#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for height of the pyramid
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    // Building the pyramid
    for (int i = 1; i <= h; i++)
    {
        // Whitepaces before each row
        for (int j = h; j > i; j--)
        {
            printf(" ");
        }
        // Each row of the pyramid
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        printf("  ");

        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}