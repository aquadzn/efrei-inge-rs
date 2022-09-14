#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void ex_1() {
    char c = 'A';
    printf("Informations sur ma variable:\n");
    printf("\ttype: char\n");
    printf("\ttaille: %lu octet\n", sizeof(c));
    printf("\tcontenu: %c\n", c);
    printf("\tadresse: %p\n", &c);
}

void ex_2() {
    int a;
    int *ptr_a = &a;

    printf("Donnez un entier: ");
    scanf("%d", ptr_a);

    printf("Valeur %d stockée à %p\n", a, &a);
}

void ex_3() {
    char prenom = 'A', nom = 'Z';
    char *ptr_prenom = &prenom;
    char *ptr_nom = &nom;

    printf("Vos initiales %c.%c\n", prenom, nom);

    int tmp = *ptr_prenom;
    *ptr_prenom = *ptr_nom;
    *ptr_nom = tmp;

    printf("Vos initiales %c.%c\n", prenom, nom);
}

void ex_4() {
    int age = 23;
    int *ptr_age = &age;

    printf("Quel est votre âge ? : ");
    scanf("%d", ptr_age);

    printf("Vous avez %d ans\n", age);
}

void ex_5() {
    char str[100];
    printf("Entrez une phrase: ");
    fgets(str, sizeof(str), stdin);

    char *ptr_str = str;
    int len = 0;
    while (*ptr_str != '\0') {
        len++;
        ptr_str++;
    }

    printf("Longueur (en comptant saut de ligne): %d\n", len);
}

void ex_6() {
    srand(time(NULL));
    int len = rand() % 10;

    int tab[len];
    printf("Tableau: ");
    for (int i = 0; i < len; i++) {
        tab[i] = rand() % 10;
        printf("%d ", tab[i]);
    }
    printf("\n");

    int somme = 0;
    int *ptr_tab = tab;
    for(int i = 0; i < len; i++) {
        somme += *ptr_tab;
        ptr_tab++;
    }

    printf("Somme : %d\n", somme);
}

int main() {
    // ex_1();
    // ex_2();
    // ex_3();
    // ex_4();
    // ex_5();
    ex_6();

    return 0;
}