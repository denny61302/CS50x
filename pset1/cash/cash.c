#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)
{
    float dollars;
    int coins = 0, quarters = 0, dimes = 0, nickels = 0, pennies = 0;
    
    // get dollars from user, the value should be postive floating number
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0.0);
    
    // transfer dollars to cents
    int cents = round(dollars * 100);
    
    // count how many quarters are used, and minus it
    while (cents >= 25)
    {
        quarters++;
        cents -= 25;
    }
    
    // count how many dimes are used, and minus it
    while (cents >= 10)
    {
        dimes++;
        cents -= 10;
    }
    
    // count how many nickels are used, and minus it
    while (cents >= 5)
    {
        nickels++;
        cents -= 5;
    }
    
    // count how many pennies are used, and minus it
    while (cents >= 1)
    {
        pennies++;
        cents -= 1;
    }
    
    // sum all kinds of coins
    coins = quarters + dimes + nickels + pennies;
    printf("%d\n", coins);
}