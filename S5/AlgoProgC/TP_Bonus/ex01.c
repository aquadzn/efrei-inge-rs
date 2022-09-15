#include <stdlib.h>
#include <stdio.h>

void ex01() {
    for (int i = 100; i <= 500; i++) {
        int nb = i;
        int reste;
        int somme = 0;

        while (nb != 0) {
            reste = nb % 10;
            somme += reste * reste * reste;
            nb /= 10;
        }

        if (somme == i) {
            printf("%d Armstrong\n", i);
        }
    }
}

int main() {
    ex01();
    
    return 0;
}