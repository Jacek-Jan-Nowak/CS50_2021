#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main(int argc, string argv[])
{
    //Checking if command line argument is valid
    char key[26];
    if (argc != 2)
    {
        // Handling lack of argument or too many of them
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {

        if (strlen(argv[1]) == 26)
        {
            string key_check = argv[1];
            int count;
            for (int i = 0, n = strlen(key_check); i < n ; i++)
            {
                count = 1;
                for (int j = i + 1; j < strlen(key_check); j++)
                {
                    if (key_check[i] == key_check[j])
                    {
                        count++;
                        //Set key_check[j] to 0 to avoid printing visited character
                        key_check[j] = '0';
                    }
                }
                if (count > 1 && key_check[i] != '0')
                {
                    printf("Usage: ./substitution key\n");
                    return 1;
                }
            }

            for (int i = 0, n = strlen(argv[1]); i < n ; i++)
            {
                if ((argv[1][i] < 'A' || (argv[1][i] > 'Z' && argv[1][i] < 'a') || argv[1][i] > 'z'))
                {
                    printf("Usage: ./substitution key\n");
                    return 1;
                }
                else
                {
                    // converting string into integer
                    key[i] = toupper(argv[1][i]);
                    // printf("%c\n", key[i]);
                }
            }
            // printf("Key: %s\n", key);
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }

    // Prompting for plain text
    string plaintext = get_string("plaintext: ");

    // Initialising empty string(array) for cypher text
    char ciphertext[strlen(plaintext)];

    printf("ciphertext: ");

    // Iterating over string and checking for lover and upper case characters
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (islower(plaintext[i]))
        {
            ciphertext[i] = (key[plaintext[i] - 'a']);
            printf("%c", ciphertext[i] + 32);
        }
        else if (isupper(plaintext[i]))
        {
            ciphertext[i] = (key[plaintext[i] - 'A']);
            printf("%c", ciphertext[i]);
        }
        else
        {
            // Non aplhabetical character are not to be crypted
            ciphertext[i] = plaintext[i];
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");
    return 0;
}