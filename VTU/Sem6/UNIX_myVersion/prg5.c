#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
	int fd;
	
	if(mkfifo(argv[1],S_IFIFO|S_IRWXU) == -1)
		perror("mkfifo");
	else
	{
		fd = open(argv[1],O_WRONLY);
		if(fd == -1)
			perror("open");
		
		else
			if(write(fd,argv[2],strlen(argv[2])) > 0)
				printf("written succesfully\n");
			else 
				perror("write");
			return 0;
	}

}
