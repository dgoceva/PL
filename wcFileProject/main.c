#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define LARGE_SIZE 1000

int main(int argc,char *argv[])
{
    int i;
    FILE *f;
    FILE *out;
    char temp[LARGE_SIZE];
    unsigned len,lines,words;
    int ch;

    if (argc==1){
        puts("Usage wcFileProject file...");
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
            ch = fgetc(f);
            if (feof(f))
                break;
            fputc(toupper(ch),out);
            if (ch==' '||ch=='\t'||ch=='\n'||ch=='\r')
                words++;
            if (ch=='\n')
                lines++;
            else
                len++;
        }
        fclose(out);
        fclose(f);
        printf("%u\t%u\t%u\n",lines,words,len);
    }

  //  printf("Hello world!\n");
    return 0;
}
