#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void outputArray(const int array[], int length){
    printf("[");
    for(int i = 0; i < length; i++){
        printf("%d", *(array + i));
        if(i != length - 1){
            printf(", ");
        }
    }
    printf("]\n");
}

int partition(int array[], int start, int end){
    int pivotPos = end;

    int i = start, j = end - 1;

    while(i <= j){
        while(i < end && array[i] <= array[pivotPos]){
            i++;
        }

        while(j >= start && array[j] >= array[pivotPos]){
            j--;
        }

        if(i < j){
            swap(&array[i], &array[j]);

//            printf("i: %d, j: %d\n", i, j);
//            outputArray(array, 7);
//            printf("\n");
        }
    }
    if(i != pivotPos) {
        swap(&array[i], &array[pivotPos]);

//        printf("i: %d, pivotPos: %d\n", i, pivotPos);
//        outputArray(array, 7);
//        printf("\n");
    }
    return i;
}

void quicksortRec(int array[], int start, int end){
    int pivotPos = partition(array, start, end);
    if(start < pivotPos){
        quicksortRec(array, start, pivotPos - 1);
    }
    if(end > pivotPos){
        quicksortRec(array, pivotPos + 1, end);
    }

}

void quicksort(int array[], int length){
    quicksortRec(array, 0, length - 1);
}

int main(){

    //The array now points to random values in memory.
    int test[20];
    int length = 20;

    //Put all the values in a smaller range to make the result more readable.
    for(int i = 0; i < length; i++){
        test[i] = test[i]%(length*3);
    }

    printf("Input: ");
    outputArray(test, length);

    quicksort(test, length);

    printf("\nResult: ");
    outputArray(test, length);
}




