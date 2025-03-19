#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);
int lower(int c);

int htoi(char s[])
{
    int i, n;

    n = 0;
    for(i = 0; isdigit(s[i]) || (lower(s[i]) >= 'a' && lower(s[i]) <= 'f'); ++i)
    {
        if(isdigit(s[i]))
            n = 16 * n + (s[i] - '0');
        else
            n = 16 * n + (lower(s[i]) - 'a' + 10);
    }
    return n;
}

int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + 'a' - 'A';
    }
    else
    {
        return c;
    }
}

int main(int argc, char const *argv[])
{
    char s[100];
    printf("please input a number in hex:\n");
    scanf("%s", s);
    printf("number in int: %d", htoi(s));
    return 0;
}
