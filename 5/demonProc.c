#include "header.h"

static void createDaemon(){
	pid_t pid;

	pid = fork();		//fork from parent

	if(pid < 0){
		perror("fork error");
		exit(-1);
	}

	if(pid > 0){
		exit(0);		//terminate parent
	}

						//on success child process becomes session leader.
	if(setsid() < 0){
		exit(-1);
	}

	//handle the signals and ignore
	signal(SIGCHLD, SIG_IGN);
	signal(SIGHUP, SIG_IGN);

	//fork for the second time
	pid = fork();		//fork from parent

	if(pid < 0){
		perror("fork error");
		exit(-1);
	}

	if(pid > 0){
		exit(0);		//terminate parent
	}

	umask(0);			//set new file permissions.

	chdir("/");			//change the working directory to the root directory.

						//close all open file descriptor.
    int openFd;
    for (openFd = sysconf(_SC_OPEN_MAX); openFd>=0; openFd--)
    {
        close (openFd);
    }


}

int openTestFile(char *path);

int main(int argc, char *argv[]){
	
	int fd;
	int input;
	int finalIncrement = 0;
	char buffer[256];

	validateNumberOfArguement(&argc);

	createDaemon();

	fd = openTestFile(argv[1]);
	input = 0;
	while(1){

		finalIncrement = atoi(buffer);
		finalIncrement++;
		input = finalIncrement;
		sprintf(buffer," %s%d ","",input);
		
		printf("writing %s to file\n", buffer);
		write(fd,buffer,(strlen(buffer)));
		if(strcmp(" 10 ",buffer) == 0){
			break;
		}
		sleep(1);
	}
	printf("Exiting from the process\n");
	close(fd);
	
	return 0;
}

int openTestFile(char *path){
	int fileDesc;

	fileDesc = open(path,O_WRONLY | O_TRUNC);
	if(fileDesc == -1){
		perror("PERROR::open failed");
	}
	printf("File from path %s opened successfully.\n",path);
	return fileDesc;
}

void validateNumberOfArguement(const int *input){
	if(*input != 2)
	{
		printf("Error : Not sufficient arguments\nPassed arguments %d\n",*input);
		exit(-1);
	}
}