#ifndef __STRUCTDEMO_H__
#define __STRUCTDEMO_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

#define NAMESIZE 100
#define GROUPSIZE 100

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

typedef enum
{
    FALSE,
    TRUE
} TBOOLEAN;

TStudentInfo inputStudent();
void outputStudent(TStudentInfo *);
TStudentInfo *inputStudentFromTXT(FILE *file);
unsigned int inputStudentGroup(char *name, TStudentInfo *group);
void outputStudentGroup(TStudentInfo *group, unsigned len);
void writeStudentGroupToCSV(char *name, TStudentInfo *group, unsigned len);
TStudentInfo *readStudentGroupFromCSV(char *name, unsigned *len);
float averageStudentMark(TStudentInfo *group, unsigned len);

TStudentInfo studentTokens(char *buffer, TBOOLEAN *isValid);
char *ltrim(char *s);
char *rtrim(char *s);
char *trim(char *s);

#endif