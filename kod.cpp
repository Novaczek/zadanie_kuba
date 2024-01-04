#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int tab[12];
    srand (time(NULL));
    for(int i=0;i<12;i++){
        tab[i]=rand()%100+1;
    }
    for(int i = 0;i<12;i++)
    cout<<tab[i]<<"";
return 0;
}

    
