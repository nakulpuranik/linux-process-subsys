#include "header.h"

int main(int argc, char *argv[]){

	int status;
	pid_t pid;

	if(vfork()==0){
		//child
		execl("./proc3","NULL",NULL);
	}
	else{
		//parent
		pid = wait(&status);
		printf("Inside proc 2 with pid %d\n",pid);
	}
	return 0;
}