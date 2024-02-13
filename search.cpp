//WYSZUKIWANIE LINIOWE//
#include <iostream>
using namespace std;
int wyszukiwanie_liniowe(int t[], int size, int k) {
    for (int i = 0; i < size; i++) {
        if (k == t[i]) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int t[] = {23, 3, 4, 6, 14, 11, 20, 7, 30, 15, 9, 10};
    int p;

    cout << "Podaj liczbe:" << endl;
    cin >> p;

    int result = wyszukiwanie_liniowe(t, 12, p);

    if (result >= 0) {
        cout << "Liczba " << p << " zostala znaleziona pod indexem: " << result << endl;
    } else {
        cout << "Liczba " << p << " nie zostala odnaleziona" << endl;
    }

    return 0;
}
//WYSZUKIWANIE LINIOWE Z WARTOWNIKIEM//
#include <iostream>
using namespace std;
int wyszukiwanie_liniowe_z_wart(int t[], int size, int k) {
    t[size] = k;

    int i = 0;
    
    while (t[i] != k) {
        i++;
    }

    
    if (i < size) {
        return i;
    } else {
        return -1;
    }
}

int main() {
    int t[] = {23, 3, 4, 6, 14, 11, 20, 7, 30, 15, 9, 10};
    int p;

    cout << "Podaj liczbe:" << endl;
    cin >> p;

    int result = wyszukiwanie_liniowe_z_wart(t, 12, p);

    if (result != -1) {
        cout << "Liczba " << p << " zostala znaleziona pod indexem: " << result << endl;
    } else {
        cout << "Liczba " << p << " nie zostala odnaleziona" << endl;
    }

    return 0;
}
//WYSZUKIWANIE BINARNE//
#include <iostream>
using namespace std;
int wyszukiwanie_binarne(int t[], int size, int k) {
    int l = 0;
    int h = size - 1;
    int mid;

    while (l <= h) {
        mid = (l + h) / 2;

        if (k == t[mid]) {
            return mid; 
        } else if (k > t[mid]) {
            l = mid + 1; 
        } else {
            h = mid - 1; 
        }
    }

    return -1; 
}

int main() {
    int t[] = {23, 3, 11, 5, 9, 8, 43, 78, 2, 10, 4, 13}; 
    int p;

    cout << "Podaj liczbe: " << endl;
    cin >> p;

    int result = wyszukiwanie_binarne(t, 12, p);

    if (result >= 0) {
        cout << "Liczba " << p << " zostala znaleziona pod indeksem: " << result << endl;
    } else {
        cout << "Liczba " << p << " nie zostala odnaleziona" << endl;
    }

    return 0;
}
//WYSZUKIWANIE SKOKOWE//
#include <iostream>
#include <cmath>
using namespace std;

//WYSZUKIWANIE SKOKOWE//
#include <iostream>
#include <cmath>
using namespace std;

int wyszukiwanie_skokowe(int t[], int size, int k) {
    int step = sqrt(size); 
    int prev = 0;

    while (t[min(step, size) - 1] < k) {
        prev = step;
        step += sqrt(size);

        if (prev >= size) {
            return -1; 
        }
    }

    while (t[prev] < k) {
        prev++;

        if (prev == min(step, size)) {
            return -1; 
        }
    }

    if (t[prev] == k) {
        return prev; 
    }

    return -1; 
}

int main() {
    int t[] = {2, 3, 4, 5, 8, 9, 10, 11, 13, 23, 43, 78};
    int p;

    cout << "Podaj liczbę: " << endl;
    cin >> p;

    int result = wyszukiwanie_skokowe(t, 12, p);

    if (result >= 0) {
        cout << "Liczba " << p << " została znaleziona pod indeksem: " << result << endl;
    } else {
        cout << "Liczba " << p << " nie została odnaleziona" << endl;
    }

    return 0;
}
//WYSZUKIWANIE INTERPOLACYJNE//
#include <iostream>
using namespace std;
int wyszukiwanie_interpolacyjne(int t[], int size, int k) {
    int l = 0; 
    int h = size - 1; 

    while (l <= h && k >= t[l] && k <= t[h]) {
        if (l == h) {
            if (t[l] == k) {
                return l; 
            }
            return -1; 
        }

        
        int p = l + (((double)(h - l) / (t[h] - t[l])) * (k - t[l]));

        if (t[p] == k) {
            return p; 
        }

        if (t[p] < k) {
            l = p + 1; 
        } else {
            h = p - 1; 
        }
    }

    return -1; 
}

int main() {
    int t[] = {2, 3, 4, 5, 8, 9, 10, 11, 13, 23, 43, 78};
    int p;

    cout << "Podaj liczbę: " << endl;
    cin >> p;

    int result = wyszukiwanie_interpolacyjne(t, 12, p);

    if (result >= 0) {
        cout << "Liczba " << p << " została znaleziona pod indeksem: " << result << endl;
    } else {
        cout << "Liczba " << p << " nie została odnaleziona" << endl;
    }

    return 0;
}

    return 0;
}
