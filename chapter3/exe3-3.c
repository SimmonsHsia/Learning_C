#include <stdio.h>

void expand(char s1[], char s2[]);

void expand(char s1[], char s2[])
{
    int i, j, k;
    int left = 0, right = 0;

    for(i = 0,j = 0; s1[i] != '\0'; i++) {
        if(s1[i] != '-')
            s2[j++] = s1[i];
        else {
            if(i == 0)
                s2[j++] = s1[i];
            else if(s1[i + 1] == '\n')
                s2[j++] = s1[i];
            else {
                left = s1[i - 1];
                right = s1[i + 1];
                if((right - left) > 1 && (left - '`') * (right - '`') > 0) {
                    for(k = left + 1; k < right; k++)
                        s2[j++] = k;
                }
                else
                    s2[j++] = s1[i];
            }
                 
        }
    }
    s2[j] = '\0';
}

int main(int argc, char const *argv[])
{
    char s1[1000], s2[1000];
    int c = 0, i = 0;
    printf("please input s1:\n");
    for(i = 0; (c = getchar()) != EOF; i++)
        s1[i] = c;
    s1[i] = '\0';
    expand(s1, s2);
    printf("s2:\n%s", s2);
    return 0;
}
