#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define FILEBUF 255

int main(int argc, char *argv[]){
	FILE *fp;
	char buf[FILEBUF];
	char *filename = NULL;
	char *result;
	int i=1;

	printf("This is Cha Project\n");
	
	while(argv[i] != NULL){
		filename = argv[i];
		fp = fopen(filename,"r");

		if(fp == NULL){
			printf("can't open %s\n",filename);
			i++;
			continue;
		}


		while(fgets(buf, FILEBUF, fp) != NULL){
			if(strlen(buf) >= FILEBUF - 1){
				printf("size over\n");
				break;
			}
			else{
				printf("%s",buf);
			}
		}
		i++;
		fclose(fp);
	}
}
