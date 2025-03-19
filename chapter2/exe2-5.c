#include <stdio.h>

int any(char s[], char t[]);

int any(char s[], char t[])
{
    int i, j;

    for(i = 0; s[i] != '\0'; i++)
    {  
        for(j = 0; t[j] != '\0'; j++)
            if(s[i] == t[j])
                return i;
    }
    return (-1);
}

int main(int argc, char const *argv[])
{   
    char s1[100], s2[100];
    printf("s1:\n");
    scanf("%s", s1);
    printf("s2:\n");
    scanf("%s", s2);
    printf("pos is:%d", any(s1, s2));
    return 0;
}
