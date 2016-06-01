#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void tokenize(char *,char ** , int);
void generate(char**, const int);

int main()
{
	int i,j,ch;
	char *token[5] = {'\0'};

	char str1[] = "if(count<10)then(s=a);";
	char str2[] = "if(count<20)then(s=a)else(s=b);";

	printf("Choose input string\n1.%s\n2.%s\n",str1,str2);
	scanf("%d",&ch);

	switch(ch)
	{
		case 1: tokenize(str1,token,4);
				for(i=0; i<4; i++)
					printf("\ntoken[%d] : %s\n",i,token[i]);
				generate(token,1);
				break;

		case 2: tokenize(str2,token,6);
				for(i=0; i<6; i++)
					printf("\ntoken[%d] : %s\n",i,token[i]);
				generate(token,2);
				break;

	}

}

void tokenize(char *str, char **token, int n)
{
	int i;
	printf("\nTOKENIZING THE INPUT\n");
	token[0] = strtok(str,"(");
	for(i = 1; i<n; i++)
		token[i] = strtok(NULL,";()");

}

void generate(char **token, const int ch)
{
	int label1 = 100, label2 = 101;
	printf("GENERATING LABELS\n");
	switch(ch)
	{
		case 1 : printf("\n%d : %s\n IF %s GOTO %d\n",label1,token[3],token[1],label1);
				 break;

		case 2 : printf("\n%d : %s \n%d : %s\n",label1,token[3],label2,token[5]);
				 printf("IF %s GOTO %d ELSE GOT %d\n",token[1],label1,label2);
				 break;
	}
}
