#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int get_value_of_word(string word);
int main(void)
{

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    int points1 = get_value_of_word(word1);
    int points2 = get_value_of_word(word2);
    if (points1 > points2)
    {
        printf("Player 1 wins!\n");
    }
    else if (points1 < points2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int get_value_of_word(string word)
{
    const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int values[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                          1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int points = 0;
    for (int i = 0, lenght = strlen(word); i < lenght; i++)
    {
        char currentChar = toupper(word[i]);
        for (int j = 0, len = strlen(chars); j < len; j++)
        {
            if (currentChar == chars[j])
            {
                points += values[j];
                break;
            }
        }
    }
    return points;
}
