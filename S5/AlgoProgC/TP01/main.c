#include <stdio.h>
#include <stdlib.h>

void convertisseur_devise() {
    float montant;
    float taux_conversion = 0.99;

    printf("Entrez un montant en euro: ");
    scanf("%f", &montant);

    printf("\n%.2f euros --> %.2f dollars\n", montant, taux_conversion * montant);
}

void inverser_variable() {
    int var1 = 123;
    int var2 = 18;
    
    int tmp = var1;
    var1 = var2;
    var2 = tmp;

    printf("var1 = %d et var2 = %d\n", var1, var2);
}

void moyenne_somme() {
    int a, b, c;
    printf("Entrez 3 entiers séparées par des espaces: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("Somme: %d\n", a + b + c);
    printf("Moyenne: %f\n", (a + b + c) / 3.);
}

void geometrie_2d() {
    int hauteur, largeur;
    printf("Hauteur et largeur séparées par un espace: ");
    scanf("%d %d", &hauteur, &largeur);

    printf("\tPérimètre: %d\n", 2 * hauteur + 2 * largeur);
    printf("\tPérimètre: %d\n", hauteur * largeur);
}

void geometrie_3d() {
    float rayon;
    printf("Quel est le rayon du cercle: ");
    scanf("%f", &rayon);

    printf("\tDiamètre: %.2f\n", 2. * rayon);
    printf("\tCirconférence: %.2f\n", 2 * 3.14 * rayon);
    printf("\tAire: %.2f\n", 3.14 * (rayon * rayon));

    float hauteur;
    printf("Quelle est la hauteur du cyclindre: ");
    scanf("%f", &hauteur);

    printf("\tVolume: %.2f\n", 3.14 * rayon * rayon * hauteur);
}

void min_vers_maj() {
    char c;
    printf("Entrez une lettre en minuscule: ");
    scanf("%c", &c);

    printf("En majuscule: %c\n", c - 32);
}

int main() {
    // convertisseur_devise();
    // inversion_variable();
    // moyenne_somme();
    // geometrie_2d();
    // geometrie_3d();
    // min_vers_maj();

    return 0;
}