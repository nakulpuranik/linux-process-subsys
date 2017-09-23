#include "header.h"


int openFile(char *path);

int main(int argc, char *argv[]){
	int fileDesc,fd;
	int ret;
	int capCount = 0;
	char buff[1];
	char *lBuff;

	fileDesc = open(argv[1],O_RDONLY);
	if(ret == -1){
		perror("openSysCall::\n");
		return -1;
	}

	//read the actual information form the file 

	while(( read(fileDesc,buff,1)) != 0){
		if('A' >=(buff[0]) && (buff[0]) <= 'Z'){
			capCount++;
		}
	}
	fd = openFile(argv[2]);

	lBuff = (char*)malloc(capCount*sizeof(long));
	sprintf(lBuff,"Count by %s is =%d\n",argv[1],capCount);
	printf("%s",lBuff);
	write(fd,lBuff,strlen(lBuff));

	printf("\n");
	close(fileDesc);
	close(fd);
	free(lBuff);
	return 0;
}

int openFile(char *path){
	int fileDesc;

	fileDesc = open(path,O_RDWR | O_APPEND);
	if(fileDesc == -1){
		perror("PERROR::open failed");
	}
	return fileDesc;
}