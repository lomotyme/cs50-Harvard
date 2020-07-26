#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars <= 0);

    int cents = round(dollars * 100);

    int quarters = round(cents / 25);
    int r = cents % 25;

    int dimes = r / 10;
    int x = r % 10;

    int nickels = x / 5;
    int y = x % 5;

    int cent = y / 1;

    int coins = quarters + dimes + nickels + cent;

    printf(" The least number of coins is: %i\n", coins);


}
