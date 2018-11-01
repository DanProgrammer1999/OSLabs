#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int filesize(int fd)
{
    struct stat st;
    fstat(fd, &st);

    return st.st_size;
}

int main()
{
    int from = open("ex1.txt", O_RDONLY);
    int to = open("ex1.memcpy.txt", O_RDWR);

    int size = filesize(from);
    ftruncate(to, size);

    char *addr_from = mmap(NULL, size, PROT_READ, MAP_SHARED, from, 0);
    char *addr_to = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_SHARED, to, 0);

    memcpy(addr_to, addr_from, size);

    munmap(addr_from, size);
    munmap(addr_to, size);
    return 0;
}