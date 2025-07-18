#include <stdarg.h>
#include <stdio.h>

/* minprintf函数：带有可变参数表的简化的printf函数 */
void minprintf(char *fmt, ...)
{
    va_list ap; // 依次指向每个无名参数
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt); // 将ap指向第一个无名参数
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            continue;
        }
        switch (*++p)
        {
        case 'd':
            ival = va_arg(ap, int);
            printf("%d", ival);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++)
                putchar(*sval);
            break;
        case 'o':
            ival = va_arg(ap, int);
            printf("%o", ival);
            break;
        case 'x':
            ival = va_arg(ap, int);
            printf("%x", ival);
            break;
        case 'c':
            ival = va_arg(ap, int);
            printf("%c", ival);
            break;
        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap); // 结束时的清理工作
}