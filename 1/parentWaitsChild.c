/**
* Source code opening specified file.
*/
#include "header.h"
int main(int argc, char *argv[]){

	int status;
	pid_t pid;

	printf("Before fork \n");
	if(vfork()==0){
		//child process
		printf("Inside the child thread.\n");
		sleep(10);
		printf("Child sleep over.\n");
		_exit(7);
	}
	else{
		//parrent process
		printf("Inside the parrent proceess.\n");
		pid = wait(&status);

		printf("child process of pid %d terminates with exit status %d\n", pid,status);
		printf("parrent process completed\n");
		exit(0);
	}
	return 0;
}