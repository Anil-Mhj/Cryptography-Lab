// c program to implement Rail Fence Cipher
#include <stdio.h>
#include <string.h>

int main()
{
    char text[100], rail[10][100];
    int i, j, k = 0;
    int row = 0, dir = 1;
    int rails;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter number of rails: ");
    scanf("%d", &rails);

    // remove spaces and newlines from text
    char temp[100];
    k = 0;
    for (i = 0; text[i]; i++)
    {
        if (text[i] != ' ' && text[i] != '\n')
        {
            temp[k++] = text[i];
        }
    }
    temp[k] = '\0';
    strcpy(text, temp);

    // Initialize rail matrix with '\n'
    for (i = 0; i < rails; i++)
        for (j = 0; j < strlen(text); j++)
            rail[i][j] = '\n';

    // Fill the rails in zig-zag manner
    for (i = 0; i < strlen(text); i++)
    {
        rail[row][i] = text[i];

        if (row == 0)
            dir = 1;
        else if (row == rails - 1)
            dir = -1;

        row += dir;
    }

    // Read the rails row-wise to get cipher text
    printf("Cipher Text: ");
    for (i = 0; i < rails; i++)
        for (j = 0; j < strlen(text); j++)
            if (rail[i][j] != '\n')
                printf("%c", rail[i][j]);
    printf("\n");
    return 0;
}
