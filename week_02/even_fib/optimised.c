#include <stdio.h>

int  sum(int n) {
    int a = 2, b = 8, sum = 0;
    while (a <= n) {
        sum += a;
        int c = 4*b + a;
        a = b;
        b = c;
    }
    return sum;
}

int main() {
    int n = 50;
    printf("%d\n", sum(n));
    return 0;
}
