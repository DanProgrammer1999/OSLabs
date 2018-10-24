#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int has(int *arr, int size, int e)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == e)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int inode_numbers[10];
    char *file_names[10];
    int to_output[10];

    DIR *dirp = opendir("tmp");
    struct dirent *pf;
    int i = 0;
    int count = 0;
    while ((pf = readdir(dirp)) != NULL)
    {
        int index = has(inode_numbers, i, pf->d_ino);
        if (index >= 0)
        {
            if (has(to_output, count, index) < 0)
            {
                to_output[count] = index;
                count++;
            }
            to_output[count] = i;
            count++;
        }

        file_names[i] = pf->d_name;
        inode_numbers[i] = pf->d_ino;
        i++;
    }

    closedir(dirp);

    for (int j = 0; j < count; j++)
    {
        printf("%s\n", file_names[to_output[j]]);
    }
}