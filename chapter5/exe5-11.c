#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int getline(char s[], int lim);

int detab(int n)
{
    int c = 0, i = 0, j = 0;
    while ((c = getchar()) != EOF)
    {

        if (c == '\t')
        {
            for (j = 0; j < n - i; ++j)
            {
                putchar('*');
            }
        }
        else
            putchar(c);

        if (i < n - 1)
            ++i;
        else
            i = 0;
        if (c == '\n')
            i = 0;
    }

    return 0;
}

int getline(char s[], int lim)
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

int entab(int n)
{
    int len = 0, i = 0;
    int start = 0, num = 0;
    int nt = 0, ns = 0;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
    {

        for (i = 0; i < len; ++i)
        {

            if (line[i] == ' ')
            {
                if (num == 0)
                {
                    start = i;
                    num++;
                }
                else
                {
                    num++;
                }
            }

            if (line[i] != ' ')
            {
                if (num == 0)
                {
                    putchar(line[i]);
                }
                else
                {
                    start %= n;

                    if ((start + num) / n)
                    {
                        for (nt = 0; nt < ((start + num) / n); nt++)
                            putchar('\t');
                        for (ns = 0; ns < ((start + num) % n); ns++)
                            putchar('*');
                    }
                    else
                    {
                        for (ns = 0; ns < num; ns++)
                            putchar('*');
                    }

                    putchar(line[i]);
                    num = 0;
                    start = 0;
                }
            }
        }
        num = 0;
        start = 0;
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    if (argc == 1)
        detab(8);
    else if (argc == 2)
        detab(atoi(*++argv));
    else
        printf("Usage: detab [n=8]\n");
    return 0;
}
