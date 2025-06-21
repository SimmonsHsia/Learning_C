#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode
{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

char *words[MAXWORD];
int nwords = 0;

int getword_pro(char *word, int lim);
struct tnode *addtree(struct tnode *, char *);
void word_add(struct tnode *);
struct tnode *talloc(void);
char *strdup_(char *);

void writewords(char *words[], int nwords, int n);

int main(int argc, char const *argv[])
{
    int n;
    *words[100];
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;

    if (argc == 1)
        n = 2;
    else if (argc == 2 && **++argv == '-')
        n = atoi(*argv + 1);
    else
        printf("Usage: print_name [-n]\n");
    printf("n = %d\n", n);

    while (getword_pro(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    word_add(root);
    writewords(words, nwords, n);
    return 0;
}

void writewords(char *words[], int nwords, int n)
{
    int i;

    printf("%s ", words[0]);
    for (i = 1; i < nwords; i++)
    {
        if (strncmp(words[i], words[i - 1], n) == 0 && strncmp(words[i], words[i - 1], n + 1) != 0)
            printf("%s ", words[i]);
        else
            printf("\n%s ", words[i]);
    }
}

/* addtree函数：在p的位置或p的下方增加一个w节点 */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL)
    {
        p = talloc();
        p->word = strdup_(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

void word_add(struct tnode *p)
{
    if (p != NULL)
    {
        word_add(p->left);
        if (nwords < MAXWORD)
            words[nwords++] = p->word;
        word_add(p->right);
    }
}

/* talloc函数：创建一个tnode */
struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

/* strdup函数：复制s到某个位置 */
char *strdup_(char *s)
{
    char *p;

    p = (char *)malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}

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
