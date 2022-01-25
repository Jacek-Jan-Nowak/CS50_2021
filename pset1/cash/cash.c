#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Prompt for change owed
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change <= 0);

    int cents = round(change * 100);
    int coins = 0;

    // quarters
    while (cents >= 25)
    {
        cents -= 25;
        coins++;
    }

    // dimes
    while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }

    //nickels
    while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }

    // pennies
    while (cents >= 1)
    {
        cents -= 1;
        coins++;
    }


    // Print amount of coins
    printf("%i\n", coins);
}