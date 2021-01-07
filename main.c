#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROZMIAR_TABLICY 15
#define MIN 2
#define MAX 10

// 1. Wypelni tablice o zadanym rozmiarze liczbami pseudolosowymi (int) z zadanego przedzialu
// 2. Policzy sume elementow tablicy
// 3. Policzy srednia arytmentyczna elementow tablicy
// 4. Wygenreuje histogram wartosci tablicy
void wyplenijTabliceLiczbamiPseudolowymi(int* tab, int min, int max);
int sumaTablicy(int *tab);
float sredniaTablicy(int *tab);
void generujHistogram(int *tab, int* histogram);
void wypiszTablice(int *tab);
void wypiszStatystyki(int *tab, int suma, float srednia, int* histogram);

int main() {
    int tablica[ROZMIAR_TABLICY];
    int suma;
    int avg;
    wyplenijTabliceLiczbamiPseudolowymi(tablica, MIN, MAX);
    wypiszTablice(tablica);

    return 0;
}

void wyplenijTabliceLiczbamiPseudolowymi(int* tab, int min, int max){
    srand(time(0));

    for (int i=0; i<ROZMIAR_TABLICY; i++)
        {
            tab[i] = rand() % max + min;
        }
}

void wypiszTablice(int *tab) {
    printf("\n[");
    for (int i=0; i<ROZMIAR_TABLICY; i++){
        printf("%d ", tab[i]);
    }
    printf("]\n");
}
