#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

unsigned countNumbers(FILE *file);
void readFromTxtFile(FILE *file, int *data, unsigned int size);
void printArray(int *data, unsigned int size);
int *getArray(char *name, unsigned int *size);

void main1()
{
    FILE *in = fopen("data.txt", "r");
    int *data;
    unsigned count;

    if (in == NULL)
    {
        perror("open file");
        exit(EXIT_FAILURE);
    }
    count = countNumbers(in);
    data = (int *)malloc(count * sizeof(int));
    if (data == NULL)
    {
        perror("malloc");
        fclose(in);
        exit(EXIT_FAILURE);
    }

    readFromTxtFile(in, data, count);
    fclose(in);

    printArray(data, count);
    free(data);
}
void main2()
{
    int *data;
    unsigned size;

    data = getArray("data.txt", &size);
    printArray(data, size);
    free(data);
}
void main()
{
    // main1();
    main2();
}
unsigned countNumbers(FILE *file)
{
    int temp, count = 0;

    while (!feof(file))
    {
        fscanf(file, "%d", &temp);
        count++;
    }
    rewind(file);
    return count;
}

void readFromTxtFile(FILE *file, int *data, unsigned int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (fscanf(file, "%d", &data[i]) != 1)
        {
            perror("readFrom");
            free(data);
            fclose(file);
            exit(EXIT_FAILURE);
        }
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

int *getArray(char *name, unsigned int *size)
{
    FILE *in = fopen(name, "r");
    int *data = NULL;

    if (in == NULL)
    {
        perror("open file");
        exit(EXIT_FAILURE);
    }
    *size = 0;
    while (!feof(in))
    {
        data = (int *)realloc(data, *size + 1);
        if (data == NULL)
        {
            perror("malloc");
            fclose(in);
            exit(EXIT_FAILURE);
        }
        if (fscanf(in, "%d", &data[(*size)++]) != 1)
        {
            perror("readFrom");
            free(data);
            fclose(in);
            exit(EXIT_FAILURE);
        }
    }
    fclose(in);
    return data;
}