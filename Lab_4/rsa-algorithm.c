// c program to rsa algorithm
// C program to implement RSA algorithm
#include <stdio.h>

long long modExp(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int modInverse(int e, int phi)
{
    int d = 1;
    while ((e * d) % phi != 1)
        d++;
    return d;
}

int main()
{
    int p, q, n, phi, e, d, m;
    long long c, decrypted;

    printf("Enter prime number p: ");
    scanf("%d", &p);

    printf("Enter prime number q: ");
    scanf("%d", &q);

    n = p * q;
    phi = (p - 1) * (q - 1);

    printf("Enter public exponent e (1 < e < %d and gcd(e,%d)=1): ", phi, phi);
    scanf("%d", &e);

    while (gcd(e, phi) != 1)
    {
        printf("Invalid e. Enter again: ");
        scanf("%d", &e);
    }

    d = modInverse(e, phi);

    printf("\nPublic key (e, n) = (%d, %d)", e, n);
    printf("\nPrivate key (d, n) = (%d, %d)\n", d, n);

    printf("\nEnter plaintext message m (m < %d): ", n);
    scanf("%d", &m);

    c = modExp(m, e, n);
    printf("Encrypted ciphertext c = %lld\n", c);

    decrypted = modExp(c, d, n);
    printf("Decrypted message = %lld\n", decrypted);

    return 0;
}
