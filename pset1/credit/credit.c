#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for Credit card number
    long cc_num;
    do
    {
        cc_num = get_long("Number: ");
    }
    while (cc_num <= 0);

    // Backups for checking checksum and length
    long cc_num_check = cc_num;
    long cc_num_length = cc_num;
    long cc_num_pref = cc_num;

    // Calculating Checksum
    int sum = 0;

    for (int i = 1 ; cc_num_check > 0; i++, cc_num_check /= 10)
    {
        if (i % 2 == 0)
        {
            int second_dig = 2 * (cc_num_check % 10);
            if (second_dig < 10)
            {
                sum += second_dig;
            }
            else
            {
                sum += (second_dig) / 10 + (second_dig % 10);
            }
        }
        else
        {
            sum += cc_num_check % 10;
        }
    }

    // Calculating length of the number
    if (sum % 10 == 0)
    {
        int length = 0;
        while (cc_num_length > 0)
        {
            cc_num_length /= 10;
            length++;
        }

        // Internal checks
        // long check = cc_num / 1e15;
        // printf("%li\n", check );
        // printf("%i\n", length );
        // printf("%li\n", cc_num );

        // Checking preffix of the card
        if (length == 13)
        {
            cc_num_pref = cc_num / 1e12;
        }
        else if (length == 16)
        {
            if (cc_num > 5e15)
            {
                cc_num_pref = cc_num / 1e14;
            }
            else
            {
                cc_num_pref = cc_num / 1e15;
            }

        }
        else if (length == 15)
        {
            cc_num_pref = cc_num / 1e13;
        }

        // Checking brand of the card
        if (length == 15 && (cc_num_pref == 34 || cc_num_pref == 37))
        {
            printf("AMEX\n");
        }
        else if (length == 16 && (cc_num_pref >= 51 && cc_num_pref <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 && cc_num_pref == 4) || (length == 16 && cc_num_pref == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }
}