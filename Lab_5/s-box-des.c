// c program to illustrate functioning of s-box of des
#include <stdio.h>

// DES S-Box 1
int S1[4][16] = {
    {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
    {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
    {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
    {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}};

// Convert binary array to decimal
int binToDec(int bin[], int size)
{
    int dec = 0;
    for (int i = 0; i < size; i++)
    {
        dec = dec * 2 + bin[i];
    }
    return dec;
}

int main()
{
    int input[6];

    printf("Enter 6-bit input (space separated bits): ");
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &input[i]);
    }

    // Row = first and last bit
    int rowBits[2] = {input[0], input[5]};
    int row = binToDec(rowBits, 2);

    // Column = middle four bits
    int colBits[4] = {input[1], input[2], input[3], input[4]};
    int col = binToDec(colBits, 4);

    // Lookup S-Box
    int result = S1[row][col];

    printf("\nRow = %d, Column = %d\n", row, col);
    printf("S-Box Output (decimal) = %d\n", result);

    // Convert result to 4-bit binary
    printf("S-Box Output (binary) = ");
    for (int i = 3; i >= 0; i--)
    {
        printf("%d", (result >> i) & 1);
    }
    printf("\n");

    return 0;
}
