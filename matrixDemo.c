#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX_SIZE 3

void input(float data[][MAX_SIZE], unsigned size);
void output(float data[][MAX_SIZE], unsigned size);
void randomInput(float data[][MAX_SIZE], unsigned size);
void minByRow(float data[][MAX_SIZE], float *result, unsigned int size);
float *genPosArray(float data[][MAX_SIZE], unsigned int size, unsigned int len);
unsigned int countPos(float data[][MAX_SIZE], unsigned size);
void printArray(float *data, unsigned int size);

void main()
{
    float data[MAX_SIZE][MAX_SIZE];
    float min[MAX_SIZE];
    float *result;
    unsigned len = countPos(data, MAX_SIZE);

    // input(data, MAX_SIZE);
    randomInput(data, MAX_SIZE);
    output(data, MAX_SIZE);
    minByRow(data, min, MAX_SIZE);
    printArray(min, MAX_SIZE);
    result = genPosArray(data, MAX_SIZE, len);
    printArray(result, len);
    free(result);
    result = NULL;
}

void randomInput(float data[][MAX_SIZE], unsigned size)
{
    int i, j;

    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            data[i][j] = rand() % 20 / 10. - 1;
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

    printf("-------------------------------------\n");
    for (i = 0; i < MAX_SIZE; i++)
    {
        printf("%g\t", data[i]);
    }
    printf("\n");
}

float *genPosArray(float data[][MAX_SIZE], unsigned int size, unsigned int len)
{
    float *result = (float *)malloc(len * sizeof(float));
    int i, j, k = 0;

    if (result == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (data[i][j] >= 0)
            {
                result[k++] = data[i][j];
            }
        }
    }
    return result;
}

unsigned int countPos(float data[][MAX_SIZE], unsigned size)
{
    int i, j, count = 0;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (data[i][j] >= 0)
            {
                count++;
            }
        }
    }
    return count;
}