#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

void swap(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}

void bubbleSort(int input[], int length){

	bool swapped;

	do{
		swapped = false;

		for(int i = 0; i < length - 1; i++){
			if(input[i] > input[i + 1]){
				swap(&input[i], &input[i + 1]);
				swapped = true;
			}
		}
	}
	while(swapped);
}

void outputArray(int array[], int length){
	printf("[");
	for(int i = 0; i < length; i++){
		printf("%d", *(array + i));
		if(!(i == length - 1)){
			printf(", ");
		}
	}
	printf("]\n");
}

int main(){	
	int a[] = {10, 9, 1, 2, 0, -4, 12, 40, 6, 4};
	int length = 10;

	printf("Input array: ");
	outputArray(a, length);

	bubbleSort(a, length);

	printf("Result:      ");
	outputArray(a, length);	
	return 0;
}