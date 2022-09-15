#include <stdlib.h>
#include <stdio.h>

int estParfait(int nb) {
    int somme = 0;
    for(int i = 1; i < nb; i++) {
        if (nb % i == 0) {
            somme += i;
        }
    }
    
    if (somme == nb) {
        return 1;
    }
    return 0;
}

int main() {
    int a, b;
    printf("Saisir un intervalle\n");
    printf("Borne inf: ");
    scanf("%d", &a);
    printf("Borne sup: ");
    scanf("%d", &b);

    for(int i = a; i <= b; i++) {
        if (estParfait(i) == 1) {
            printf("%d est parfait\n", i);
        }
    }

    return 0;
}