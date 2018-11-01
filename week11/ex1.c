#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define ll long long

int main()
{
    char *text = "This is a nice day";

    int file_fd = open("ex1.txt", O_RDWR);

    int size = strlen(text);
    char *file = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, file_fd, 0);

    ftruncate(file_fd, size);

    for (int i = 0; i < size; i++)
    {
        file[i] = text[i];
    }

    munmap(file, size);

    return 0;
}