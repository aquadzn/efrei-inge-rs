#include <stdlib.h>
#include <stdio.h>

int factorielle(int n) {
    if (n >= 1) {
        return n * factorielle(n - 1);
    } else {
        return 1;
    }
}

int main() {
    int n = 5;
    printf("La factorielle de %d est %d\n", n, factorielle(n));

    return 0;
}