#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 10

void main()
{
    int data[MAX_LEN];
    int i;

    // for (i = 0; i < MAX_LEN; i++)
    // {
    //     printf("A[%d]=", i + 1);
    //     scanf("%d", &data[i]);
    // }

    srand((unsigned int)time(NULL));

    for (i = 0; i < MAX_LEN; i++)
    {
        data[i] = rand() % 100;
    }

    for (i = 0; i < MAX_LEN; i++)
    {
        printf("%d\t", data[i]);
    }
    printf("\n");

    for (i = MAX_LEN - 1; i >= 0; i--)
    {
        printf("%d\t", data[i]);
    }
    printf("\n");
}