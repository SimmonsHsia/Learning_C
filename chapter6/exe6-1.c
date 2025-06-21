#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* getword_pro函数：从输入中读取下一个单词或字符 */
int getword_pro(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    char s[lim];
    int i;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (c == '"')
    {
        for (i = 0; i < lim; i++)
            if ((s[i] = getch()) == '"')
            {
                s[++i] = '\0';
                strcpy(w, s);
                return s[0];
            }
        for (i = 0; s[i] != '\0'; i++)
        {
            ungetch(s[i]);
            return c;
        }
    }
    else if (c == '/')
    {
        if ((*w++ = getch()) == '/')
        {
            for (; --lim > 0; w++)
                if ((*w = getch()) == '\n')
                    break;
            *w = '\0';
            return word[2];
        }
        else
        {
            ungetch(*--w);
            *w = '\0';
            return c;
        }
    }
    else if (c == '#')
    {
        for (; --lim > 0; w++)
            if (!isalnum(*w = getch()))
            {
                ungetch(*w);
                break;
            }
        *w = '\0';
        return c;
    }
    else if (!isalpha(c) && c != '_')
    {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch()) && *w != '_')
        {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
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

#define MAXWORD 100

int main(int argc, char const *argv[])
{
    char word[MAXWORD];
    while (getword_pro(word, MAXWORD) != EOF)
    {
        printf("%s|", word);
    }
    return 0;
}
