#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;

const int size = 10;

void wypelnij_tablice(int t[], int size) {
    srand(time(NULL)); 
    
    for (int i = 0; i < size; i++) {
        t[i] = rand() % 100; 
    }
}

void wydrukuj_tablice(int t[], int size) {
    for (int i = 0; i < size; i++) {
        cout << t[i] << " ";
    }
    cout << endl;
}

void BubbleSort(int n, int *X) {
    int i,j;
    for (int i = 1; i < n ; i++) 
        for (int j = n - 1; j >= i; j--) 
            if (X[j] < X[j - 1])
                swap(X[j - 1], X[j]);
}

void MergeSort(int t[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        
        MergeSort(t, left, middle);
        MergeSort(t, middle + 1, right);
        
        int i = left, j = middle + 1, k = 0;
        int temp[right - left + 1];
        
        while ((i <= middle) && (j <= right)) {
            if (t[i] <= t[j]) {
                temp[k++] = t[i++];
            } else {
                temp[k++] = t[j++];
            }
        }
        
        while (i <= middle) {
            temp[k++] = t[i++];
        }
        
        while (j <= right) {
            temp[k++] = t[j++];
        }
        
        for (i = left, k = 0; i <= right; i++, k++) {
            t[i] = temp[k];
        }
    }
}
void ShakerSort(int t[], int n) {
    int left = 0;
    int right = n - 1;
    int k;

    while (left < right) {
        k = left;
        for (int j = right; j > left; j--) {
            if (t[j]) {
                swap(t[j - 1], t[j]);
                k = j;
            }
        }
        left = k + 1;

        k = right;
        for (int j = left; j < right; j++) {
            if (!t[j - 1]) {
                swap(t[j - 1], t[j]);
                k = j;
            }
        }
        right = k - 1;
    }
}
void QuickSort(int t[], int left, int right)
{
	if(right <= left) return;
	
	int i = left - 1, j = right + 1, 
	pivot = t[(left+right)/2]; 
	
	while(1)
	{
		
		while(pivot>t[++i]);
		
		
		while(pivot<t[--j]);
		
		if( i <= j)
			
			swap(t[i],t[j]);
		else
			break;
	}

	if(j > left)
    QuickSort(t, left, j);
	if(i < right)
    QuickSort(t, i, right);
}
void InsertionSort(int n, int *tab)
{
     int size, j;
     for(int i=1; i<n; i++)
     {
             size = tab[i]; 
             j = i-1;
             
             
             while(j>=0 && tab[j]>size) 
             {
                        tab[j+1] = tab[j]; 
             }
             tab[j+1] = size; 
     }     
}

int main() {
    const int n = 10;
    int t[n];
    
    wypelnij_tablice(t, n);

    
    cout << "Tablica przed sortowaniem:" << endl;
    wydrukuj_tablice(t, n);

    
    BubbleSort(n, t);
    cout << "Tablica po Bubble Sort:" << endl;
    wydrukuj_tablice(t, n);

    
    MergeSort(t, 0, n - 1);
    cout << "Tablica po Merge Sort:" << endl;
    wydrukuj_tablice(t, n);


    ShakerSort(t, n);
    cout << "Tablica po Shaker Sort:" << endl;
    wydrukuj_tablice(t, n);


    QuickSort(t, 0, n - 1);
    cout << "Tablica po Quick Sort:" << endl;
    wydrukuj_tablice(t, n);

    
    InsertionSort(n, t);
    cout << "Tablica po Insertion Sort:" << endl;
    wydrukuj_tablice(t, n);

    return 0;
};