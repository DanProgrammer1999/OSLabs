#include <stdio.h>

void swap(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}

int main(){

	int a;
	int b;

	printf("Enter the first integer:  ");
	scanf("%d", &a);

	printf("Enter the second integer:  ");
	scanf("%d", &b);

	swap(&a, &b);

	printf("%d, %d\n", a, b);
}
