#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverese);
void qsort_1(void *v[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
int getline(char *s, int lim);
char *alloc(int n);
void afree(char *p);
int strcmp_f(char *s, char *t);
int strcmp_d(char *s, char *t);
int strcmp_df(char *s, char *t);
int is_directory(char c);

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines, c;   /* number of input lines read */
    int numeric = 0; /* 1 if numeric sort */
    int reverse = 0;
    int no_case = 0;
    int directory = 0;
    int (*compptr)(void *, void *);

    while (--argc > 0 && (*++argv)[0] == '-')
    {
        while (c = *++argv[0])
            switch (c)
            {
            case 'r':
                reverse = 1;
                break;
            case 'n':
                numeric = 1;
                break;
            case 'f':
                no_case = 1;
                break;
            case 'd':
                directory = 1;
                break;
            default:
                printf("error: illegal option %c\n", c);
                argc = 0;
                break;
            }
    }

    if (numeric)
        compptr = (int (*)(void *, void *))numcmp;
    else if (no_case)
    {
        if (directory)
            compptr = (int (*)(void *, void *))strcmp_df;
        else
            compptr = (int (*)(void *, void *))strcmp_f;
    }
    else
    {
        if (directory)
            compptr = (int (*)(void *, void *))strcmp_d;
        else
            compptr = (int (*)(void *, void *))strcmp;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort_1((void *)lineptr, 0, nlines - 1, compptr);
        writelines(lineptr, nlines, reverse);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }
}

void qsort_1(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right) /* do  nothing if array contains */
        return;        /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort_1(v, left, last - 1, comp);
    qsort_1(v, last + 1, right, comp);
}

#define MAXLEN 1000

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

void writelines(char *lineptr[], int nlines, int reverse)
{
    int i;
    if (reverse)
        for (i = nlines - 1; i >= 0; i--)
            printf("%s\n", lineptr[i]);
    else
        for (i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
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

int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

int strcmp_f(char *s, char *t)
{
    for (; tolower(*s) == tolower(*t); s++, t++)
        if (*s == '\0')
            return 0;
    return tolower(*s) - tolower(*t);
}

int strcmp_d(char *s, char *t)
{
    while (*s)
    {
        if (is_directory(*s))
        {
            if (is_directory(*t))
            {
                if (*s != *t)
                    return *s - *t;
                s++;
                t++;
            }
            else
                t++;
        }
        else
        {
            s++;
        }
    }
    return *s - *t;
}

int strcmp_df(char *s, char *t)
{
    while (*s)
    {
        if (is_directory(*s))
        {
            if (is_directory(*t))
            {
                if (tolower(*s) != tolower(*t))
                    return tolower(*s) - tolower(*t);
                s++;
                t++;
            }
            else
                t++;
        }
        else
        {
            s++;
        }
    }
    return tolower(*s) - tolower(*t);
}

int is_directory(char c)
{
    if (isdigit(c) || isspace(c) || isupper(c) || islower(c))
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
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
