#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    int key;
    
    // check valid input
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    } 
    else 
    {
        for (int i = 0; i < strlen(argv[1]) ; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }
    
    // calculate the encryption key
    key = atoi(argv[1]) % 26;
    
    string plaintext = get_string("plaintext: ");
    
    // an integer array for storing the ciphertext
    int tempciphertext[strlen(plaintext) - 1];
    
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // encrypt letters from 'a' to 'z'
        if ((plaintext[i] >= 'a' && plaintext[i] <= 'z'))
        {
            tempciphertext[i] = plaintext[i] + key;
            // if the vaule after encryption is bigger than 'z' - 26, so that the value starts from 'a' again 
            if (tempciphertext[i] > 'z')
            {
                tempciphertext[i] = tempciphertext[i] - 26;
            }
        }
        // encrypt letters from 'A' to 'Z'
        else if ((plaintext[i] >= 'A' && plaintext[i] <= 'Z'))
        {
            tempciphertext[i] = plaintext[i] + key;
            if (tempciphertext[i] > 'Z')
            {
                tempciphertext[i] = tempciphertext[i] - 26;
            }
        }
        else
        {
            tempciphertext[i] = plaintext[i];
        }
    }
    
    // a char array for storing the ciphertext
    char ciphertext[strlen(plaintext) - 1];
    
    for (int i = 0; i < strlen(plaintext); i++)
    {
        ciphertext[i] = tempciphertext[i];
    }
    
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}