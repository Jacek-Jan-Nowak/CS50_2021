#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Asking user for the name and greeting him
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}