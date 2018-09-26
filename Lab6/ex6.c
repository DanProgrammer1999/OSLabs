#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int pipefd[2];
    pipe(pipefd);
    pid_t child1_id = fork();
    if (child1_id != 0)
    {
        pid_t child2_id = fork();
        if (child2_id)
        {
            //Parent process
            close(pipefd[0]);

            pid_t process_id = getpid();

            printf("Parent(%d): sending child 2 id (%d) through the pipe.\n", process_id, child2_id);
            write(pipefd[1], &child2_id, sizeof(child2_id));

            close(pipefd[1]);

            printf("Parent(%d): waiting for child 2(%d) change of state.\n", process_id, child2_id);

            //The description given in the lab text is not completely true: with not options specified, 
            //it waits until the termination of the process. However, specifying an option WUNTRACED, 
            //we shall get the behavior we need.
            waitpid(child2_id, NULL, WUNTRACED);

            printf("Parent(%d): child 2(%d) changed its state.\n", process_id, child2_id);
            kill(child2_id, SIGINT);
            printf("The second child is dead.\n");
            printf("Leaving parent\n");
            exit(0);
        }
        else
        {
            //Child 2 process
            close(pipefd[0]);
            close(pipefd[1]);

            pid_t process_id = getpid();
            printf("Child 2(%d): waiting for a signal.\n", process_id);
            while (1);
            printf("Leaving child 2\n");
            exit(0);
        }
    }
    else
    {
        //Child 1 process
        close(pipefd[1]);
        pid_t process_id = getpid();
        pid_t child2_id;
        read(pipefd[0], &child2_id, sizeof(child2_id));
        close(pipefd[0]);
        printf("Child 1(%d): receiving through the pipe: %d\n", process_id, child2_id);
        sleep(2);
        printf("Child 1(%d): sending SIGSTOP signal to child 2(%d).\n", process_id, child2_id);
        kill(child2_id, SIGSTOP);
        printf("Leaving child 1\n");
        exit(0);
    }
    return 0;
}