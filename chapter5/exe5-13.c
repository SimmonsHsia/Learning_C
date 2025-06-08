#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 1000

int readlines(char *lineptr[], int maxlines);
int getline(char *s, int lim);
void strcpy_v4(char *s, char *t);
char *alloc(int n);
void afree(char *p);

int main(int argc, char const *argv[])
{
    int n = 3, nlines, i;
    char *lineptr[MAXLINES];

    if (argc == 1)
        n = 3;
    else if (argc == 2 && (*++argv)[0] == '-')
    {
        if (atoi(*argv + 1) > 0)
            n = atoi(*argv + 1);
        else
            printf("Error: [n] should be a positive number!\n");
    }
    else
        printf("Usage: tail [-n]\n");

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        for (i = nlines - n; i < nlines; i++)
            printf("%s\n", lineptr[i]);
        return 0;
    }
    else
    {
        printf("Error: input too long to print!\n");
        return -1;
    }
}

#define MAXLEN 1000

/* readlines函数：读取输入行 */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

int getline(char *s, int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void strcpy_v4(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}

#define ALLOCSIZE 1000 /* 可用空间大小 */

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
        return 0;
}

void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
