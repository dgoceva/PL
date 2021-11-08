#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_LEN 10

typedef enum
{
    FALSE,
    TRUE
} boolean;

void inputArray(int *data);
void printArray(int *data);
float averageArray(int *data);
int minArray(int *data);
int maxArray(int *data);
void powerArray(int *in, int *out, int power);
boolean isEven(int number);
unsigned int evenArray(int *in, int *out);

void main()
{
    int data[MAX_LEN];
    int output[MAX_LEN];

    inputArray(data);
    printArray(data);
    printf("Average T is %.2g\n", averageArray(data));
    printf("Min T is %d\tMax T is %d\n", minArray(data), maxArray(data));

    powerArray(data, output, 2);
    printArray(output);
}

void inputArray(int *data)
{
    int i;

    // srand((unsigned int)time(NULL));

    for (i = 0; i < MAX_LEN; i++)
    {
        data[i] = rand() % 50 - 20;
    }
}

void printArray(int *data)
{
    int i;
    for (i = 0; i < MAX_LEN; i++)
    {
        printf("%d\t", data[i]);
    }
    printf("\n");
}

float averageArray(int *data)
{
    int i;
    int sum = 0;

    for (i = 0; i < MAX_LEN; i++)
    {
        sum += data[i];
    }
    return (float)sum / (float)MAX_LEN;
}

int minArray(int *data)
{
    int i, min;
    for (min = data[0], i = 1; i < MAX_LEN; i++)
    {
        if (data[i] < min)
        {
            min = data[i];
        }
    }
    return min;
}

int maxArray(int *data)
{
    int i, max;
    for (max = data[0], i = 1; i < MAX_LEN; i++)
    {
        if (data[i] > max)
        {
            max = data[i];
        }
    }
    return max;
}

void powerArray(int *in, int *out, int power)
{
    int i;
    for (i = 0; i < MAX_LEN; i++)
    {
        out[i] = (int)pow(in[i], power);
    }
}