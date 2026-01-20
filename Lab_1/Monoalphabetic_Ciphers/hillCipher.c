// c program to implement monoalphabetic (hill cipher)

#include <stdio.h>

int main()
{
    int key[2][2], plaintext[2], ciphertext[2];
    char text[100];
    int i;
    printf("Enter 2-letter plaintext (uppercase):");
    scanf("%s", text);

    for (i = 0; i < 2; i++)
    {
        plaintext[i] = text[i] - 'A';
    }

    printf("Enter 2x2 key matrix (numbers 0-25):\n");
    for (i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &key[i][j]);
        }
    }

    for (i = 0; i < 2; i++)
    {
        ciphertext[i] = 0;
        for (int j = 0; j < 2; j++)
        {
            ciphertext[i] += key[i][j] * plaintext[j];
        }
        ciphertext[i] %= 26;
    }

    printf("Encrypted text:");
    for (i = 0; i < 2; i++)
    {
        printf("%c", ciphertext[i] + 'A');
    }
    printf("\n");
    return 0;
}