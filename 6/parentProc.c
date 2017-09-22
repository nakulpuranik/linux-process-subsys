#include "header.h"

int main(int argc, char *argv[]){
	pid_t pid;
	int status;
	if(fork()==0){
		execv("./procReadAndList",(char *[]){"parentProc","/home/nakul/Desktop"});
	}
	else{
		//parent process
		pid = wait(&status);
	}

}