#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define size 16

int main()
{
    int from = open("ex1.txt", O_RDONLY);
    int to = open("ex1.memcpy.txt", O_RDWR);

    ftruncate(to, size);

    char *addr_from = mmap(NULL, size, PROT_READ, MAP_SHARED, from, 0);
    char *addr_to = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_SHARED, to, 0);
    
    memcpy(addr_to, addr_from, size);

    return 0;
}