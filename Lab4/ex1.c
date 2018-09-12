#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 

int main(){
    int n = 0;
    int f = fork();
    int pid = (int)getpid();

    if(f == 0){
        printf("Hello from child %d - %d\n", pid, n);
    } else{
        printf("Hello from parent %d - %d\n", pid, n);
    }    

    return 0;
}