#include <ctype.h>
#include <stdio.h>
#include <math.h>

int getch(void);
void ungetch(int);
int getfloat(float *pn);

int getfloat(float *pn)
{
    int c, sign, i;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    if (!isdigit(c))
        ungetch(c);
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    if (c == '.')
    {
        c = getch();
        for (i = 0; isdigit(c); c = getch())
        {
            *pn = 10 * *pn + (c - '0');
            i++;
        }
        *pn /= pow(10, i);
    }
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
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
    float n;
    getfloat(&n);
    printf("n = %f\n", n);
    return 0;
}
