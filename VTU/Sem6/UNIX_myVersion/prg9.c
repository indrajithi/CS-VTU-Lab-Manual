#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

char cmd[100];


int mysysfun(const char *cmd)
{
	pid_t pid;
	int status;

	if(cmd == NULL)
		return(1);

	if((pid = fork()) < 0)
		perror("fork");

	if(pid == 0)  //child
	{
		setbuf(stdout,NULL);
		printf("pid = %d\n",getpid());
		execl("/bin/sh","sh","-c",cmd,(char *)0);
		exit(0);
	}
	  
	waitpid(pid,&status,0);
	return status;
}


int main()
{
	int status;
	
		printf("\nEnter a command\n");
		
		scanf("%s",cmd);
		
		status = mysysfun(cmd);

}
