#include <stdio.h>
#include <stdlib.h>

int main1()
{
    char name[50];
    // int age;
    unsigned age;

    printf("Input your name: ");
    scanf("%s",name);  // &name[0]
    printf("Input age: ");
//    scanf("%d",&age);
    scanf("%u",&age);
//    printf("My age is %d\n",age);
    if (age > 120){
        printf("Wrong age\n");
        return -1;
    }

    printf("\n\nHello world!\n");
    printf("Hello C Language!\n");
    printf("Hello %s!\n",name);
    printf("My age is %u\n",age);
    return 0;
}

int main()
{
    int cel;
    float far;

    printf("Input C degree: ");
    scanf("%d",&cel);
    far = cel*(float)9/5.+32;
    printf("%dC = %gF\n",cel,far);
    return 0;
}
