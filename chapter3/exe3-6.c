#include <string.h>
#include <stdio.h>

void itoa(int n, char s[], int t);
void reverse(char s[]);

void itoa(int n, char s[], int t)
{
    int i, sign, j;

    if ((sign = n) < 0)
        n = -n;
    
    i = 0;
    do
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    int len = strlen(s);
    for (j = 0; j < t - len; j++)
    {
        s[i + j] = ' ';
    }
    s[i + j] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main(int argc, char const *argv[])
{
    char s[100];
    itoa(123, s, 7);
    printf("s:\n%s", s);
    return 0;
}