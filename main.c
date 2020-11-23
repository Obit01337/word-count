//TASK:
//Enter text in the head function.
//In the first function, calculate the number of words in the text.
//In the second, count the number of words for which the first and last characters are the same.

#include <stdio.h>
#include <stdlib.h>

int check();
int count_num_words(char** text, int num_str);
int count_same_first_last_symbols(char** text, int num_str);

int main()
{
    // Input text size
    puts("Enter number of strings");
    int num_str = check();
    puts("Enter max length of string");
    int length = check();
    char **text = NULL;
    // 22-31 creating array for text
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
    // Input text
    for (int i = 0; i < num_str; ++i)
    {
        fgets(text[i], length+1, stdin);
        rewind(stdin);
    }
    // Output text
    for (int i = 0; i < num_str; ++i)
        printf_s("\n%d %s", i, text[i]);
    // Outputs results of functions
    printf_s("\n%d words in the text", count_num_words(text, num_str));
    printf_s("\n%d words with the same first and last symbols in the text", count_same_first_last_symbols(text, num_str));
    // Freeing memory
    for (int i = 0; i < num_str; ++i)
        free(text[i]);
    free(text);
    printf_s("\n");
    getchar();
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

// The function counts the number of words in the text
int count_num_words(char** text, int num_str)
{
    int num = 0;
    for (int i = 0; i < num_str; ++i)
        for (int j = 0; text[i][j] != '\0' && text[i][j] != '\n'; ++j)
            if ((j == 0 && text[i][j] != ' ' && text[i][j] != '\t') || (text[i][j] != ' ' && text[i][j] != '\t' && (text[i][j-1] == ' ' || text[i][j-1] == '\t')))
            {
                num++;
                for (int k = j; text[i][k] != ' ' && text[i][k] != '\n' && text[i][k] != '\t' && text[i][k] != '\0'; ++k)
                    j = k;
            }
    return num;
}

// The function counts the number of words with the same beginning and end
int count_same_first_last_symbols(char** text, int num_str)
{
    int num = 0;
    for (int i = 0; i < num_str; ++i)
        for (int j = 0; text[i][j] != '\0' && text[i][j] != '\n'; ++j)
            if ((j == 0 && text[i][j] != ' ' && text[i][j] != '\t') || (text[i][j] != ' ' && text[i][j] != '\t' && (text[i][j-1] == ' ' || text[i][j-1] == '\t')))
            {
                char first = text[i][j];
                for (int k = j; text[i][k] != ' ' && text[i][k] != '\n' && text[i][k] != '\t' && text[i][k] != '\0'; ++k)
                    j = k;
                char last = text[i][j];
                if (first == last)
                    num++;
            }
    return num;
}

