#include <cs50.h>
#include <stdio.h>

void checktpye(long credit);

int main(void)
{
    long credit;

    // get dollars from user, the value should be postive floating number

    credit = get_long("Number: ");

    checktpye(credit);
    // printf("%ld",credit);
}

void checktpye(long credit)
{

    bool vaild = false;
    int digit;
    int type;
    int length = 0;
    int tempCardDigit[16] = {};
    int cardDigit[16] = {};
    int checksum = 0;
    while (credit > 0)
    {
        digit = credit % 10;
        credit = credit / 10;
        tempCardDigit[length] = digit;
        // printf("digit: %d\n",tempCardDigit[length]);
        length++;
    }

    // printf("length: %d\n",length);

    for (int i = 0; i < length; i++)
    {
        cardDigit[i] = tempCardDigit[(length - i - 1)];
        // printf("Digit %d is %d\n",i+1,cardDigit[i]);
    }

    for (int i = 0; i < length; i++)
    {
        if ((i % 2) == 1)
        {
            if ((tempCardDigit[i] * 2 < 10))
            {
                checksum = checksum + tempCardDigit[i] * 2;
            }
            else
            {
                checksum = checksum + ((tempCardDigit[i] * 2) - 10) + 1;
            }

            // printf("Digit %d is %d\n",i+1,tempCardDigit[i]);
            // printf("Checksum: %d\n", checksum);
        }
        if ((i % 2) == 0)
        {
            checksum = checksum + tempCardDigit[i];
            // printf("Digit %d is %d\n",i+1,tempCardDigit[i]);
            // printf("Checksum: %d\n", checksum);
        }
    }

    if ((checksum % 10) == 0)
    {
        vaild = true;
    }

    type = cardDigit[0] * 10 + cardDigit[1];

    if ((length == 16) & (type >= 51) & (type <= 55) & vaild)
    {
        printf("MASTERCARD\n");
    }
    else if (((length == 16) | (length == 13)) & (cardDigit[0] == 4) & vaild)
    {
        printf("VISA\n");
    }
    else if ((length == 15) & ((type == 34) | (type == 37)) & vaild)
    {
        printf("AMEX\n");
    }
    else if ((length < 13) | (!vaild))
    {
        printf("INVALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

