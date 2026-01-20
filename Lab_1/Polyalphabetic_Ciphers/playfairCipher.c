#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char key[50], text[100], p[200], c[200], m[5][5];
    int used[26] = {0}, i, j, k = 0, r1, c1, r2, c2;

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    /* Key Matrix */
    for (i = 0; i < strlen(key); i++)
    {
        char ch = toupper(key[i]);
        if (ch == 'J')
            ch = 'I';
        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A'])
        {
            m[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        if (ch != 'J' && !used[ch - 'A'])
        {
            m[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    /* Prepare text */
    for (i = 0, j = 0; i < strlen(text); i++)
        if (isalpha(text[i]))
            p[j++] = toupper(text[i]);
    p[j] = '\0';

    for (i = 0; p[i]; i += 2)
    {
        if (p[i] == p[i + 1])
        {
            memmove(&p[i + 2], &p[i + 1], strlen(p) - i);
            p[i + 1] = 'X';
        }
    }
    if (strlen(p) % 2)
        strcat(p, "X");

    /* Encrypt */
    for (i = 0; p[i]; i += 2)
    {
        for (j = 0; j < 5; j++)
            for (k = 0; k < 5; k++)
            {
                if (m[j][k] == p[i])
                {
                    r1 = j;
                    c1 = k;
                }
                if (m[j][k] == p[i + 1])
                {
                    r2 = j;
                    c2 = k;
                }
            }

        if (r1 == r2)
        {
            c[i] = m[r1][(c1 + 1) % 5];
            c[i + 1] = m[r2][(c2 + 1) % 5];
        }
        else if (c1 == c2)
        {
            c[i] = m[(r1 + 1) % 5][c1];
            c[i + 1] = m[(r2 + 1) % 5][c2];
        }
        else
        {
            c[i] = m[r1][c2];
            c[i + 1] = m[r2][c1];
        }
    }
    c[i] = '\0';

    printf("\nCipher Text: %s\n", c);
    return 0;
}
