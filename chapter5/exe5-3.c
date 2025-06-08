void strcat_(char *s, char *t)
{

    while (*s != '\0')
        s++;
    while (*s = *t)
    {
        s++;
        t++;
    }
}

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char s[] = "hello, ";
    char t[] = "world";
    strcat_(s, t);
    printf("%s", s);
    return 0;
}
