#include <stdlib.h>
#include <stdio.h>

void tri_decroissant(int *tab, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (*(tab + i) < *(tab + j))
            {
                int tmp = *(tab + i);
                *(tab + i) = *(tab + j);
                *(tab + j) = tmp;
            }
        }
    }
}

int main()
{
    int tab[] = {1, 2, 3, 4, 5};
    tri_decroissant(tab, 5);
    
    for(int i = 0; i < 5; i++) {
        printf("%d ", *(tab + i));
    }
    printf("\n");
    
    return 0;
}