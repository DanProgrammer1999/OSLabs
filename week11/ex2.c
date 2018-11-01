#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char s[] = "Hello";

    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c", s[i]);
        sleep(1);
    }

    printf("\n");
    return 0;
}