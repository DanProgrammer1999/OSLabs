#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

static int pipefd[2];

int main()
{
    pipe(pipefd);
    char input[] = "Pipe test";
    int input_size = sizeof(input);

    printf("Input: %s\n", input);
    write(pipefd[1], input, input_size);
    char result[input_size];
    read(pipefd[0], result, input_size);
    printf("Output: %s\n", result);
}