#include <stdio.h>

void drawDefault(int height){
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

void drawInverse(int height){
	for(int i = 0; i < height - 2; i++){
		int ast = height - i - 1;
		for(int j = 0; j < ast - 1; j++){
			printf("*");
		}

		int spaces = (i + 1)*2 - 1;
		for(int j = 0; j < spaces; j++){
			printf(" ");
		}

		ast = height - i - 1;
		for(int j = 0; j < ast - 1; j++){
			printf("*");
		}
		printf("\n");
	}

	for(int i = 0; i < (height - 2)*2 + 1; i++){
		printf("*");
	}

	printf("\n");
}

void drawSquare(int height){
	for(int i = 0; i < height; i++){
		for(int j = 0; j < height; j++){
			printf("*");
		}
		printf("\n");
	}
}

void drawRightTriangle(int height){
	for(int i = 0; i < height; i++){
		for(int j = 0; j <= i; j++){
			printf("*");
		}
		printf("\n");
	}
}

void draw(int mode, int height){
	switch(mode){
		case 0: drawDefault(height); break;
		case 1: drawInverse(height); break;
		case 2: drawRightTriangle(height); break;
		case 3: drawSquare(height); break;
		default: printf("Mode %d is not supported.", mode);
	}
}

int main(int argc, char *argv[]){

	int height;
	int mode = 0;

	if(argc > 2){
		sscanf(argv[2], "%d", &mode);
	}

	sscanf(argv[1], "%d", &height);

	draw(mode, height);

	return 0;
}

