#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"

void majorite()
{
    int age;
    printf("Quel est votre âge ? : ");
    scanf("%d", &age);

    if (age > 17)
    {
        printf("Vous êtes majeur\n");
    }
    else
    {
        printf("Vous êtes mineur\n");
    }
}

void compte_a_rebours()
{
    int decompte;
    printf("Nombre pour compte à rebours : ");
    scanf("%d", &decompte);

    for (int i = decompte; i > 0; i--)
    {
        printf("%d\n", i);
    }
    printf("BOOM\n");
}

void comparaison_nombres()
{
    int a, b;
    printf("Entrez deux nombres\n");
    printf("Nb 1: ");
    scanf("%d", &a);
    printf("Nb 2: ");
    scanf("%d", &b);

    if (a == b || b == a)
    {
        printf("Nombres égaux\n");
    }
    else
    {
        if (a > b)
        {
            printf("%d est supérieur à %d\n", a, b);
        }
        else
        {
            printf("%d est inférieur à %d\n", a, b);
        }
    }
}

void jours_de_la_semaine()
{
    int jour;
    printf("Donnez un numéro de jour de la semaine (1-7) : ");
    scanf("%d", &jour);

    switch (jour)
    {
    case 1:
        printf("Lundi\n");
        break;
    case 2:
        printf("Mardi\n");
        break;
    case 3:
        printf("Mercredi\n");
        break;
    case 4:
        printf("Jeudi\n");
        break;
    case 5:
        printf("Vendredi\n");
        break;
    case 6:
        printf("Samedi\n");
        break;
    case 7:
        printf("Dimanche\n");
        break;
    default:
        printf("Jour invalide\n");
        break;
    }
}

void code_pin()
{
    int pin;
    int code_a_trouver = 0;

    int tentatives = 3;
    while (tentatives > 0)
    {
        tentatives--;
        printf("Code PIN: ");
        scanf("%d", &pin);
        if (pin == code_a_trouver)
        {
            printf("Téléphone dévérouillé\n");
            break;
        }
        else
        {
            printf("Erreur, il reste %d tentative(s)\n", tentatives);
        }
    }
}

void pair_ou_impair()
{
    int nb;
    printf("Entrez un nombre: ");
    scanf("%d", &nb);
    (nb % 2 == 0) ? printf("Pair\n") : printf("Impair\n");
}

void nombre_premier()
{
    int nb;
    printf("Entrez un nombre: ");
    scanf("%d", &nb);

    int estPremier = 0;
    if (nb < 2)
    {
        estPremier = -1;
    }
    else
    {
        for (int i = 2; i < nb; i++)
        {
            if (nb % i == 0)
            {
                estPremier = -1;
                break;
            }
        }
    }

    if (estPremier == 0)
    {
        printf("%d est premier\n", nb);
    }
    else
    {
        printf("%d n'est pas premier\n", nb);
    }
}

void conversion_de_date()
{
    int jour, mois, annee;
    printf("Entrez une date (jj/mm/AA) : ");
    scanf("%d/%d/%d", &jour, &mois, &annee);

    printf("%d ", jour);
    switch (mois)
    {
    case 1:
        printf("janvier ");
        break;
    case 2:
        printf("février ");
        break;
    case 3:
        printf("mars ");
        break;
    case 4:
        printf("avril ");
        break;
    case 5:
        printf("mai ");
        break;
    case 6:
        printf("juin ");
        break;
    case 7:
        printf("juillet ");
        break;
    case 8:
        printf("août ");
        break;
    case 9:
        printf("septembre ");
        break;
    case 10:
        printf("octobre ");
        break;
    case 11:
        printf("novembre ");
        break;
    case 12:
        printf("décembre ");
        break;
    default:
        printf("mois invalide\n");
        exit(-1);
        break;
    }
    printf("%d\n", annee);
}

void table_multiplication()
{
    int nb;
    printf("Table de multiplication à afficher : ");
    scanf("%d", &nb);

    for (int table = 0; table < nb; table++)
    {
        printf("Table de multiplication de %d\n", table);
        for (int i = 0; i <= 10; i++)
        {
            printf("%d x %d = %d\n", nb, i, nb * i);
        }
        printf("\n");
    }
}

void triangle_des_etoiles()
{
    int hauteur;
    printf("Nombre de lignes [3-10] : ");
    scanf("%d", &hauteur);

    if (hauteur < 3 || hauteur > 10)
    {
        printf("[3-10]\n");
        exit(-1);
    }
    else
    {
        for (int ligne = 1; ligne <= hauteur; ligne++)
        {
            for (int colonne = 1; colonne <= hauteur - ligne; colonne++)
            {
                printf(" ");
            }
            for (int colonne = 1; colonne <= 2 * ligne - 1; colonne++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
}

void factorielle()
{
    int nb;
    printf("Calculer la factorielle de : ");
    scanf("%d", &nb);

    int f = 1;
    for (int i = 1; i <= nb; i++)
    {
        f *= i;
    }

    printf("Factorielle de %d = %d\n", nb, f);
}

void calculatrice()
{
    int a, b;
    char operateur;
    printf("Entrez une opération: ");
    scanf("%d%c%d", &a, &operateur, &b);

    int res;
    int operateur_valide = 0;
    while (operateur_valide == 0)
    {
        switch (operateur)
        {
        case '%':
            res = a % b;
            operateur_valide = 1;
            break;
        case '+':
            res = a + b;
            operateur_valide = 1;
            break;
        case '-':
            res = a - b;
            operateur_valide = 1;
            break;
        case '*':
            res = a * b;
            operateur_valide = 1;
            break;
        case '/':
            if (b == 0)
            {
                printf("Erreur, division par 0 impossible!\n");
                printf("Entrez une opération: ");
                scanf("%d%c%d", &a, &operateur, &b);
            }
            else
            {
                res = a / b;
                operateur_valide = 1;
            }
            break;
        default:
            printf("Erreur d'opérateur\n");
            printf("Réessayez avec un opérateur valide: ");
            scanf("%d%c%d", &a, &operateur, &b);
            break;
        }
    }
    printf("Résultat:\n\t%d %c %d = ", a, operateur, b);
    printf("%d\n", res);
}
