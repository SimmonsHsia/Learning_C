int strend(char *s, char *t)
{
    while (*s)
    {
        if (*t == '\0')
            return 0;
        if (*s == *t)
            t++;
        s++;
    }
    if (*t == '\0')
        return 1;
}

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char s[] = "hello, world";
    char t[] = "orld";
    char m[] = "d";
    char n[] = "hello";
    printf("t is tail of s? %d\n", strend(s, t));
    printf("m is tail of s? %d\n", strend(s, m));
    printf("n is tail of s? %d\n", strend(s, n));

    return 0;
}
