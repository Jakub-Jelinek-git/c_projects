#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");
    int numChars = 0;
    int numWords = 0;
    int numSentences = 0;
    for (int i = 0, lenght = strlen(text); i < lenght; i++)
    {
        if (isalpha(text[i]))
        {
            numChars++;
        }
        else if (isblank(text[i]))
        {
            numWords++;
        }
        else if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            numSentences++;
        }
    }
    if (numWords > 0)
    {
        numWords++;
    }
    printf("c: %i, w: %i, s:%i\n", numChars, numWords, numSentences);
    float avgCharsWords = (float) numChars / numWords * 100.0;
    float avgWordsSent = (float) numSentences / numWords * 100.0;
    float index = ((0.0588 * avgCharsWords) - (0.296 * avgWordsSent) - 15.8);
    int gradeNum = round(index);
    if (gradeNum <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (gradeNum >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", gradeNum);
    }
}
