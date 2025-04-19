#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);
void print(void);
void copy(void);
void exchange(void);
void clear(void);

int main(int argc, char const* argv[])
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zreo divisor\n");
            break;
        case '%':
            op2 = pop();
            push(fmod(pop(), op2));
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

//=========================栈命令==================================
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

/* push函数：把f压入值栈中 */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop函数：弹出并返回栈顶的值 */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empth\n");
        return 0.0;
    }
}

/* print函数：在不弹出元素的情况下打印栈顶元素 */
void print(void)
{
    int sp_temp = sp - 1;
    printf("the top of stack is: %f\n", val[sp_temp]);
}

/* copy函数：复制栈顶元素 */
void copy(void)
{
    int sp_temp = sp - 1;
    if (sp < MAXVAL)
        push(val[sp_temp]);
    else
        printf("error: stack full, can't push %g\n", val[sp_temp]);
}

/* exchange函数：交换栈顶两个元素的值 */
void exchange(void)
{
    if (sp >= 2) {
        double stack_top_0 = pop();
        double stack_top_1 = pop();
        push(stack_top_0);
        push(stack_top_1);
    }
    else
        printf("error: stack has less than two numbers!");
}

/* clear函数：清空栈 */
void clear(void)
{
    sp = 0;
}

//================================================================

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop函数：获取下一个运算符或数值操作数 */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
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