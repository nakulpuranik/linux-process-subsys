#include "header.h"

int openDemoFile(char *path);
void readDirAndWrite(char *path);

int main(int argc, char *argv[]){
	
	printf("%s\n", argv[1]);
	readDirAndWrite(argv[1]);
	return 0;
}

int openDemoFile(char *path){
	int fileDesc;

	fileDesc = open(path,O_CREAT|O_WRONLY,0777);
	if(fileDesc == -1){
		perror("PERROR::open failed");
	}
	printf("Created the new file  at path %s with fd %d\n",path,fileDesc);
	return fileDesc;
}

void readDirAndWrite(char *path){

	DIR *dir;
	struct dirent *entry;
	int fileDescDemo;
	char buffer[512];
	struct stat fileInfo;
	int ret;

	if ((dir = opendir(path)) == NULL)
	{
		printf("Unable to open specified directory\n");
		exit(-1);
	}

	//create the new demo file
	fileDescDemo = openDemoFile("./demo");

	// Traverse directory
	while ((entry = readdir(dir)) != NULL)
	{
		sprintf(buffer,"%s/%s",path,(char*)entry->d_name);
		stat(buffer,&fileInfo);
		if(S_ISREG(fileInfo.st_mode)){
			sprintf(buffer,"%s%s",((char*)entry->d_name),"\n");
			ret = write(fileDescDemo,buffer,strlen(buffer));
			if(ret < 0){
				perror("Error in writing file.");
				break;
			}
			else{
				printf("File name : \t%s\n",(char*)entry->d_name);
			}
		}
	}

	closedir(dir);
}