#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	printf("parent process id = %d \n",getpid());

	if((pid=fork()) < 0)
		perror("fork error\n");

	else if (pid == 0){
		printf("child process id = %d\n",getpid());
		exit(0);
	}
	sleep(2);
	system("ps -o pid,ppid,state,tty,command");
	exit(0);
}