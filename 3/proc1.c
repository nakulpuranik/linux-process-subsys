#include "header.h"

int main(int argc, char *argv[]){

	int status;
	pid_t pid;

	//process executes 3 different processes.
	if(fork()==0){
		//child
		execl("./proc2","NULL",NULL);
	}
	if(fork()==0){
		//child
		execl("./proc3","NULL",NULL);
	}
	if(fork()==0){
		//child
		execl("./proc4","NULL",NULL);
	}
	
	return 0;
}