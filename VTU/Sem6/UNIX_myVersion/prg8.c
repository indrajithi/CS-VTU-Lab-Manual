#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	pid_t pid, child_pid, grandchild_pid;

	if((pid = fork()) < 0 )
		perror("fork");

	else if(pid == 0) //first child
	{ 
			if((pid = fork()) < 0) //grand child
				perror("fork from child");
			else if(pid > 0)
				exit(0); //child exits
			  //grand child
			else if(pid == 0){
				sleep(2);
				printf("the grand child, parent pid = %d\n",getppid()); // pp1d 1 is for init
				exit(0);
			}


		}

	if(waitpid(pid,NULL,0) != pid)
		perror("waitpid");
	system("ps t");
	sleep(3);

	exit(0);
}