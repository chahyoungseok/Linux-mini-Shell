#include<stdio.h>
#include<unistd.h>

#define MAX_CONTENT_SIZE 255

int main(int argc, char* argv[]){
	int result = 0;
	printf("This is Cha project\n");

	result = remove(argv[1]);
	if(result == 0){
		printf("Remove File Success\n");
	}
	else{	
		result = rmdir(argv[1]);

		if(result == 0){
			printf("Remove Success\n");
		}
		else if(result == -1){
			printf("error : There are files inside the folder.\n");
		}
	}



	return 0;
}
