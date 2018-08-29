#include <stdio.h>

int main(int argc, char *argv[]){
	
	int height;

	sscanf(argv[1], "%d", &height);

	for(int i = 0; i < height; i++){
		int spaces = height - i - 1;
		for(int j = 0; j < spaces; j++){
			printf(" ");
		}
		int ast = (i + 1)*2 - 1;

		for(int j = 0; j < ast; j++){
			printf("*");
		}

		printf("\n");
	}
}
