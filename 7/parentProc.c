#include "header.h"

int main(int argc, char *argv[]){
	pid_t pid;
	int status,status2;
	if(fork()==0){
		execv("./proc1",(char *[]){"parentProc","./demo","./count"});
	}
	else{
		//parent process
		pid = wait(&status);
	}

	if(fork()==0){	
		execv("./proc1",(char *[]){"parentProc","./hello","./count"});
	}
	else{
		pid = wait(&status2);
	}

}