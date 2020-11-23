#include <stdio.h>
#include <stdlib.h>

int check();
int count_num_words(char** text, int num_str, int length);

int main()
{
    puts("Enter number of strings");
    int num_str = check();
    puts("Enter max length of string");
    int length = check();
    char **text = NULL;
    if (!(text = (char**)malloc(num_str * sizeof(char*))))
        return 144;
    for (int i = 0; i < num_str; ++i)
        if (!(text[i] = (char *) malloc((length + 1) * sizeof(char))))
        {
            for (int j = 0; j < i; ++j)
                free(text[j]);
            free(text);
            return 145;
        }
    puts("Enter your text");
    for (int i = 0; i < num_str; ++i)
    {
        fgets(text[i], length+1, stdin);
        rewind(stdin);
    }
    for (int i = 0; i < num_str; ++i)
        printf_s("\n%d %s", i, text[i]);
    int num = count_num_words(text, num_str, length);
    printf_s("\n%d words in the text", num);
    return 0;
}

// Function for correct input
int check()
{
    int number;
    char check;
    do
    {
        rewind(stdin);
        puts("Input\t");
    }while ( !(scanf_s("%d%c", &number, &check)) || check != '\n' || number <= 0);
    return number;
}

int count_num_words(char** text, int num_str, int length)
{
    int num = 0;
    for (int i = 0; i < num_str; ++i)
        for (int j = 0; j < length && text[i][j] != '\0' && text[i][j] != '\n'; ++j)
            if ((j == 0 && text[i][j] != ' ' && text[i][j] != '\t') || (text[i][j] != ' ' && text[i][j] != '\t' && (text[i][j-1] == ' ' || text[i][j-1] == '\t')))
            {
                num++;
                for (int k = j; text[i][k] != ' ' && text[i][k] != '\n' && text[i][k] != '\t' && text[i][k] != '\0'; ++k)
                    j = k;
            }
    return num;
}
