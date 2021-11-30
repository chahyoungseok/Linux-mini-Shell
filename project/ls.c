#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<stdlib.h>

#define MAX_DIR_NAME 1024

int main(){
	char dirName[MAX_DIR_NAME];
	DIR *dir = NULL;
	struct dirent* direntry = NULL;

	getcwd(dirName, MAX_DIR_NAME);
	
	if((dir = opendir(dirName)) == NULL){
		printf("This directory error\n");
		exit(1);
	}

	printf("This is Cha Project\n");

	while((direntry = readdir(dir)) != NULL){
		printf("%s\n",direntry->d_name);
	}
	printf("\n");

	closedir(dir);
	return 0;
}
