#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

void input(float data[][MAX_SIZE], unsigned size);
void output(float data[][MAX_SIZE], unsigned size);
void randomInput(float data[][MAX_SIZE], unsigned size);
void minByRow(float data[][MAX_SIZE], float *result, unsigned int size);
void printArray(float *data, unsigned int size);

void main()
{
    float data[MAX_SIZE][MAX_SIZE];
    float min[MAX_SIZE];

    // input(data, MAX_SIZE);
    randomInput(data, MAX_SIZE);
    output(data, MAX_SIZE);
    minByRow(data, min, MAX_SIZE);
    printArray(min, MAX_SIZE);
}

void randomInput(float data[][MAX_SIZE], unsigned size)
{
    int i, j;

    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            data[i][j] = rand() % 20 / 10.;
        }
    }
}
void input(float data[][MAX_SIZE], unsigned size)
{
    int i, j;

    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            printf("A(%d,%d)=", i + 1, j + 1);
            scanf("%f", &data[i][j]);
        }
    }
}
void output(float data[][MAX_SIZE], unsigned size)
{
    int i, j;

    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            printf("%g\t", data[i][j]);
        }
        printf("\n");
    }
}

void minByRow(float data[][MAX_SIZE], float *result, unsigned int size)
{
    int i, j;
    int min;

    for (i = 0; i < MAX_SIZE; i++)
    {
        for (min = j = 0; j < MAX_SIZE; j++)
        {
            if (data[i][min] > data[i][j])
            {
                min = j;
            }
        }
        result[i] = data[i][min];
    }
}

void printArray(float *data, unsigned int size)
{
    int i;

    for (i = 0; i < MAX_SIZE; i++)
    {
        printf("%g\t", data[i]);
    }
    printf("\n");
}