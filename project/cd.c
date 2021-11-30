#include <unistd.h>
#include <stdio.h>

#define MAX_BUFF_SIZE 255
int main(int argc, char *argv[]){
	char BUFF[MAX_BUFF_SIZE];

	printf("This is Cha Project\n");
	
	if(chdir(argv[1]) == -1){
		printf("The file does not exist in the current diretory\n");
	}
	else{
		printf("chdir success\n");
		getcwd(BUFF,MAX_BUFF_SIZE);
		printf("%s\n",BUFF);
	}
}
