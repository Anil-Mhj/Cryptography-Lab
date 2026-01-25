// c program to find multiplicative inverse of given number
#include <stdio.h>

int main()
{
    int a, b, mod, x0 = 1, x1 = 0, q, temp;
    printf("Enter two integers (a and b) to find inverse of a mod b: ");
    scanf("%d %d", &a, &b);

    if (b <= 1) {
        printf("Modulus must be greater than 1.\n");
        return 0;
    }

    mod = b;
    a = (a % b + b) % b;

    while (b != 0)
    {
        q = a / b;

        temp = b;
        b = a % b;
        a = temp;

        temp = x1;
        x1 = x0 - q * x1;
        x0 = temp;
    }

    if (a != 1)
        printf("Multiplicative inverse does not exist.\n");
    else
        printf("Multiplicative inverse is %d\n", (x0 % mod + mod) % mod);

    return 0;
}
