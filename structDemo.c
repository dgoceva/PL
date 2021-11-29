#include "structDemo.h"

void main()
{
    struct TStudent st;
    TStudentInfo st1, *st2;
    FILE *f;

    // st1 = inputStudent();
    // outputStudent(&st1);
    if ((f = fopen("students.txt", "r")) == NULL)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    st2 = inputStudentFromTXT(f);
    fclose(f);
    outputStudent(st2);
    free(st2);
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
        return NULL;
    }
    if (fscanf(file, "%lu", &len) != 1)
    {
        perror("len:");
        return NULL;
    }
    if (fgets(st->name, len + 1, file) == NULL)
    {
        perror("name:");
        return NULL;
    }
    if (fscanf(file, "%f", &st->mark) != 1)
    {
        perror("mark:");
        return NULL;
    }
    return st;
}