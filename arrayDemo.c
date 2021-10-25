#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 30

void main()
{
    int data[MAX_LEN];
    int i;
    int sum = 0;
    int max, min;

    // srand((unsigned int)time(NULL));

    for (i = 0; i < MAX_LEN; i++)
    {
        data[i] = rand() % 50 - 20;
    }

    for (i = 0; i < MAX_LEN; i++)
    {
        printf("%d\t", data[i]);
    }
    printf("\n");

    for (i = 0; i < MAX_LEN; i++)
    {
        sum += data[i];
    }
    printf("Average T is %.2g\n", (float)sum / MAX_LEN);

    for (min = max = data[0], i = 1; i < MAX_LEN; i++)
    {
        if (data[i] < min)
        {
            min = data[i];
        }
        if (data[i] > max)
        {
            max = data[i];
        }
    }
    printf("Min T is %d\tMax T is %d\n", min, max);
}