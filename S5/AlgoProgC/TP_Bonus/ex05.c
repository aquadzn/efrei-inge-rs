#include <stdlib.h>
#include <stdio.h>

int estPalindrome(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        if (tab[i] != tab[n - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int tab_pas_palindrome[] = {1, 2, 3, 4};
    int tab_palindrome[] = {1, 3, 5, 3, 1};

    if (estPalindrome(tab_pas_palindrome, 4) == 0) {
        printf("Pas palindrome\n");
    }

    if (estPalindrome(tab_palindrome, 5) == 1) {
        printf("Palindrome\n");
    }

    return 0;
}