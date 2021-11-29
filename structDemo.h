#ifndef __STRUCTDEMO_H__
#define __STRUCTDEMO_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define NAMESIZE 100

struct TStudent
{
    unsigned long id;
    char name[NAMESIZE];
    float mark;
};

typedef struct
{
    unsigned long id;
    char name[NAMESIZE];
    float mark;
} TStudentInfo;

TStudentInfo inputStudent();
void outputStudent(TStudentInfo *);
TStudentInfo *inputStudentFromTXT(FILE *file);

#endif