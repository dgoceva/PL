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
void printArray(int *data, unsigned int size);
float averageArray(int *data, unsigned int size);
int minArray(int *data, unsigned int size);
int maxArray(int *data, unsigned int size);
void powerArray(int *in, int *out, int power);
boolean isEven(int number);
unsigned int evenArray(int *in, int *out);

void main()
{
    int data[MAX_LEN];
    int output[MAX_LEN];
    unsigned len;

    inputArray(data);
    printArray(data, MAX_LEN);
    printf("Average T is %.2g\n", averageArray(data, MAX_LEN));
    printf("Min T is %d\tMax T is %d\n", minArray(data, MAX_LEN), maxArray(data, MAX_LEN));

    powerArray(data, output, 2);
    printArray(output, MAX_LEN);

    len = evenArray(data, output);
    printArray(output, len);
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

void printArray(int *data, unsigned int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\t", data[i]);
    }
    printf("\n");
}

float averageArray(int *data, unsigned int size)
{
    int i;
    int sum = 0;

    for (i = 0; i < size; i++)
    {
        sum += data[i];
    }
    return size == 0 ? 0 : (float)sum / (float)size;
}

int minArray(int *data, unsigned int size)
{
    int i, min;
    for (min = data[0], i = 1; i < size; i++)
    {
        if (data[i] < min)
        {
            min = data[i];
        }
    }
    return min;
}

int maxArray(int *data, unsigned int size)
{
    int i, max;
    for (max = data[0], i = 1; i < size; i++)
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

boolean isEven(int number)
{
    return number % 2 == 0;
}

unsigned int evenArray(int *in, int *out)
{
    int i, j;

    for (i = j = 0; i < MAX_LEN; i++)
    {
        if (isEven(in[i]))
        {
            out[j++] = in[i];
        }
    }
    return j;
}