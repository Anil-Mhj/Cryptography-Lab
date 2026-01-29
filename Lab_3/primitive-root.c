// c program to find the primitive root of a number
#include <stdio.h>

// Function to compute gcd
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Fast modular exponentiation
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;

    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// Compute Euler's Totient function
int phi(int n) {
    int result = n;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main() {
    int n, g;
    int factors[32], count = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter g: ");
    scanf("%d", &g);

    if (gcd(g, n) != 1) {
        printf("%d is NOT a primitive root of %d\n", g, n);
        return 0;
    }

    int phi_n = phi(n);
    int temp = phi_n;

    // Find prime factors of phi(n)
    for (int i = 2; i * i <= temp; i++) {
        if (temp % i == 0) {
            factors[count++] = i;
            while (temp % i == 0)
                temp /= i;
        }
    }
    if (temp > 1)
        factors[count++] = temp;

    // Check primitive root condition
    for (int i = 0; i < count; i++) {
        if (modPow(g, phi_n / factors[i], n) == 1) {
            printf("%d is NOT a primitive root of %d\n", g, n);
            return 0;
        }
    }

    printf("%d IS a primitive root of %d\n", g, n);
    return 0;
}
