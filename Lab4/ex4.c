#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

#define $PROMPT "$user> "

char *read_command()
{
    char *result = malloc(255);
    fgets(result, 255, stdin);
    return result;
}

int main()
{
    while (1)
    {
        printf($PROMPT);
        char *command = read_command();
        if (strncmp("exit", command, 4) == 0)
        {
            break;
        }

        if(command[strlen(command) - 2] == '&'){
            int process_id;
            command[strlen(command) - 3] = '\0';

            int pid;
            if(fork == 0){
                system(command);
                pid = getpid();
            }
            else{
                printf("Task id: %d\n", pid);
            }
        }
        else{
            system(command);
        }
    }
    return 0;
}