#include <iostream>

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

namespace fonctions
{
    namespace arithmetique
    {
        double addition(double a, double b)
        {
            return a + b;
        }
        double multiplication(double a, double b)
        {
            return a * b;
        }
        double division(double a, double b)
        {
            return a / b;
        }
        double soustraction(double a, double b)
        {
            return a - b;
        }
    }

    namespace logique
    {
        bool et(double a, double b)
        {
            return a && b;
        }
        bool ou(double a, double b)
        {
            return a || b;
        }
    }
}

void nb_occurences()
{
    int tab[10];
    int max = 0;
    int occurences = 0;

    for (int i = 0; i < 10; i++)
    {
        std::cout << "Entrez note " << i + 1 << ": ";
        std::cin >> tab[i];
        if (tab[i] > max)
        {
            max = tab[i];
            occurences = 0;
        }
        if (tab[i] == max)
        {
            occurences++;
        }
    }

    std::cout << "Nombre d'occurences de " << max << ": " << occurences << '\n';
}

void decalage_tableau() {
    int n = 10;
    int tab[n];
    int V, i;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Entrez élément " << i + 1 << ": ";
        std::cin >> tab[i];
    }

    std::cout << "Entrez V: ";
    std::cin >> V;
    std::cout << "Entrez i (0..9): ";
    std::cin >> i;

    if (i < 0 || i > 9) {
        std::cout << "i n'est pas compris entre 0 et 9\n";
        exit(EXIT_FAILURE);
    }

    for(int j = n - 1 ; j > i; j--) {
        tab[j] = tab[j - 1];
    }
    tab[i] = V;

    for(int j = 0; j < n; j++) {
        std::cout << tab[j] << ' ';
    }
    std::cout << '\n';
}

void tri_insertion(int tab[]) {

}

int main()
{
    // 1.
    // int a = 10;
    // int b = 20;
    // std::cout << "A: " << a << " - B: " << b << '\n';
    // swap(a, b);
    // std::cout << "Après swap:\n";
    // std::cout << "A: " << a << " - B: " << b << '\n';

    // 2.
    // namespace ar = fonctions::arithmetique;
    // namespace log = fonctions::logique;

    // std::cout << ar::multiplication(3, 7) << '\n';
    // std::cout << log::et(3, 3) << '\n';

    // 3.
    // nb_occurences();

    // 4.
    // decalage_tableau();

    // 5.
    // int tab[] = {4, 2, 8, 1, 6, 9, 5};
    // tri_insertion(tab);

    return 0;
}