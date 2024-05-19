#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("first number to compare: ");
    int y = get_int("compare this num to: ");
    if (x == y)
    {
        printf("%i is equal to %i.\n",x,y);
    }
    else if (x < y  )
    {
        printf("%i is smaller then %i.\n",x,y);
    }
    else
    {
        printf("%i is greater then %i.\n",x,y);
    }
}
