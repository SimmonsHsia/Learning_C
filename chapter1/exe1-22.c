#include <stdio.h>
#define MAXLINE 10000
#define N 8

int getline(char s[], int lim);


int getline(char s[], int lim)
{
    int c, i;
    
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int main(int argc, char const *argv[])
{
    char line[MAXLINE];
    int len = 0;
    int k = 0;
    int i = 0, j = 0, pos = 0;

    while((len = getline(line, MAXLINE)) > 0)
    {
        k = len / N;
        for(i = 0; i <= k; i++)
        {
            for(j = i * N; j < (i + 1) * N && j < len; j++)
            {
                if(line[j] == ' ' || line[j] == '\t')
                {
                    pos = j;
                }
            }

            if(pos > i * N)
            {
                line[pos] = '\n';
            }
        }
        for(i = 0; i < len; i++)
            putchar(line[i]);
    }
    return 0;
}