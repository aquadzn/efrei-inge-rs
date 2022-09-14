#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int puissance(int a, int p) {
    int res = 1;
    for(int i = 0; i < p; i++) {
        res *= a;
    }

    return res;
}

void is_a_number() {
    int nbr;
    printf("Ecrire un nombre: ");
    if (scanf("%d", &nbr) == 1) {
        printf("C'est un nombre\n");
    } else {
        printf("Erreur\n");
    }
}

int valeur_presente(int tab[], int len, int valeur) {
    for (int i = 0; i < len; i++) {
        if (tab[i] == valeur) {
            return i;
        }
    }
    return -1;
}

int occurences_caractere(char str[], char c) {
    char *e = str;
    int occurences = 0;

    while (*e != '\0') {
        if (c == *e) {
            occurences++;
        }
        e++;
    }
    return occurences;
}

void table_valeurs_f(int x) {
    printf("X\tF(X)\n");
    for(double i = 1; i <= x; i++) {
        double y = sin(i) + log(i) - sqrt(i);
        printf("%.0f\t%f\n", i, y);
    }
}

int main() {
    // printf("%d\n", min(4, 3));
    // printf("%d\n", max(4, 3));
    // printf("%d\n", puissance(2, 3));
    // is_a_number();
    // int tab[] = {3, 7, 2, 6};
    // printf("%d\n", valeur_presente(tab, 4, 7));
    // printf("Caractère %c est présent %d fois\n", 'o', occurences_caractere("bonjour", 'o'));
    table_valeurs_f(10);

    return 0;
}