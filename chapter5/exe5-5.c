void strncpy(char *s, char *t, int n)
{
    int i = 0;
    while (i < n)
    {
        *s++ = *t;
        i++;
        if (*t == '\0')
            break;
        t++;
    }
}

void strncat(char *s, char *t, int n)
{
    int i = 0;
    while (*s)
        s++;
    while (i < n)
    {
        i++;
        *s++ = *t;
        if (*t == '\0')
            break;
        t++;
    }
}

int strncmp(char *s, char *t, int n)
{
    int i = 0;

    for (i = 0; *s++ == *t++; i++)
        if (i >= n - 1 || *s == '\0')
            return 0;

    return *s - *t;
}

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char s[] = "hello, world!";
    char t[] = "hello";
    int n = 5;

    printf("%d", strncmp(s, t, n));
    return 0;
}
