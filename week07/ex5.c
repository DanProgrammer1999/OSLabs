#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **s;
    s = malloc(sizeof(char *));
    char foo[] = "Hello World";
    *s = foo;

    /* 
    printf("s is %s\n", s);
        
    // We could leave it like this, and it would not cause a segmentation fault.
    // However, in that case s is a pointer and it outputs garbage
    // Let's fix it too.
    */

    printf("s is %s\n", *s);
    s[0] = foo;
    printf("s[0] is %s\n", s[0]);
    return (0);
}