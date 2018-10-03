#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[256];
    scanf("%s", &input);
    int n = atoi(input);
    int *arr = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i != n - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");

    free(arr);

    return 0;
}