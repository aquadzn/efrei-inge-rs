#include <stdlib.h>
#include <stdio.h>

int estPremier(int nb) {
    if (nb == 2) {
        return 1;
    } else if (nb < 2) {
        return 0;
    } else {
        for(int i = 2; i < nb; i++) {
            if (nb % i == 0) {
                return 0;
            }
        }
        return 1;
    }
}

int main() {
    int a, b;
    printf("Saisir un intervalle\n");
    printf("Borne inf: ");
    scanf("%d", &a);
    printf("Borne sup: ");
    scanf("%d", &b);
    
    for(int i = a; i <= b; i++) {
        if (estPremier(i) == 1) {
            printf("%d est premier\n", i);
        }
    }

    return 0;
}