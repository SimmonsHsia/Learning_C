#include <stdio.h>

#define MAXLINES 3
#define MAXLINE 100

void printfl(char const *fl)
{
    int lineno = 0, page = 1;
    char line[MAXLINE];
    FILE *fp;

    if ((fp = fopen(fl, "r")) == NULL)
    {
        fprintf(stderr, "can't open file: %s", fl);
        return;
    }

    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>\nPrinting file: %s\n", fl);
    printf("Page: 1\n-------------------\n");
    while (fgets(line, MAXLINE, fp) != NULL)
    {
        lineno++;
        if (lineno > MAXLINES)
        {
            page++;
            lineno = 0;
            printf("Page: %d\n-------------------\n", page);
        }
        printf("%s", line);
    }
}

int main(int argc, char const *argv[])
{
    if (argc < 2)
        fprintf(stderr, "Usage: printfl file1 [file2 ...]\n");
    else
        while (--argc > 0)
            printfl(*++argv);
    return 0;
}
