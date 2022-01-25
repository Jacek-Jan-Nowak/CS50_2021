#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int compute_letters(string text);

int compute_words(string text);

int compute_sentences(string text);

int main(void)
{
    // Get input text from the user
    string text = get_string("Text: ");

    // Total number of letters in the text
    int letters = compute_letters(text);
    // printf("%i letter(s)\n", letters );

    // Total number of words in the text
    int words = compute_words(text);
    // printf("%i word(s)\n", words );

    // Total number of sentences in the text
    int sentences = compute_sentences(text);
    // printf("%i sentence(s)\n", sentences );

    //Average number of letters per 100 words
    float L = (letters * 100) / (float)words;
    //Average number of sentences per 100 words
    float S = (sentences * 100) / (float)words;

    // printf("%f L\n", L );
    // printf("%f S\n", S );

    //Calculating grade using Coleman-Liau index
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    // printf("%i grade\n", index );

    //Final Grade
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    // printf("\n");
}

int compute_letters(string text)
{
    int letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
    }
    return letters;
}

int compute_words(string text)
{
    int words = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            words += 1;
        }
    }

    return words;
}

int compute_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] ==  63)
        {
            sentences += 1;
        }
    }

    return sentences;
}