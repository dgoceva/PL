#include "structDemo.h"

void main()
{
    // struct TStudent st;
    // TStudentInfo st1, *st2;
    // FILE *f;
    // TStudentInfo group[GROUPSIZE];
    unsigned len;
    TStudentInfo *students;

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
    // len = inputStudentGroup("students.txt", group);
    // if (len == 0)
    // {
    //     exit(EXIT_FAILURE);
    // }
    // writeStudentGroupToCSV("students.csv", group, len);
    students = readStudentGroupFromCSV("students.csv", &len);
    if (students != NULL)
    {
        outputStudentGroup(students, len);
        printf("Student Average Mark: %g\n", averageStudentMark(students, len));
        qsort(students, len, sizeof(TStudentInfo), compareMarks);
        outputStudentGroup(students, len);
        printf("\n\n\n");
        qsort(students, len, sizeof(TStudentInfo), compareNames);
        outputStudentGroup(students, len);
        free(students);
    }
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

TStudentInfo *readStudentGroupFromCSV(char *name, unsigned *len)
{
    FILE *f;
    TStudentInfo *group = NULL;
    TStudentInfo temp;
    TBOOLEAN validate;
    char buffer[1024];

    *len = 0;
    if ((f = fopen(name, "r")) == NULL)
    {
        perror("open csv:");
        return NULL;
    }

    while (!feof(f))
    {
        if (fgets(buffer, sizeof(buffer), f) == NULL)
        {
            break;
        }
        group = (TStudentInfo *)realloc(group, (*len + 1) * sizeof(TStudentInfo));
        if (group == NULL)
        {
            perror("realloc:");
            break;
        }

        temp = studentTokens(buffer, &validate);
        if (!validate)
        {
            break;
        }
        group[(*len)++] = temp;
    }
    fclose(f);
    return group;
}

float averageStudentMark(TStudentInfo *group, unsigned len)
{
    int i;
    float sum = 0;

    for (i = 0; i < len; i++)
    {
        sum += group[i].mark;
    }
    return (len != 0) ? sum / len : 0;
}

TStudentInfo studentTokens(char *buffer, TBOOLEAN *isValid)
{
    TStudentInfo st;
    char *token;

    *isValid = FALSE;
    token = strtok(buffer, ",");
    if (token == NULL)
    {
        perror("id error:");
        return st;
    }
    st.id = atoi(token);
    if (st.id == 0)
    {
        printf("student id mismatch\n");
        return st;
    }

    token = strtok(NULL, ",");
    if (token == NULL)
    {
        perror("name error:");
        return st;
    }
    strcpy(st.name, token);

    token = strtok(NULL, ",");
    if (token == NULL)
    {
        perror("mark error:");
        return st;
    }
    st.mark = atof(token);
    if (st.mark == 0)
    {
        printf("student mark mismatch\n");
        return st;
    }

    *isValid = TRUE;
    return st;
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

int compareMarks(const void *a, const void *b)
{
    float mark_a = ((TStudentInfo *)a)->mark;
    float mark_b = ((TStudentInfo *)b)->mark;

    if (mark_a > mark_b)
        return -1;
    else if (mark_a < mark_b)
        return 1;
    return 0;
}

int compareNames(const void *a, const void *b)
{
    char *name_a = ((TStudentInfo *)a)->name;
    char *name_b = ((TStudentInfo *)b)->name;

    return strcmp(name_a, name_b);
}