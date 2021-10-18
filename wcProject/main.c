#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countLF(char *line){
    int count=0;
    int i;

    for(i=0;i<strlen(line);++i){
        if (line[i]=='\n')
            count++;
    }
    return count;
}

int main(int argc,char *argv[])
{
    int i;
    long len=0,line=0;

    if (argc==1){
        puts("Usage wcProject switch data...");
        return 0;
    }

    for (i=1;i<argc;++i){
        len += strlen(argv[i]);
        line += countLF(argv[i]);
    }

    printf("%ld\t%d\t%ld\n",line+1,argc,len);
    //printf("Hello world!\n");
    return 0;
}
