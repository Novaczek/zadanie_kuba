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
    int t[] = {23, 3, 12, 5, 9};
    int p;

    cout << "Podaj liczbe:" << endl;
    cin >> p;

    int result = wyszukiwanie_liniowe(t, 5, p);

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
    int t[] = {23, 3, 12, 5, 9};
    int p;

    cout << "Podaj liczbe:" << endl;
    cin >> p;

    int result = wyszukiwanie_liniowe_z_wart(t, 5, p);

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
    int t[] = {4, 7, 12, 21, 34}; 
    int p;

    cout << "Podaj liczbe: " << endl;
    cin >> p;

    int result = wyszukiwanie_binarne(t, 5, p);

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
    int t[] = {4, 7, 12, 21, 34}; 
    int p;

    cout << "Podaj liczbe: " << endl;
    cin >> p;

    int result = wyszukiwanie_skokowe(t, 5, p);

    if (result >= 0) {
        cout << "Liczba " << p << " zostala znaleziona pod indeksem: " << result << endl;
    } else {
        cout << "Liczba " << p << " nie zostala odnaleziona" << endl;
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
    int t[] = {4, 7, 12, 21, 34}; 
    int p;

    cout << "Podaj liczbe: " << endl;
    cin >> p;

    int result = wyszukiwanie_interpolacyjne(t, 5, p);

    if (result >= 0) {
        cout << "Liczba " << p << " zostala znaleziona pod indeksem: " << result << endl;
    } else {
        cout << "Liczba " << p << " nie zostala odnaleziona" << endl;
    }

    return 0;
}
