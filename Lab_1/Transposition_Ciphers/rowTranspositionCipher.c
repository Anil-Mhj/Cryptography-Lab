#include <stdio.h>
#include <string.h>

int main()
{
    char text[100], cipher[100];
    int key[10], order[10];
    char matrix[10][10];
    int i, j, k = 0;
    int cols, rows, len;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter key sequence:\n");
    for (i = 0; i < cols; i++)
        scanf("%d", &key[i]);

    /* Remove spaces and newline */
    char temp[100];
    k = 0;
    for (i = 0; text[i]; i++)
        if (text[i] != ' ' && text[i] != '\n')
            temp[k++] = text[i];
    temp[k] = '\0';
    strcpy(text, temp);

    len = strlen(text);
    rows = len / cols;
    if (len % cols != 0)
        rows++;

    /* Fill matrix row-wise */
    k = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (k < len)
                matrix[i][j] = text[k++];
            else
                matrix[i][j] = 'x';  // padding character
        }
    }

    /* Determine column reading order */
    for (i = 0; i < cols; i++)
        order[key[i] - 1] = i;

    /* Read columns in correct order */
    k = 0;
    for (i = 0; i < cols; i++) {
        int col = order[i];
        for (j = 0; j < rows; j++)
            cipher[k++] = matrix[j][col];
    }
    cipher[k] = '\0';

    printf("Cipher Text: %s\n", cipher);
    return 0;
}
