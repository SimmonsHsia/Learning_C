#include <stdio.h>
#define MAXLEN 1000
int getline(char *, int);

int readlines(char *lineptr[], char lines[], int maxlines)
{
    int len, nlines;
    char *p = lines, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines)
        {
            return -1;
        }
        else
        {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
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