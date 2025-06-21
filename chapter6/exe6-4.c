struct tnode
{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *);
int getword(char *, int);
struct tnode *treemax(struct tnode *p, int m);

struct tnode *maxp = NULL;

int main(int argc, char const *argv[])
{
    struct tnode *root;
    char word[MAXWORD];

    struct tnode *max;

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    while ((max = treemax(root, 0)) != NULL)
    {
        printf("%d: %s\n", max->count, max->word);
        max->count = 0;
        max->word = "deleted";
        maxp = NULL;
    }
    return 0;
}

struct tnode *talloc(void);
char *strdup_(char *);

struct tnode *treemax(struct tnode *p, int m)
{
    static int max = 0;
    max = m;

    if (p != NULL)
    {
        treemax(p->left, max);
        if (p->count > max)
        {
            max = p->count;
            maxp = p;
        }
        treemax(p->right, max);
    }
    return maxp;
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

#include <stdlib.h>

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

/* getword函数：从输入中读取下一个单词或字符 */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
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