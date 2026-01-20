// write a program to illustrate monoalphabetic cipher
// Ceasar cipher

#include <stdio.h>
#include <string.h>

int main()
{
    char text[100], ch;
    int key;
    printf("Enter the message (Uppercase):");
    fgets(text, sizeof(text), stdin);
    printf("Enter the key:");
    scanf("%d", &key);
    for (int i = 0; text[i] != '\0'; i++)
    {
        ch = text[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = (ch - 'A' + key) % 26 + 'A';
        }
        text[i] = ch;
    }
    printf("Decrypted text: %s", text);
    return 0;
}