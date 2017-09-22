#include "header.h"

int main(int argc, char *argv[]){

	int status1,stats2;
	pid_t pid;

	
	printf("Parent process starts\n");

	if(fork()==0){
		//child
		execl("./proc2","NULL",NULL);
	}
	else{
		pid = wait(&status1);
	}
	if(fork()==0){
		//child
		execl("./proc3","NULL",NULL);
	}
	else{
		pid = wait(&status1);
	}

	printf("Parent process ends\n");
	
	return 0;
}