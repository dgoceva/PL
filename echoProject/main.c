#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int main(int argc, char *argv[])
{
    int i;
   // puts(argv[0]);
    if (argc == 1){
        puts("Usage echoProject data...");
        return 0;
    }

    for(i=1;i<argc;++i){
       // puts(argv[i]);
       printf("%s ",argv[i]);
    }
    printf("\n");
    return 0;
}
