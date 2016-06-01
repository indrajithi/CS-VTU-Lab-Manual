#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <string.h>

int main(int argc, char const * argv[])
{
	int fd;
	char buf[256],kst[12];
	struct flock fvar;

	if((fd=open(argv[1],O_RDWR)) == -1){
		perror("open");
		return -1;
	}

	fvar.l_type   = F_WRLCK;				// type of lock
	fvar.l_whence = SEEK_END;				// relative to the end of the file
	fvar.l_start  = SEEK_END - 100;			// where to start
	fvar.l_len	  = 100;					// total bytes to consider
	
	printf("press enter to set lock.\n");
	getchar();
	printf("trying to lock..\n");

	if((fcntl(fd,F_SETLK,&fvar)) == -1)
	{
		
		fcntl(fd,F_GETLK,&fvar);
		printf("selected region is already locked by process (pid): %d\n",fvar.l_pid);
		printf("do you want to kill the process? Y/N\n");
		scanf("%s",kst);
		if(!strcmp(kst, "Y") || !strcmp(kst, "y")){
			kill(fvar.l_pid,SIGTERM);
			printf("process killed..\n");
		}
		else
			return -1;
	}

	else 
		printf("Locked..\n");

	//seek
	printf("press enter to read 50 bytes\n");
	getchar();

	if((lseek(fd,SEEK_END - 50, SEEK_END)) == -1)
		perror("seek");

	if((read(fd,buf,100) == -1))
		perror("read");

	//print 50 bytes

	puts(buf);

	//unlock
	printf("press enter to relese lock\n");
	getchar();

	fvar.l_type   = F_UNLCK;
	fvar.l_whence = SEEK_SET;
	fvar.l_start  = 0;
	fvar.l_len 	  = 0;

	if((fcntl(fd,F_UNLCK,&fvar) == -1))
		perror("fcntl");

	printf("unlocked\n");
	close(fd);

}