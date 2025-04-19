#include <stdio.h>

void itoa(int n, char s[])
{
    static int i = 0;
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n / 10)
    {
        itoa((n / 10), s);
    }
    s[i++] = n % 10 + '0';
    s[i] = '\0';
}

int main(int argc, char const *argv[])
{
    char s[5];
    itoa(254, s);
    printf("%s", s);
    return 0;
}
