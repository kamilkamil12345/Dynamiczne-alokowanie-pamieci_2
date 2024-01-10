#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int ile;
clock_t start, stop;
double czas;

int main()
{
    cout << "Ile liczb w tablicy? " << endl;    cin >> ile;

    //dynamiczna alokacja tablicy
    int *tablica;
    tablica=new int [ile];

    //zacznij odliczac czas
    start = clock();
    //wczytywanie liczb do tablicy
    for (int i=0; i<ile; i++)
    {
        tablica[i]=i;
        tablica[i]+=50;
    }
    stop = clock();
    czas = (double)(stop - start) / CLOCKS_PER_SEC; //przeliczenie cykli procesora na sekundy
    cout<< "Czas zapisu (bez wskaznika): " << czas << " sekund" << endl;

    delete [] tablica;

    //ponowna alokacja tablicy
     tablica=new int [ile];
	 int *wskaznik=tablica;

    //zacznij odliczac czas
    start = clock();
    //wczytywanie liczb do tablicy
    for (int i=0; i<ile; i++)
    {
        *wskaznik = i;
        *wskaznik+=50;
        wskaznik++;
    }
    stop = clock();
    czas = (double)(stop - start) / CLOCKS_PER_SEC; //przeliczenie cykli procesora na sekundy
    cout<< "Czas zapisu (ze wskaznikiem): " << czas << " sekund" << endl;

    delete [] tablica;

    return 0;
}
