// c program to check if two numbers are co-prime
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, temp;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    a = abs(a);
    b = abs(b);

    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }

    if (a == 1)
        printf("The numbers are co-prime.\n");
    else
        printf("The numbers are not co-prime.\n");

    return 0;
}
