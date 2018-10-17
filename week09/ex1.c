#include <stdio.h>
#include <stdlib.h>

#define FRAMES_COUNT 50
#define MAX_AGE 8

int binary_to_decimal(char binary_str[])
{
    int res = 0;
    for (int i = 0; i < MAX_AGE; i++)
    {
        if (binary_str[i] == '1')
        {
            res += (1 << (MAX_AGE - i - 1));
        }
    }

    return res;
}

int find_page(int page_number, int pages[])
{
    for (int i = 0; i < FRAMES_COUNT; i++)
    {
        if (pages[i] == page_number)
        {
            return i;
        }
    }

    return -1;
}

int find_least_frequent_page(char *ages[])
{
    int min_freq = binary_to_decimal(ages[0]);
    int index = 0;

    for (int i = 1; i < FRAMES_COUNT; i++)
    {
        int curr_freq = binary_to_decimal(ages[i]);
        if (curr_freq <= min_freq)
        {
            min_freq = curr_freq;
            index = i;
        }
    }
    return index;
}

void insert(int page_num, int pages[], char *ages[])
{
    int least_freq_index = find_least_frequent_page(ages);
    pages[least_freq_index] = page_num;
    ages[least_freq_index][0] = '1';
    for (int i = 1; i < MAX_AGE; i++)
    {
        ages[least_freq_index][i] = '0';
    }
}

void *srl(char num[])
{
    for (int i = MAX_AGE - 1; i > 0; i--)
    {
        num[i] = num[i - 1];
    }

    num[0] = '0';
}

int main()
{
    long hits = 0;
    long misses = 0;
    int pages[FRAMES_COUNT];
    char *ages[FRAMES_COUNT];

    for (int i = 0; i < FRAMES_COUNT; i++)
    {
        pages[i] = 0;
        ages[i] = malloc(sizeof(char) * MAX_AGE);
        for (int j = 0; j < MAX_AGE; j++)
        {
            ages[i][j] = '0';
        }
    }

    FILE *input_file = fopen("Lab 09 input.txt", "r");

    while (1)
    {
        int input;
        fscanf(input_file, "%d", &input);
        if (feof(input_file))
        {
            break;
        }


        int p_index = find_page(input, pages);

        if (p_index == -1)
        {
            misses++;
            for (int i = 0; i < FRAMES_COUNT; i++)
            {
                srl(ages[i]);
            }
            insert(input, pages, ages);
        }
        else
        {
            hits++;
            for (int i = 0; i < FRAMES_COUNT; i++)
            {
                srl(ages[i]);
                if (i == p_index)
                {
                    ages[i][0] = '1';
                }
            }
        }    
    }

    fclose(input_file);

    printf("Hit/miss rate is %f%%\n", 100.0 * hits / misses);
    printf("%li hits, %li misses\n", hits, misses);

    return 0;
}