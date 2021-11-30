#include <unistd.h>
#include <stdio.h>

#define MAX_BUFF_SIZE 1024

int main(void){
	char buff[MAX_BUFF_SIZE];
	getcwd(buff,MAX_BUFF_SIZE);
	printf("This is Cha Project\n");

	if(buff == NULL){
		printf("error\n");
	}
	else{
		printf("Current Directory : %s\n", buff);
	}
	return 0;
}
