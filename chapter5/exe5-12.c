#include <stdio.h>
#include <stdlib.h>

#define N 8
#define MAXLINE 1000

int getline(char s[], int lim);
void entab_e(int m, int n, int num);

int main(int argc, char const *argv[])
{
    int m = 0, n = 8, len;
    char line[MAXLINE];

    if (argc == 3 && (*(argv + 1))[0] == '-' && (*(argv + 2))[0] == '+')
    {
        m = atoi(*(argv + 1) + 1);
        n = atoi(*(argv + 2) + 1);
    }

    printf("m = %d, n = %d\n", m, n);

    while ((len = getline(line, MAXLINE)) > 0)
    {
        int i, is_space = 0, num = 0;
        for (i = 0; i < len; i++)
        {
            if (line[i] == ' ')
            {
                if (is_space)
                {
                    num += 1;
                }
                else
                {
                    is_space = 1;
                    num = 1;
                }
            }
            else
            {
                if (is_space)
                {
                    entab_e(m, n, num);
                    num = 0;
                    is_space = 0;
                    putchar(line[i]);
                }
                else
                {
                    putchar(line[i]);
                }
            }
            // printf("%d", num);
        }
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

void entab_e(int m, int n, int num)
{
    int i;
    if (m + n > num)
        for (i = 0; i < num; i++)
            putchar(' ');
    else
    {
        for (i = 0; i < m; i++)
            putchar(' ');
        for (i = 0; i < (num - m) / n * n; i++)
            putchar('*');
        for (i = 0; i < (num - m) % n; i++)
            putchar(' ');
    }
}