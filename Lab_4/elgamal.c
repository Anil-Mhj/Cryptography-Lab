// c program to implement elgamal cryptographic system
#include <stdio.h>

// Function for modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}

// Function to find modular inverse (brute force)
long long modInverse(long long a, long long mod) {
    long long x;
    for (x = 1; x < mod; x++) {
        if ((a * x) % mod == 1)
            return x;
    }
    return -1;
}

int main() {
    long long p, g, x , y, k , m , c1, c2, s, s_inv;

    // Input public parameters
    printf("Enter a prime number (p): ");
    scanf("%lld", &p);

    printf("Enter a primitive root of %lld (g): ", p);
    scanf("%lld", &g);

    // Private key
    printf("Enter private key (x): ");
    scanf("%lld", &x);

    // Public key calculation
    y = modExp(g, x, p);

    printf("\nPublic key (y): %lld\n", y);

    // Message and random number
    printf("Enter message (m < %lld): ", p);
    scanf("%lld", &m);

    printf("Enter random number (k): ");
    scanf("%lld", &k);

    // Encryption
    c1 = modExp(g, k, p);
    s  = modExp(y, k, p);
    c2 = (m * s) % p;

    printf("\nEncrypted message:");
    printf("\nc1 = %lld", c1);
    printf("\nc2 = %lld\n", c2);

    // Decryption
    s = modExp(c1, x, p);
    s_inv = modInverse(s, p);
    m = (c2 * s_inv) % p;

    printf("\nDecrypted message: %lld\n", m);

    return 0;
}
