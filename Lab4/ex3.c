#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define $PROMPT "$user>"

char* read_command(){
    char *result = malloc(255);
    fgets(result, 255, stdin);
    return result;
}

int main(){
    while(true){
        printf($PROMPT);
        char* command = read_command();
        if(strncmp("exit", command, 4) == 0){
            break;
        }
        system(command);
    }
    return 0;
}