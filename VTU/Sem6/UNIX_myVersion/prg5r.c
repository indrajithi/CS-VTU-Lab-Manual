#include <stdio.h>
#include <unistd.h>
//#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char * argv[])
{
	int fd, i, j;

	char buf[256];

	fd = open(argv[1],O_RDONLY);

	if((i = read(fd,buf,sizeof(buf))) < 0)
		perror("read");
	else
	{
		for(j=0; j<i; j++)
			printf("%c",buf[j]);
		printf("\n");
	}
	unlink(argv[1]);

}