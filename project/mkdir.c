#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc, char* argv[]){
	printf("This is Cha Project\n");
	if(mkdir(argv[1],0755) != 0){
		printf("mkdir error\n");
		return -1;
	}
	return 0;
}
