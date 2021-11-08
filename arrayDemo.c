#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_LEN 10
#define isOdd(x) ((x) % 2 != 0)

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
int minOddValue(int *data, unsigned int size);

void main()
{
    int data[MAX_LEN];
    int output[MAX_LEN];
    unsigned len;
    int min, max;

    inputArray(data);
    printArray(data, MAX_LEN);
    printf("Average is %.2g\n", averageArray(data, MAX_LEN));

    min = minArray(data, MAX_LEN);
    max = maxArray(data, MAX_LEN);
    printf("Min is %d, index: %d\tMax is %d, index: %d\n",
           data[min], min, data[max], max);

    powerArray(data, output, 2);
    printArray(output, MAX_LEN);

    len = evenArray(data, output);
    printArray(output, len);

    min = minOddValue(data, MAX_LEN);
    if (min == -1)
    {
        printf("No odd element...\n");
    }
    else
    {
        printf("Min odd element is %d, it's position is %d\n",
               data[min], min + 1);
    }
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
    for (min = 0, i = 1; i < size; i++)
    {
        if (data[i] < data[min])
        {
            min = i;
        }
    }
    return min;
}

int maxArray(int *data, unsigned int size)
{
    int i, max;
    for (max = 0, i = 1; i < size; i++)
    {
        if (data[i] > data[max])
        {
            max = i;
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

int minOddValue(int *data, unsigned int size)
{
    int min;
    int i;

    for (min = -1, i = 0; i < size; i++)
    {
        if (isOdd(data[i]))
        {
            if (min == -1)
            {
                min = i;
            }
            else if (data[i] < data[min])
            {
                min = i;
            }
        }
    }
    return min;
}