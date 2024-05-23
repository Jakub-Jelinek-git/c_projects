#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    int intChars = 0;
    if (argc != 2)
    {
        printf("Wrong number of command line arguments. (only 1 needed)");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("wrong lenght of key!");
        return 1;
    }
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("One or more of the characters of the key are not letters");
            return 1;
        }
        intChars += (int) toupper(argv[1][i]);
    }
    if (intChars != 2015)
    {
        printf("There are duplicates of letters!!!\n");
        return 1;
    }
    char charss[26];
    for (int i = 0, len = 26; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (toupper(argv[1][i]) == charss[j])
            {
                return 1;
            }
        }
        charss[i] = toupper(argv[1][i]);
    }
    string text = get_string("plaintext: ");
    string key = argv[1];
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (islower(key[i]))
        {
            key[i] = toupper(key[i]);
        }
    }
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        bool lower = false;
        if (isalpha(text[i]))
        {
            if (islower(text[i]))
            {
                lower = true;
            }
            char currentChar = key[(int) toupper(text[i]) - 65];
            if (lower)
            {
                text[i] = tolower(currentChar);
            }
            else
            {
                text[i] = currentChar;
            }
        }
    }
    printf("ciphertext: %s\n", text);
}
