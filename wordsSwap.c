#include "general.h"


int isword(char a)
{
    if (a !=  ' ' && a != '\t')
        return 1;
    return 0;
}
void swapp(char **s, int size)
{
    for (int i = 0; i < size /2; i++)
    {
        char *temp;
        temp = s[i];
        s[i] = s[size -1 - i];
        s[size -1 - i] = temp;
    }
}

void wordsSwap(char *s)
{
    char **words = (char**) malloc(sizeof(char *) * 100);
    if (!words) return NULL;
    char *word = malloc(sizeof(char) * 100);
    if (!word) return NULL;

    int n = 0;
    for (int i = 0; s[i]; i++)
    {
        int k = 0;
        for (k = 0; isword(s[i++]); k++)
            word[k] = s[i];
        word[k] = '\0';
        words[n] = malloc(sizeof(char) * strlen(word));
        strcpy(words[n++],word);
    }
    swapp(words, n);
}



int main()
{
    char a[] = "wach akhay ssat hani kolchi mzyan";
    wordsSwap(a);
    printf("%s", a);;
}