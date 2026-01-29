// c program to find the totient of a number
#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n, count = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 1; i < n; i++) {
        if (gcd(i, n) == 1) {
            count++;
        }
    }

    printf("Euler's Totient (phi) value is: %d\n", count);

    return 0;
}
