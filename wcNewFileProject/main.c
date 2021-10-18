#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define LARGE_SIZE 1000
#define DELIM " \t\n\r"

int main(int argc,char *argv[])
{
    int i;
    FILE *f;
    FILE *out;
    char temp[LARGE_SIZE];
    char line[LARGE_SIZE];
    char *token;
    unsigned len,lines,words;


    if (argc==1){
        puts("Usage wcNewFileProject file...");
        return 0;
    }

    for (i=1;i<argc;++i){
        len=0;
        lines=words=1;
        f = fopen(argv[i],"r");
        if (f==NULL){
            perror("fopen error: ");
            return EXIT_FAILURE;
        }
        strcpy(temp,argv[i]);
        strcat(temp,".out");
        out = fopen(temp,"w");
        while(TRUE){
            if (fgets(line,LARGE_SIZE,f)==NULL)
                break;
            len += strlen(line);
            lines++;
            token = strtok(line,DELIM);
            for(;token!=NULL;words++){
                fputs(token,out);
                token = strtok(NULL,DELIM);
            }
        }
        fclose(out);
        fclose(f);
        printf("%u\t%u\t%u\n",lines,words,len);
    }

  //  printf("Hello world!\n");
    return 0;
}
