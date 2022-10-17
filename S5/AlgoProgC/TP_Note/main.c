#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_LIGNES 15
#define N_COLS 7
#define N_OCCURENCES 9
#define MAX_OCCURENCES 3
#define TRUE 1
#define FALSE 0

int **saisir_mat(int n)
{
    printf("[Saisie de matrice %dx%d]\n", n, n);
    int **mat = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        mat[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            printf("x%dy%d: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("--------------------\n");

    return mat;
}

int **generer_mat()
{
    printf("[Génération de matrice %dx%d]\n", N_LIGNES, N_COLS);
    int **tab = malloc(N_LIGNES * sizeof(int *));
    for (int i = 0; i < N_LIGNES; i++)
    {
        tab[i] = malloc(N_COLS * sizeof(int));
        for (int j = 0; j < N_COLS; j++)
        {
            tab[i][j] = (rand() % N_OCCURENCES) + 1;
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    printf("--------------------\n");

    return tab;
}

void afficher_mat(int **mat, int l, int c)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == -1)
            {
                printf("_ ");
            }
            else
            {
                printf("%d ", mat[i][j]);
            }
        }
        printf("\n");
    }
    printf("--------------------\n");
}

void liberer_mat(int **mat, int l, int c)
{
    for (int i = 0; i < l; i++)
    {
        free(mat[i]);
    }
    free(mat);
}

void supprimer_element(int *mat_l, int n, int pos) {
    if(pos <= n) {
        for(int i = pos; i < n - 1; i++) {
            mat_l[i] = mat_l[i + 1];
        }
    }
}

int somme(int tab[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += tab[i];
    }
    return sum;
}

void afficher_booleen(int bool)
{
    (bool == 0) ? printf("faux\n") : printf("vrai\n");
}

int *ex1_nb_occurences(int **tab)
{
    printf("[Occurences]\n");

    // Tableau d'occurences pour les N_OCCURENCES valeurs
    int *occurences = calloc(N_OCCURENCES, sizeof(int));

    for (int n = 1; n <= N_OCCURENCES; n++)
    {
        int occ = 0;
        for (int i = 0; i < N_LIGNES; i++)
        {
            for (int j = 0; j < N_COLS; j++)
            {
                if (tab[i][j] == n)
                {
                    occ++;
                }
            }
        }
        occurences[n - 1] = occ;
        printf("%d : %d occurence(s)\n", n, occ);
    }
    printf("--------------------\n");

    return occurences;
}

void ex1_tri_decroissant(int **tab)
{
    printf("[Tri décroissant]\n");
    for (int i = 0; i < N_LIGNES; i++)
    {
        for (int j = 0; j < N_COLS; j++)
        {
            for (int k = j + 1; k < N_COLS; k++)
            {
                if (tab[i][j] < tab[i][k])
                {
                    int tmp = tab[i][j];
                    tab[i][j] = tab[i][k];
                    tab[i][k] = tmp;
                }
            }
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    printf("--------------------\n");
}

void ex1_sup_occurence(int **tab, int *occurences)
{
    printf("[Supprimer occurences]\n");
    for (int n = 1; n <= N_OCCURENCES; n++)
    {
        if (occurences[n - 1] <= MAX_OCCURENCES)
        {
            for (int i = 0; i < N_LIGNES; i++)
            {
                for (int j = 0; j < N_COLS; j++)
                {
                    if (tab[i][j] == n)
                    {
                        // supprimer_element(tab[i], N_COLS, j);
                        tab[i][j] = -1;
                    }
                }
            }
        }
    }
}

void ex1()
{
    int **mat = generer_mat();
    int *occurences = ex1_nb_occurences(mat);
    ex1_tri_decroissant(mat);
    ex1_sup_occurence(mat, occurences);
    afficher_mat(mat, N_LIGNES, N_COLS);

    free(occurences);
    liberer_mat(mat, N_LIGNES, N_COLS);
}

int ex2_carre_magique(int **mat, int n)
{
    // Somme diagonales
    int sum_diag_g = 0;
    int sum_diag_d = 0;
    for (int i = 0; i < n; i++)
    {
        sum_diag_g += mat[i][i];
        sum_diag_d += mat[i][n - i - 1];
    }
    if (sum_diag_g != sum_diag_d)
    {
        return FALSE;
    }

    // Somme lignes et colonnes
    for (int i = 0; i < n; i++)
    {
        int sum_l = 0;
        int sum_c = 0;
        for (int j = 0; j < n; j++)
        {
            sum_l += mat[i][j];
            sum_c += mat[j][i];
        }

        if (sum_l != sum_c || sum_l != sum_diag_g)
        {
            return FALSE;
        }
    }

    return TRUE;
}

int ex2_carre_magique_parfait(int **mat, int n)
{
    int limit = n * n;
    if (ex2_carre_magique(mat, n) == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] < 1 || mat[i][j] > limit)
                {
                    return FALSE;
                }
            }
        }

        return TRUE;
    }

    return FALSE;
}

void ex2()
{
    int N_MATRICE_CARRE;
    printf("Taille n de la matrice: ");
    scanf("%d", &N_MATRICE_CARRE);
    printf("--------------------\n");

    int **mat = saisir_mat(N_MATRICE_CARRE);
    afficher_mat(mat, N_MATRICE_CARRE, N_MATRICE_CARRE);

    printf("Carré magique: ");
    afficher_booleen(ex2_carre_magique(mat, N_MATRICE_CARRE));

    printf("Carré magique parfait: ");
    afficher_booleen(ex2_carre_magique_parfait(mat, N_MATRICE_CARRE));

    liberer_mat(mat, N_MATRICE_CARRE, N_MATRICE_CARRE);
}

int main()
{
    srand(time(NULL));

    ex1();
    ex2();

    return FALSE;
}