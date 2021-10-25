#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 10

void main()
{
    int data[MAX_LEN];
    int i;

    for (i = 0; i < MAX_LEN; i++)
    {
        printf("A[%d]=", i + 1);
        scanf("%d", &data[i]);
    }

    for (i = 0; i < MAX_LEN; i++)
    {
        print("%d\t", data[i]);
    }
}