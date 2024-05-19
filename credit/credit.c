#include <cs50.h>
#include <stdio.h>

int countDigits(long number);
int isLegitCard(long cNumber, int numDig);
int lasttwoNums(long num, int numLenght);
int main(void)
{
    long creditNum = get_long("Number: ");
    int numDig = countDigits(creditNum);
    int cardValid = isLegitCard(creditNum, numDig);
    int lastTwoNums = lasttwoNums(creditNum, numDig);
    if (numDig < 13 || numDig > 16)
    {
        printf("INVALID\n");
    }
    else if (!cardValid)
    {
        printf("INVALID\n");
    }
    else if ((numDig == 13 || numDig == 16) && lastTwoNums / 10 == 4)
    {
        printf("VISA\n");
    }
    else if (numDig == 15 && (lastTwoNums == 34 || lastTwoNums == 37))
    {
        printf("AMEX\n");
    }
    else if (numDig == 16 && (lastTwoNums >= 51 && lastTwoNums <= 55))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int countDigits(long number)
{
    int i;
    for (i = 0; 0 != number; i++)
    {
        number /= 10;
    }
    return i;
}
int isLegitCard(long cNumber, int numDig)
{
    int i;
    int didget;
    int diSum = 0;
    for (i = 0; i < numDig; i++)
    {
        didget = cNumber % 10;
        if (i % 2 == 1)
        {
            didget *= 2;
            diSum += didget % 10;
            didget /= 10;
            diSum += didget;
        }
        else
        {
            diSum += didget;
        }
        cNumber /= 10;
    }
    if (diSum % 10 == 0)
        return 1;
    else
        return 0;
}
int lasttwoNums(long num, int numLenght)
{
    long divNum = 1;
    for (int i = 0; i < numLenght - 2; i++)
    {
        divNum *= 10;
    }
    return num / divNum;
}
