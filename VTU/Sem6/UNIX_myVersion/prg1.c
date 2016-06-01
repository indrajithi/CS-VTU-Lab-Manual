#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main()
{
	int res;
	if((res=sysconf(_SC_CLK_TCK)) == -1)
		perror("sysconf");
	else
		cout<<"CLK_TCK: "<<res<<endl;

	if((res=sysconf(_SC_CHILD_MAX)) == -1)
		perror("sysconf");
	else
		cout<<"CHILD MAX"<<res<<endl;

	if((res=pathconf("/",_PC_PATH_MAX)) == -1)
		perror("pathconf");
	else 
		cout<<"PATH MAX"<<res<<endl;
	
	if((res=pathconf("/",_PC_NAME_MAX)) == -1)
		perror("pathconf");
	else
		cout<<"NAME_MAX"<<res<<endl;

	if((res=sysconf(_SC_OPEN_MAX)) == -1)
		perror("sysconf");
	else
		cout<<"OPEN MAX"<<res<<endl;


}