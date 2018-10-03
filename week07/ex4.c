#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *realloc1(void *ptr, int new_size)
{
    if (ptr == NULL)
    {
        return malloc(new_size);
    }

    if(new_size == 0){
        free(ptr);
        return ptr;
    }

    void* result = malloc(new_size);
    memcpy(result, ptr, new_size);
    free(ptr);

    return result;    
}

// For testing purposes
int main()
{
    srand(time(NULL));

    printf("Enter original array size: ");
    int n1 = 0;
    scanf("%d", &n1);

    int *a1 = malloc(sizeof(int) * n1);
    for (int i = 0; i < n1; i++)
    {
        a1[i] = i;
        printf("%d ", a1[i]);
    }

    printf("\nEnter new array size: ");
    int n2 = 0;
    scanf("%d", &n2);

    a1 = realloc(a1, sizeof(int) * n2);

    for (int i = 0; i < n2; i++)
    {
        printf("%d ", a1[i]);
    }
    printf("\n");

    return 0;
}
