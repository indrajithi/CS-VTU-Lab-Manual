#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include <unistd.h>
#include <iostream>
using namespace std;

int main()
{
	#ifdef _POSIX_JOB_CONTROL
		cout<<"system support posix job control\n";
	#else
		cout<<"system doesnot support posic job control\n";
	#endif

	#ifdef _POSIX_SAVED_IDS
		cout<<"system supports set uid and set gid \n";
	#else
		cout<<"doesnot support set uid and git";
	#endif

	#ifdef _POSIX_CHOWN_RESTRICT
		cout<<"chown restrict oprtion is : "<<_POSIX_CHOWN_RESTRICT<<endl;
	#else
		cout<<"system doesnot support chown restrict\n";
	#endif

	#ifdef _POSIX_NO_TRUNC
		cout<<"path trunc option is: "<<_POSIX_NO_TRUNC<<endl;
	#else
		cout<<"doesnot support no trunc\n";
	#endif 

	#ifdef _POSIX_VDISABLE
		cout<<"posix vdisable is "<<_POSIX_VDISABLE<<endl;
	#else 
		cout<<"doesnot support vdssable\n"
	#endif
}