// c program to find gcd of two numbers
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

    printf("GCD is %d\n", a);
    return 0;
}
