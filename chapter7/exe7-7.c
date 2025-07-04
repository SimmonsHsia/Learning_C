#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline_(char *line, int max);

/* find函数：打印所有与第一个参数指定的模式匹配行 */
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    char *pattern;
    FILE *fp;
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c)
            {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }

    pattern = *argv++;

    if (argc == 2)
    {
        if ((fp = fopen(*argv, "r")) == NULL)
        {
            fprintf(stderr, "can't open %s\n", *argv);
            return -1;
        }
        while (fgets(line, MAXLINE, fp) != NULL)
        {
            lineno++;
            if ((strstr(line, pattern) != NULL) != except)
            {
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
        fclose(fp);
    }
    else if (argc == 1)
        while (getline_(line, MAXLINE) > 0)
        {
            lineno++;
            if ((strstr(line, pattern) != NULL) != except)
            {
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    else
        printf("Usage: find -x -n pattern\n");
    return found;
}

int getline_(char *line, int max)
{
    if (fgets(line, max, stdin) == NULL)
        return 0;
    else
        return strlen(line);
}