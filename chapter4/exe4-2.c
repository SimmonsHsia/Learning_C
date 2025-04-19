#include <ctype.h>
#include <math.h>

/* atof函数:把字符串s转换为对应的双精度浮点数 */
double atof_e(char s[])
{
    double val, power, num, val_e;
    int i, sign, sign_e;

    for (i = 0; isspace(s[i]); i++) // 跳过空白符
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    num = sign * val / power; // E前面的数值部分
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    sign_e = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val_e = 0.0; isdigit(s[i]); i++)
        val_e = 10.0 * val_e + (s[i] - '0');

    if (sign_e == 1)
        return num * pow(10, val_e);
    else
        return num * pow(10, sign_e * val_e);
}

#include <stdio.h>

int main(int argc, char const* argv[])
{
    char s[100];
    scanf("%s", s);
    printf("%f", atof_e(s));
    return 0;
}
