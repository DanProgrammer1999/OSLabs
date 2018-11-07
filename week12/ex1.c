#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *rnd = fopen("/dev/random", "r");
    char result[21];
    result[21] = '0'; // Add null terminator
    for (int i = 0; i < 20; i++)
    {
        result[i] = fgetc(rnd);
    }

    return 0;
}