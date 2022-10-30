#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <fcntl.h>

#define MAX_COMMAND_SIZE 255
#define TRUE 1
#define FALSE 0

void removeFirst(char *buf){
	int i=0;
	for(i=1; buf[i]; i++){
		buf[i - 1] = buf[i];
	}

	buf[i - 1] = '\0';
}

int main(){
	char inCommand[MAX_COMMAND_SIZE];
	char historyBuf[MAX_COMMAND_SIZE];
	char aliasBuf[MAX_COMMAND_SIZE];

	char checkAli[6] = "alias ";
	int inAli = TRUE;
	int isAli = TRUE;
	int afterCommand = FALSE;
	char saveAli[MAX_COMMAND_SIZE];
	int charAli = 0;
	int size = 0;
	int comNum = 0;

	char *path;
	int fd, hisNum = 0, hisUse = 0;
	pid_t pid;
	FILE* hisFp;
	FILE* aliFp;
	char *argv[10] = {"", "", "", "", "", "", "", "", "", ""};

	
	aliFp = fopen("cha_alias","w+");	
	fclose(aliFp);

	while(1){
		printf("Cha Shell: ");
		if(fgets(inCommand,MAX_COMMAND_SIZE,stdin) == NULL){
			printf("fgets error");
		}
		if(strlen(inCommand) >= MAX_COMMAND_SIZE - 1){
			printf("input overSize\n");
			while(getchar() != '\n');
			continue;
		}

		isAli = TRUE;
		inAli = TRUE;
		afterCommand = FALSE;
		comNum = 0;
		
		if(strcmp(inCommand, "alias\n") == 0){
			aliFp = fopen("cha_alias","r");
			while(fgets(aliasBuf, MAX_COMMAND_SIZE, aliFp) != NULL){
				printf("alias %s",aliasBuf);
			}
			fclose(aliFp);
			continue;
		}
		
		


		aliFp = fopen("cha_alias","r");
		while(fgets(aliasBuf, MAX_COMMAND_SIZE, aliFp) != NULL){
			for(int e=0;e<strlen(inCommand) - 1;e++){
				if(aliasBuf[e] != inCommand[e]){
					inAli = FALSE;
					break;
				}
			}
			
			if(inAli == TRUE){
				for(int f=0;f<strlen(aliasBuf) - 2;f++){
					if(afterCommand == TRUE){
						inCommand[comNum] = aliasBuf[f + 1];
						comNum++;
					}
					if(afterCommand == FALSE && aliasBuf[f] == '='){
						afterCommand = TRUE;
					}
				}

				inCommand[strlen(inCommand) - 1] = '\n';
				inCommand[strlen(inCommand)] = 0;
				printf("%s\n",inCommand);
			}
			inAli = TRUE;
		}
			
		fclose(aliFp);

		if(inCommand[0] == '!'){
			inCommand[strlen(inCommand) - 1] = 0;
			removeFirst(inCommand);
			hisUse = atoi(inCommand);
			hisFp = fopen("cha_history","r");

			if(hisFp == NULL){
				printf("Can't open cha_history\n");
				continue;
			}

			while(fgets(historyBuf, MAX_COMMAND_SIZE, hisFp) != NULL){
				hisNum++;
				if(hisNum == hisUse){
					strcpy(inCommand, historyBuf);
					break;
				}
			}
			fclose(hisFp);
			hisNum = 0;
		}

		fd = open("cha_history", O_WRONLY | O_APPEND);	
		write(fd, inCommand , strlen(inCommand));
		close(fd);
		
		for(int i=0;i<6;i++){
			if(checkAli[i] != inCommand[i]){
				isAli = FALSE;
				break;
			}
		}

		if(isAli == TRUE){
			int i, j;
			for(i=6;i<MAX_COMMAND_SIZE;i++){
				if(inCommand[i] == '\'' || inCommand[i] == '\"'){
					charAli++;
				}
				else{
					saveAli[i - charAli - 6] = inCommand[i];
				}
			
				if(charAli == 2){
					break;
				}
				if(i == MAX_COMMAND_SIZE - 1){
					printf("No quotation marks.\n");
					break;
				}
			}
			
			saveAli[i - 7] = '\0';
			if(i != MAX_COMMAND_SIZE - 1){
				size = strlen(saveAli);
				saveAli[size] = '\'';
				saveAli[size + 1] = '\0';

				for(j = 0;j<strlen(saveAli);j++){
					if(saveAli[j] == '='){
						break;
					}
				}

				size = strlen(saveAli);
				for(int k = size;k>j+1;k--){
					saveAli[k] = saveAli[k - 1];
				}
				saveAli[j + 1] = '\'';
				saveAli[size + 1] = '\0';
				strcat(saveAli,"\n");

				fd = open("cha_alias", O_WRONLY | O_APPEND);	
				write(fd, saveAli , strlen(saveAli));
				close(fd);

				charAli = 0;
				size = 0;
				memset(saveAli,0,sizeof(char) * MAX_COMMAND_SIZE);
				continue;
			}
		}

		inCommand[strlen(inCommand) - 1] = 0;
		
		if(strcmp(inCommand, "exit") == 0){
			break;
		}
		else if(strcmp(inCommand, "history") == 0){
			hisFp = fopen("cha_history","r");

			if(hisFp == NULL){
				printf("Can't open cha_history\n");
				continue;
			}

			while(fgets(historyBuf, MAX_COMMAND_SIZE, hisFp) != NULL){
				hisNum++;
				printf(" %d  %s",hisNum, historyBuf);
			}
			fclose(hisFp);
			hisNum = 0;
			continue;
		}
		else if(strcmp(inCommand, "help") == 0){
			printf("available commands : ");
			continue;
		}

		pid = fork();
		if(pid < 0){
			printf("Fork Failed");
			break;
		}
		else if(pid == 0){ //child process
			path = strtok(inCommand," ");
			argv[0] = path;
			for(int i=1;i<10;i++){
				argv[i] = strtok(NULL," ");
			}

			if(execv(path,argv) == -1){//HELP cp error
				printf("%s: command not found\n",inCommand);
			}
			break;
		}
		else{ //parent process
			wait(NULL);
			printf("Child Complete\n");
		}	
	}
}
