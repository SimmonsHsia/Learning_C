#include <stdio.h>

int getline_chpt1(char *s, int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        *s++ = c;
    if (c == '\n')
    {
        *s++ = c;
        ++i;
    }
    *s = '\0';
    return i;
}

int getline_chpt4(char *s, int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        i++;
        *s++ = c;
    }
    if (c == '\n')
    {
        i++;
        *s++ = c;
    }
    *s = '\0';
    return i;
}

int atoi_chpt2(char *s)
{
    int n;

    n = 0;
    for (; *s >= '0' && *s <= '9'; s++)
        n = 10 * n + (*s - '0');
    return n;
}

#include <ctype.h>

int atoi_chpt3(char *s)
{
    int n, sign;

    for (; isspace(*s); s++)
        ;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    for (n = 0; isdigit(*s); s++)
        n = 10 * n + (*s - '0');
    return sign * n;
}

#include <string.h>

/* reverse函数：倒置字符串s中各个字符的位置 */
void reverse(char *s)
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = *(s + i);
        *(s + i) = *(s + j);
        *(s + j) = c;
    }
}

void itoa_chpt3(int n, char *s)
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;

    i = 0;
    do
    {
        *s = n % 10 + '0';
        s++;
        i++;
    } while ((n /= 10) > 0);
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(s - i);
}

int strindex(char *s, char *t)
{
    int i, j, k;

    for (i = 0; *(s + i) != '\0'; i++)
    {
        for (j = i, k = 0; *(t + k) != '\0' && *(s + j) == *(t + k); j++, k++)
            ;
        if (k > 0 && *(t + k) == '\0')
            return i;
    }
    return -1;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop函数：获取下一个运算符或数值操作数 */
int getop(char *s)
{
    int i, c;

    while ((*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s + 1) = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(*(s + (++i)) = c = getch()))
            ;
    if (c == '.')
        while (isdigit(*(s + (++i)) = c = getch()))
            ;
    *(s + i) = '\0';
    if (c != EOF)
        ungetch(c);
    return 0;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int main(int argc, char const *argv[])
{
    char s[100] = "abc";
    itoa_chpt3(398, s);
    printf("%s\n", s);
    return 0;
}
