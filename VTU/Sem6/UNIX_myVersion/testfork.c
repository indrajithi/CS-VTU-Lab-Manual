#include <unistd.h>
#include <stdio.h>

int tst()
{
	pid_t pid;

	pid = fork();

	if(pid == 0)
		printf("heloo..\n");
	else{
		sleep(1);
		printf("nope\n");
	}
}
int main()
{
	tst();
}