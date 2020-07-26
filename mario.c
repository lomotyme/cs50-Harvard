#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Enter an integer between 1 and 8: ");
    }
    while (n < 1 || n > 8);
    for (int i = 0; i < n; i++)
    {
        for (int j = n; (j-1) > i; j--)
        {
            printf(" ");

        }
        for (int k = -1; k < i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int a = -1 ;a < i; a++)
        {
            printf("#");
        }
        for (int b = n; (b-1) > i; b--)
        {
            printf(" ");
        }
        printf("\n");
    }
}