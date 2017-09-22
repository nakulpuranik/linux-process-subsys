/**
* Source code opening specified file.
*/
#include "header.h"
int main(int argc, char *argv[]){

	int status;
	pid_t pid;
	int processHeirarchy;
	char buff[256];

	processHeirarchy = atoi(argv[1]);

	if((processHeirarchy>0) && (processHeirarchy<=3)){
		if(vfork()==0){
			execl("./FinalExe",buff,NULL);
			//child process
			if(processHeirarchy==1){
				//terminate this child
				_exit(7);
			}
			printf("Creating process number %d\n",processHeirarchy);
			sprintf(buff,"%s%d","",--processHeirarchy);
			
		}
		else{
			//parrent process
			printf("Inside the parrent proceess. Number %d \n",processHeirarchy);
			//pid = wait(&status);

			//printf("child process of pid %d terminates with exit status %d\n", pid,status);
		}
	}
	return 0;
}