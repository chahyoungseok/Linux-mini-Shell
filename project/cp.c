#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CONTENT_SIZE 255

int main(int argc,char* argv[]){
	int cpedfd = 0;
	char contentBuf[MAX_CONTENT_SIZE];
	FILE *fp;

	printf("This is Cha project\n");
	fp = fopen(argv[1], "r");

	if(fp == NULL){
		printf("Can't open %s\n",argv[1]);
		exit(1);
	}

	cpedfd = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC | O_SYNC, 0644);
	
	while(fgets(contentBuf, MAX_CONTENT_SIZE, fp) != NULL){
		write(cpedfd, contentBuf, strlen(contentBuf));
	}

	close(cpedfd);
}
