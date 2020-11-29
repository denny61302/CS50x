#include <cs50.h>
#include <stdio.h>

void triBrick(int h);

int main(void)
{
    int height;
    
    // get height and check if it in the range from 1 to 8
    do
    {
        height = get_int("How height it is ");
    }
    while (height < 1 || height > 8);
    
    triBrick(height);
}

void triBrick(int h)
{
    
    int i, j;
    
    // how many rows
    for (i = 0; i < h; i++)
    {
        //how many spaces
        for (j = h - 1; j > i; j--)
        {
            printf(" ");
        }
        //how many hashes
        for (j = 0; j <= i; j++)
        {
            printf("#");
        }
        
        printf(" ");
        printf(" ");
        
        //how many hashes
        for (j = 0; j <= i; j++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}