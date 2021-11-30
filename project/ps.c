#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>

#define MAX_CONTENT_SIZE 255 

void noNumberOut(char* buf){
	int i=0;
	while(48 <= buf[i] && buf[i] <= 57){
		i++;
	}
	buf[i + 1] = '\0';
}

void removeChar(char *buf, int start){
	int i=0;
	for(i=start; buf[i]; i++){
		buf[i - start] = buf[i];
	}

	buf[i - start] = '\0';
}

int main(){
	DIR *dir = NULL;
	FILE* file = NULL;
	struct dirent *direntry = NULL;
	int myID = getuid();
	char userID[MAX_CONTENT_SIZE];
	int lineNum = 0;
	char contentBuf[MAX_CONTENT_SIZE];
	char uidBuf[MAX_CONTENT_SIZE];
	char ppidBuf[MAX_CONTENT_SIZE];
	char pidBuf[MAX_CONTENT_SIZE];
	char nameBuf[MAX_CONTENT_SIZE];
	
	char filename[MAX_CONTENT_SIZE] = "/proc/";

	printf("This is Cha Project\n");	

	sprintf(userID, "%d", myID);
	if((dir = opendir("/proc")) == NULL){
		printf("opendir error\n");
		exit(1);
	}
	
	printf(" PPID   PID    UID     CMD    \n");
	
	while((direntry = readdir(dir)) != NULL){
		if(strcmp(direntry->d_name,"self") != 0 && strcmp(direntry->d_name,"thread-self") != 0){
			strcat(filename, direntry->d_name);
			strcat(filename, "/status");

			file = fopen(filename, "r");
			lineNum = 0;
			if(file != NULL){
				while(fgets(contentBuf, MAX_CONTENT_SIZE, file)){
					if(lineNum == 0){
						strcpy(nameBuf, contentBuf);
						removeChar(nameBuf, 6);
						nameBuf[strlen(nameBuf) - 1] = '\0';
					}
					else if(lineNum == 5){
						strcpy(pidBuf, contentBuf);
						removeChar(pidBuf, 5);
						pidBuf[strlen(pidBuf) - 1] = '\0';
					}
					else if(lineNum == 6){
						strcpy(ppidBuf, contentBuf);
						removeChar(ppidBuf, 6);
						ppidBuf[strlen(ppidBuf) - 1] = '\0';
					}
					else if(lineNum == 8){
						strcpy(uidBuf, contentBuf);
						removeChar(uidBuf, 5);
						noNumberOut(uidBuf);
						uidBuf[strlen(uidBuf) - 1] = '\0';

						if(strcmp(uidBuf, userID) == 0){
							printf("%5s %6s %5s %7s\n",ppidBuf, pidBuf, uidBuf, nameBuf);
						}
						else{
							break;
						}
					}
					lineNum++;
				}
				fclose(file);
				file = NULL;
			}
			strcpy(filename, "/proc/");
		}
	}
	closedir(dir);
}
