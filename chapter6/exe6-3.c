#include <stdio.h>
#include <String.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode
{
    char *word;
    struct tnode *left;
    struct tnode *right;
    int nlines[MAXWORD];
    int count;
};

struct tnode *addtree(struct tnode *p, char *w, int nline);
void treeprint(struct tnode *p);
int getword(char *word, int lim);
struct tnode *talloc(void);
char *strdup_(char *s);

int main(int argc, char const *argv[])
{
    int nline = 0;
    char word[MAXWORD];
    struct tnode *root;

    root = NULL;

    while ((getword(word, MAXWORD)) != EOF)
    {
        if (word[0] == '\n')
            nline++;

        if (isalpha(word[0]))
            root = addtree(root, word, nline);
        // printf("nline = %d: %s\n", nline, word);
    }
    treeprint(root);
    return 0;
}

struct tnode *addtree(struct tnode *p, char *w, int nline)
{
    int cond;

    if (p == NULL)
    {

        p = talloc();
        p->word = strdup_(w);
        p->count = 0;
        p->nlines[0] = nline;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
    {

        p->count++;
        (p->nlines)[p->count] = nline;
    }
    else if (cond < 0)
        p->left = addtree(p->left, w, nline);
    else
        p->right = addtree(p->right, w, nline);
    return p;
}

void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        int i = 0;
        treeprint(p->left);
        printf("%s: [ ", p->word);
        for (i = 0; i <= p->count; i++)
            printf("%d ", (p->nlines)[i]);
        printf("]\n");
        treeprint(p->right);
    }
}

int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()) && c != '\n')
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c))
    {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
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
