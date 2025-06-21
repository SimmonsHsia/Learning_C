#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct nlist
{
    struct nlist *next;
    char *name;
    char *defn;
};

#define HASHSIZE 101
#define MAXWORD 100

static struct nlist *hashtab[HASHSIZE];

struct nlist *lookup(char *s);
unsigned hash(char *s);
int getword_pro(char *word, int lim);
struct nlist *install(char *name, char *defn);
void stallprint(void);

int main(int argc, char const *argv[])
{
    char word[MAXWORD];
    char name[MAXWORD];
    char defn[MAXWORD];

    while ((getword_pro(word, MAXWORD)) != EOF)
    {
        if (strcmp(word, "#define") == 0)
        {
            getword_pro(name, MAXWORD);
            if (isalpha(name[0]))
            {
                getword_pro(defn, MAXWORD);
                if (isalnum(defn[0]))
                    install(name, defn);
            }
        }
    }
    stallprint();
    return 0;
}

void stallprint(void)
{
    struct nlist *np;
    int i;
    for (i = 0; i < HASHSIZE; i++)
        for (np = hashtab[i]; np != NULL; np = np->next)
            printf("#define %s %s", np->name, np->defn);
}

/* install函数：将（name, defn）加入到hashtab中 */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL)
    {
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else
        free((void *)np->defn);
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

/* hash函数：为字符串s生成散列值 */
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup函数：在hashtab中查找s */
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

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