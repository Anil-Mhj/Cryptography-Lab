// c program to implement vigerene cipher

#include <stdio.h>
#include <string.h>

int main()
{
    char plaintext[100], key[100], ciphertext[100];
    int i, p, k;
    printf("Enter plaintext (uppercase):");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter key (uppercase):");
    scanf("%s", key);
    int textLen = strlen(plaintext);
    int keyLen = strlen(key);
    for (i = 0; i < textLen; i++)
    {
        p = plaintext[i] - 'A';
        k = key[i % keyLen] - 'A';
        ciphertext[i] = (p + k) % 26 + 'A';
    }
    ciphertext[i] = '\0';
    printf("Encrypted text: %s \n", ciphertext);
    return 0;
}