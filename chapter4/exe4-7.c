void ungetch(int c);
int getch(void);
void ungets(char s[]);

void ungets(char s[])
{
    int i = 0;
    for (i = 0; s[i] != '\0'; i++)
        ungetch(s[i]);
}

#include <stdio.h>
int main(int argc, char const* argv[])
{
    char s[100] = "ggbod";
    ungets(s);
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