#include <stdio.h>
#include <unistd.h>
#include <string.h>
void printstr(char *str)
{
	char *ptr;
	char c;
	int i;
	setbuf(stdout,NULL);

	//for(ptr = str; (c = *ptr++)!=0; )
	//	putc(c,stdout);

	while(*str++ != '\0')
		printf("%c",*str);
}

int main()
{
	pid_t pid;

	if((pid = fork()) < 0)
		perror("fork");
	else 
		if(pid == 0)
			printstr("child prints\n");
		else{
			printstr("parent prints\n");
	//		printf("pid here = %d",pid);
		}
}