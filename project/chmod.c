#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){
	int per =0;
	printf("This is Cha project\n");
	sscanf(argv[2],"%o",&per);
	mode_t mode = per;
	if(chmod(argv[1], mode) == -1){
		printf("permission change fail\n");
	}

	return 0;
}
