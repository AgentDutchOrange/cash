#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // get the dollar amount from user as a float
    float dollars;
    do 
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0.01);

    // convert dollars to cents as integer
    int cents = round(dollars * 100);
    //number of quarters required
    int q = 0;
    while (q * 25 <= cents)
    {
        ++q;
    }
    if (q > 0)
    {
        --q;
    }
    //number of dimes required
    int d = 0;
    while (d * 10 <= cents - q * 25)
    {
        ++d;
    }
    if (d > 0)
    {
        --d;
    }
    //number of nickels required
    int n = 0;
    while (n * 5 <= cents - (q * 25) - (d * 10))
    {
        ++n;
    }
    if (n > 0)
    {
        --n;
    }
    //number of pennies required
    int p = 0;
    while (p * 1 <= cents - (q * 25) - (d * 10) - (n * 5))
    {
        ++p;
    }
    if (p > 0)
    {
        --p;
    }
    printf("Quarters: %i, Dimes: %i, Nickels: %i, Pennies: %i\n", q, d, n, p);
}
