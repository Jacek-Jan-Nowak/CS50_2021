#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main(int argc, string argv[])
{
    //Checking if command line argument is valid
    int key = 0;
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (argv[1][i] < '0' || argv[1][i] > '9')
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
            // converting string into integer
            key = atoi(argv[1]);
            printf("Key: %i\n", key);
        }
    }
    else
    {
        // Handling lack of argument or too many of them
        printf("Usage: ./caesar key\n");
        return 1;
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
            ciphertext[i] = (plaintext[i] - 'a' + key) % 26;
            printf("%c", ciphertext[i] + 'a');
        }
        else if (isupper(plaintext[i]))
        {
            ciphertext[i] = (plaintext[i] - 'A' + key) % 26;
            printf("%c", ciphertext[i] + 'A');
        }
        else
        {
            // Non aplhabetical character are not to be crypted
            ciphertext[i] = plaintext[i];
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");
}