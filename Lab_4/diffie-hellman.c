// c program to implement diffie hellman exchange
#include <stdio.h>

// Function to perform modular exponentiation
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        exp = exp >> 1;
        base = (base * base) % mod;
    }

    return result;
}

int main() {
    long long p, g;   
    long long a, b;  
    long long A, B; 
    long long keyA, keyB;

    // Input public parameters
    printf("Enter a prime number (p): ");
    scanf("%lld", &p);

    printf("Enter a primitive root of %lld (g): ", p);
    scanf("%lld", &g);

    // Input private keys
    printf("Enter private key for Alice (a): ");
    scanf("%lld", &a);

    printf("Enter private key for Bob (b): ");
    scanf("%lld", &b);

    // Calculate public keys
    A = mod_exp(g, a, p);
    B = mod_exp(g, b, p);

    printf("\nAlice's public key (A): %lld", A);
    printf("\nBob's public key (B): %lld\n", B);

    // Calculate shared secret keys
    keyA = mod_exp(B, a, p);
    keyB = mod_exp(A, b, p); 

    printf("\nShared secret key computed by Alice: %lld", keyA);
    printf("\nShared secret key computed by Bob:   %lld\n", keyB);

    return 0;
}
