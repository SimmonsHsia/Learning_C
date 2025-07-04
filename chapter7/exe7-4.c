#include <stdio.h>
#include <stdarg.h>

void minscanf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int *ival;
    float *fval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
            continue;
        switch (*++p)
        {
        case 'd':
            ival = va_arg(ap, int *);
            scanf("%d", ival);
            break;

        case 'f':
            fval = va_arg(ap, float *);
            scanf("%f", fval);
            break;

        case 's':
            sval = va_arg(ap, char *);
            scanf("%s", sval);
            break;

        default:
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    int a;
    float b;
    char *s;

    minscanf("%d %f %s", &a, &b, s);
    printf("a = %d, b = %hf, s = %s\n", a, b, s);

    return 0;
}
