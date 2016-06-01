#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

//#define INTERVEL 5

void callme(int sig)
{
	printf("\balarm api\n");

//	alarm(2);
	sleep(2);

}

int main()
{
	signal(SIGALRM,callme);
	alarm(2);
	sleep(3);
	printf("All done\n");
}


