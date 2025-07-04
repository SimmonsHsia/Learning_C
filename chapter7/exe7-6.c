#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 100

int main(int argc, char const *argv[])
{
    char line1[MAXLINE], line2[MAXLINE];
    FILE *fp1, *fp2;
    char const *prog;
    prog = argv[0];

    if (argc == 3)
    {
        if ((fp1 = fopen(*++argv, "r")) == NULL)
        {
            fprintf(stderr, "%s: can't open %s\n", prog, *argv);
            exit(1);
        }
        if ((fp2 = fopen(*++argv, "r")) == NULL)
        {
            fprintf(stderr, "%s: can't open %s\n", prog, *argv);
            exit(1);
        }
    }
    else
    {
        printf("Usage: diff file1 file2\n");
        exit(2);
    }

    while (fgets(line1, MAXLINE, fp1) != NULL)
    {
        if (fgets(line2, MAXLINE, fp2) != NULL)
        {
            if (strcmp(line1, line2) != 0)
            {
                printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
                printf("file1: %s\n", line1);
                printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                printf("file2: %s\n", line2);
                fclose(fp1);
                fclose(fp2);
                exit(0);
            }
        }
        else
        {
            printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
            printf("file1: %s\n", line1);
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
            printf("file2:  \n");
            fclose(fp1);
            fclose(fp2);
            exit(0);
        }
    }
    if (fgets(line2, MAXLINE, fp2) != NULL)
    {
        printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
        printf("file1: %s\n", line1);
        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("file2: %s\n", line2);
    }
    else
    {
        printf("Two files are the same\n");
    }

    fclose(fp1);
    fclose(fp2);
    exit(0);
}
