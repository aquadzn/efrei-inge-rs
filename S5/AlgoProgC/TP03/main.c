#include <stdlib.h>
#include <stdio.h>

void afficher_tableau()
{
    int tab[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
    for (int i = 4; i >= 0; i--)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void statistiques()
{
    int tab[5];
    printf("Remplir tableau:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }
    int max = tab[0];
    int min = tab[0];
    int somme = tab[0];
    for (int i = 1; i < 5; i++)
    {
        if (tab[i] > max)
        {
            max = tab[i];
        }
        if (tab[i] < min)
        {
            min = tab[i];
        }
        somme += tab[i];
    }
    printf("min: %d\tmax: %d\tmoyenne: %d\n", min, max, somme / 5);
}

void lettre_perdue()
{
    char tab[1000];
    for (int i = 0; i < 1000; i++)
    {
        tab[i] = 'A' + (random() % 26);
    }
    char c;
    printf("Saisir une lettre majuscule (A-Z) : ");
    scanf("%c", &c);

    int occurences = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (tab[i] == c)
        {
            occurences++;
        }
    }
    if (occurences == 0)
    {
        printf("Aucune occurence de %c\n", c);
    }
    else
    {
        printf("%d occurences de %c\n", occurences, c);
    }
}

void matrice_unitaire()
{
    int tab[4][4];
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if (i == j) {
                tab[i][j] = 1;
            } else {
                tab[i][j] = 0;
            }
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

void additionner_matrice()
{
    int tab1[3][2] = {{1, 3}, {1, 0}, {1, 2}};
    int tab2[3][2] = {{0, 0}, {7, 5}, {2, 1}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", tab1[i][j] + tab2[i][j]);
        }
        printf("\n");
    }
}

void tableau_char_vers_string()
{
    char chaine[] = {'S', 'a', 'l', 'u', 't', ' ', 'l', 'e', 's', ' ', 'c', 'o', 'd', 'e', 'u', 'r', 's', '!'};
    char str[19];
    for (int i = 0; i < 18; i++)
    {
        str[i] = chaine[i];
    }
    str[18] = '\0';
    printf("%s\n", str);
}

void carte_identite()
{
    int jj, mm, aa;
    char nom[20], prenom[20], couleur[20];

    printf("Donnez les infos suivantes:\n");
    printf("Date de naissance (jj/mm/AA) : ");
    scanf("%d/%d/%d", &jj, &mm, &aa);
    printf("Nom : ");
    scanf("%s", nom);
    printf("Prénom : ");
    scanf("%s", prenom); 
    printf("Couleur des yeux : ");
    scanf("%s", couleur);
    printf("Vous vous appelez %s %s, vous êtes né le %d/%d/%d et vos yeux sont %s\n", prenom, nom, jj, mm, aa, couleur);
}

void majuscules()
{
    char str[100];
    printf("Entrez une phrase: ");
    fgets(str, sizeof(str), stdin);

    int taille = 0;
    while (str[taille] != '\n') {
        taille++;
    }
    str[taille] = '\0';

    for(int j = 0; j < taille; j++) {
        if(str[j] >= 'a' && str[j] <= 'z') {
            printf("%c", str[j] - 32);
        } else {
            printf("%c", str[j]);
        }
    }
    printf("\n");
}

void mirroir() {
    char str[100];
    printf("Entrez une phrase: ");
    fgets(str, sizeof(str), stdin);

    int taille = 0;
    while (str[taille] != '\n') {
        taille++;
    }
    str[taille] = '\0';

    printf("%s | ", str);
    for(int i = taille; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void mot_de_passe() {
    char mdp[9];
    printf("Entrez un mot de passe: ");
    scanf("%8s", mdp);
    mdp[8] = '\0';

    int majuscule = 1;
    int caractere_special = 1;
    int chiffre = 1;
    int longueur_mdp = 1;

    int taille = 0;
    while (mdp[taille] != '\0') {
        if (mdp[taille] >= 'A' && mdp[taille] <= 'Z') {
            
        }

        taille++;
    }
    
    printf("%d\n", taille);
}

void longueur_chaine() {
    char str[100];
    printf("Entrez une phrase: ");
    fgets(str, sizeof(str), stdin);

    int taille = 0;
    while (str[taille] != '\n') {
        taille++;
    }

    printf("Longueur: %d\n", taille);
}

void codeur() {
    char codeur[] = "CODEUR";
    char str[100];

    printf("Entrez une phrase: ");
    fgets(str, sizeof(str), stdin);

    int taille = 0;
    while (str[taille] != '\n') {
        taille++;
    }
    str[taille] = '\0';

    if (taille == 6) {
        for(int i = 0; i < 6; i++) {
            if (str[i] != codeur[i]) {
                printf("%s != %s\n", str, codeur);
                return ;
            }
        }
        printf("%s == %s\n", str, codeur);
    } else if (taille > 6) {
        printf("%s > %s\n", str, codeur);
    } else {
        printf("%s < %s\n", str, codeur);
    }
}

int main()
{
    // afficher_tableau();
    // statistiques();
    // lettre_perdue();
    // matrice_unitaire();
    // additionner_matrice();
    // tableau_char_vers_string();
    // carte_identite();
    // majuscules();
    // mirroir();
    // mot_de_passe();
    // longueur_chaine();
    // codeur();

    return 0;
}