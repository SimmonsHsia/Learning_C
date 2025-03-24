void escape(char s[], char t[])
{
    int i = 0;
    int j = 0;
    for(i = 0; t[i] != '\0'; i++) {
        if(t[i] == '\n') {
            s[j++] = '\\';
            s[j++] = 'n';
        }
        else if(t[i] == '\t') {
            s[j++] = '\\';
            s[j++] = 't';
        }
        else
            s[j++] = t[i];
    }
    s[j] = '\0';
}

void rev_escape(char s[], char t[])
{
    int i = 0;
    int j = 0;
    for(i = 0; t[i] != '\0'; i++) {
        if(t[i] == '\\' && t[i+1] == 'n') {
            s[j++] = '\n';
            i++;
        }
        else if(t[i] == '\\' && t[i+1] == 't') {
            s[j++] = '\t';
            i++;
        }
        else
            s[j++] = t[i];
    }
    s[j] = '\0';
}

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char s[1000];
    char t[1000];
    int c = 0;
    int i = 0;
    while((c = getchar()) != EOF)
    {
        t[i++] = c;
        t[i] = '\0';
    }
    escape(s, t);
    printf("escape:\n%s", s);
    rev_escape(t, s);
    printf("\nrev_escape:\n%s", t);

}
