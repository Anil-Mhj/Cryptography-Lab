// c program to check if a number is prime using Miller-Rabin primality test
#include <stdio.h>

// Fast modular exponentiation: (a^d) % n
long long power(long long a, long long d, long long n)
{
    long long result = 1;
    a = a % n;

    while (d > 0)
    {
        if (d & 1)
            result = (result * a) % n;
        a = (a * a) % n;
        d >>= 1;
    }
    return result;
}

// Miller-Rabin test for one base 'a'
int millerTest(long long a, long long d, long long n)
{
    long long x = power(a, d, n);

    if (x == 1 || x == n - 1)
        return 1;

    while (d < n - 1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)
            return 0;
        if (x == n - 1)
            return 1;
    }

    return 0;
}

// Miller-Rabin primality test
int isPrime(long long n)
{
    if (n <= 1 || n == 4)
        return 0;
    if (n % 2 == 0)
        return (n == 2);
    if (n <= 3)
        return 1;

    // Write n-1 as d * 2^r
    long long d = n - 1;
    while ((d & 1) == 0)
        d >>= 1;

    // Deterministic bases for 32-bit integers
    int bases[] = {2, 7, 61};

    for (int i = 0; i < 3; i++)
    {
        if (bases[i] >= n)
            continue;
        if (!millerTest(bases[i], d, n))
            return 0;
    }

    return 1;
}

int main()
{
    long long n;
    printf("Enter a number: ");
    scanf("%lld", &n);

    if (isPrime(n))
        printf("%lld is a prime number.\n", n);
    else
        printf("%lld is not a prime number.\n", n);

    return 0;
}
