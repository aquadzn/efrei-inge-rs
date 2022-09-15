#include <stdlib.h>
#include <stdio.h>

void n1_n2(int n) {
    int *tab = malloc(0);
    int count = 0;

    while (n) {
        tab[count++] = n % 10;
        tab = realloc(tab, count * sizeof(int));
        n /= 10;
    }
    
    printf("N1 = ");
    for(int i = count; i >= 0; i--) {
        if (tab[i] % 2 == 0) {
            printf("%d", tab[i]);
        }
    }
    printf("\t");
    
    printf("N2 = ");
    for(int i = count; i >= 0; i--) {
        if (tab[i] % 2 != 0) {
            printf("%d", tab[i]);
        }
    }
    printf("\n");
}

int main() {
    n1_n2(32687451);

    return 0;
}