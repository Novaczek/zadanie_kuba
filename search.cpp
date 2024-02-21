#include <iostream>
#include <cmath> // dla funkcji sqrt
using namespace std;

int wyszukiwanie_liniowe(int t[], int size, int k) {
    for (int i = 0; i < size; i++) {
        if (k == t[i]) {
            return i; 
        }
    }
    return -1; 
}

int wyszukiwanie_liniowe_z_wart(int t[], int size, int k) {
    for (int i = 0; i < size; i++) {
        if (k == t[i]) {
            return i; 
        }
    }
    return -1; 
}

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
    int tt[12] = {2,3,1,5,11,15,6,8,4,23,10,7};
    int result;
    int k_exist_in_tt = 5;
    int k_not_exist_in_tt = 13;
    result = wyszukiwanie_liniowe(tt, 12, k_exist_in_tt);
    if (result >= 0) {
        cout << "Liczba " << k_exist_in_tt << " została znaleziona pod indeksem: " << result << endl;
    } else {
        cout << "Liczba " << k_exist_in_tt << " nie została odnaleziona" << endl;
    }

    result = wyszukiwanie_liniowe_z_wart(tt, 12, k_exist_in_tt);
    if (result >= 0) {
        cout << "Liczba " << k_exist_in_tt << " została znaleziona pod indeksem: " << result << endl;
    } else {
        cout << "Liczba " << k_exist_in_tt << " nie została odnaleziona" << endl;
    }

    result = wyszukiwanie_binarne(tt, 12, k_exist_in_tt);
    if (result >= 0) {
        cout << "Liczba " << k_exist_in_tt << " została znaleziona pod indeksem: " << result << endl;
    } else {
        cout << "Liczba " << k_exist_in_tt << " nie została odnaleziona" << endl;
    }

    result = wyszukiwanie_skokowe(tt, 12, k_exist_in_tt);
    if (result >= 0) {
        cout << "Liczba " << k_exist_in_tt << " została znaleziona pod indeksem: " << result << endl;
    } else {
        cout << "Liczba " << k_exist_in_tt << " nie została odnaleziona" << endl;
    }

    result = wyszukiwanie_interpolacyjne(tt, 12, k_exist_in_tt);
    if (result >= 0) {
        cout << "Liczba " << k_exist_in_tt << " została znaleziona pod indeksem: " << result << endl;
    } else {
        cout << "Liczba " << k_exist_in_tt << " nie została odnaleziona" << endl;
    }

    return 0;
} 
