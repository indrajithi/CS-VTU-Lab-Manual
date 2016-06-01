#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const * argv[] )
{
	if(argc<3 || argc >4){
		printf("invalid number of arguments: %d\n", argc);
		exit(0);
	}

	if ((argc == 4) && !strcmp(argv[1],"-s"))
	{
		if(symlink(argv[2], argv[3]) == -1)
			perror("symlink");
		else
			printf("symbolic link created\n");
	}

	else
	{
		if(link(argv[1],argv[2]) == -1)
			perror("link");
		else 
			printf("hardlink created\n");
	}

}