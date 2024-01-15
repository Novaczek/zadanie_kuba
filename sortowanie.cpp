#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
void wypelnijTab(int tablica[], int rozmiar) {
    srand(time(NULL));
    for (int i = 0; i < rozmiar; ++i) {
        tablica[i] = rand() % 100;
    }
}

void drukujTab(int tablica[], int rozmiar) {
    for (int i = 0; i < rozmiar; ++i) {
        std::cout << tablica[i] << " ";
    }
    std::cout << std::endl;
}

void sortowanie_babelkowe(int tablica[], int rozmiar) {
    for (int i = 0; i < rozmiar - 1; ++i) {
        for (int j = 0; j < rozmiar - i - 1; ++j) {
            if (tablica[j] > tablica[j + 1]) {
                std::swap(tablica[j], tablica[j + 1]);
            }
        }
    }
}

void scal(int tablica[], int lewy, int srodek, int prawy) {
  int n1 = srodek - lewy + 1;
    int n2 = prawy - srodek;

    int* L = new int[n1];
    int* R = new int[n2];

    std::copy(tablica + lewy, tablica + lewy + n1, L);
    std::copy(tablica + srodek + 1, tablica + srodek + 1 + n2, R);

    int i = 0, j = 0, k = lewy;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            tablica[k++] = L[i++];
        } else {
            tablica[k++] = R[j++];
        }
    }

    while (i < n1) {
        tablica[k++] = L[i++];
    }

    while (j < n2) {
        tablica[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}  


void sortowanie_przez_scalanie(int tablica[], int lewy, int prawy) {
    if (lewy < prawy) {
        int srodek = lewy + (prawy - lewy) / 2;

        sortowanie_przez_scalanie(tablica, lewy, srodek);
        sortowanie_przez_scalanie(tablica, srodek + 1, prawy);

        scal(tablica, lewy, srodek, prawy);
    }
}

int main() {
    const int n = 10;
    int tablica[n];

    wypelnijTab(tablica, n);
    std::cout << "Przed sort babelkowe: ";
    drukujTab(tablica, n);

    sortowanie_babelkowe(tablica, n);
    std::cout << "Po sort babelkowe: ";
    drukujTab(tablica, n);

    wypelnijTab(tablica, n);
    std::cout << "Przed sort przez scalanie: ";
    drukujTab(tablica, n);

    sortowanie_przez_scalanie(tablica, 0, n - 1);
    std::cout << "Po sort przez scalanie: ";
    drukujTab(tablica, n);

    return 0;
}