// c program to find additive inverse of given number
#include <stdio.h>

int main(void)
{
    int num, mod, additiveInverse;

    printf("Enter the integer: ");
    scanf("%d", &num);

    printf("Enter the modulus: ");
    scanf("%d", &mod);

    additiveInverse = (mod - (num % mod)) % mod;
    printf("Additive inverse of %d modulo %d is %d\n",
           num, mod, additiveInverse);

    return 0;
}
