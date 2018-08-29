#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){

    int n;
    float f;
    double d;

    n = INT_MAX;
    f = FLT_MAX;
    d = DBL_MAX;

    printf("integer: %i, %lu bytes\n", n, sizeof(n));
    printf("float: %f, %lu bytes\n", f, sizeof(f));
    printf("double: %f, %lu bytes\n", d, sizeof(d));

    return 0;
}
