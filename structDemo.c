#include "structDemo.h"

void main()
{
    // struct TStudent st;
    // TStudentInfo st1, *st2;
    // FILE *f;
    TStudentInfo group[GROUPSIZE];
    unsigned len;

    // st1 = inputStudent();
    // outputStudent(&st1);
    // if ((f = fopen("students.txt", "r")) == NULL)
    // {
    //     perror("open");
    //     exit(EXIT_FAILURE);
    // }
    // st2 = inputStudentFromTXT(f);
    // fclose(f);
    // if (st2 == NULL)
    // {
    //     exit(EXIT_FAILURE);
    // }
    // outputStudent(st2);
    // free(st2);
    len = inputStudentGroup("students.txt", group);
    if (len == 0)
    {
        exit(EXIT_FAILURE);
    }
    writeStudentGroupToCSV("students.csv", group, len);
}

TStudentInfo inputStudent()
{
    TStudentInfo st;

    printf("Student Number: ");
    scanf("%lu", &st.id);
    fflush(stdin);
    printf("Student Name: ");
    // scanf("%s", st.name);
    scanf("%[^\n]s", st.name);
    // fgets(st.name, NAMESIZE, stdin);
    // fflush(stdin);
    printf("Student Mark: ");
    scanf("%f", &st.mark);

    return st;
}

void outputStudent(TStudentInfo *st)
{
    printf("(%lu\t%s\t%g)\n", st->id, st->name, st->mark);
}

TStudentInfo *inputStudentFromTXT(FILE *file)
{
    TStudentInfo *st;
    unsigned int len;

    st = (TStudentInfo *)malloc(sizeof(TStudentInfo));
    if (st == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    if (fscanf(file, "%lu", &st->id) != 1)
    {
        free(st);
        return NULL;
    }
    if (fscanf(file, "%lu", &len) != 1)
    {
        perror("len:");
        free(st);
        return NULL;
    }
    if (fgets(st->name, len + 1, file) == NULL)
    {
        perror("name:");
        free(st);
        return NULL;
    }
    strcpy(st->name, trim(st->name));
    if (fscanf(file, "%f", &st->mark) != 1)
    {
        perror("mark:");
        free(st);
        return NULL;
    }
    return st;
}

unsigned int inputStudentGroup(char *name, TStudentInfo *group)
{
    FILE *f;
    TStudentInfo *st;
    unsigned len = 0;

    if ((f = fopen(name, "r")) == NULL)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    while (!feof(f))
    {
        st = inputStudentFromTXT(f);
        if (st == NULL)
        {
            break;
        }
        outputStudent(st);
        group[len++] = *st;
        free(st);
    }
    fclose(f);
    return len;
}

void outputStudentGroup(TStudentInfo *group, unsigned len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        outputStudent(&group[i]); // group+i
    }
}

void writeStudentGroupToCSV(char *name, TStudentInfo *group, unsigned len)
{
    FILE *f = fopen(name, "a");
    int i;

    if (f == NULL)
    {
        perror("csv open:");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < len; i++)
    {
        if (fprintf(f, "%lu,%s,%g\n", group[i].id, group[i].name, group[i].mark) < 0)
        {
            perror("write:");
            break;
        }
    }
    fclose(f);
}

char *ltrim(char *s)
{
    while (isspace(*s))
        s++;
    return s;
}

char *rtrim(char *s)
{
    char *back = s + strlen(s);
    while (isspace(*--back))
        ;
    *(back + 1) = '\0';
    return s;
}

char *trim(char *s)
{
    return rtrim(ltrim(s));
}