#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	if(argc != 3){
		printf("Usage:%s <path><newpath>\n",argv[0]);
	}
	if(symlink(argv[1],argv[2]) < 0){
		printf("symlink error\n");
	}
	printf("This is Cha project\n");
}
