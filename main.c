#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROZMIAR_TABLICY 15
#define MIN 2
#define MAX 10
#define Rozmiar_Histograma 11

// 1. Wypelnij tablice o zadanym rozmiarze liczbami pseudolosowymi (int) z zadanego przedzialu
// 2. Policzy sume elementow tablicy
// 3. Policzy srednia arytmetyczna elementow tablicy
// 4. Wygeneruje histogram wartosci tablicy

void wypelnijTabliceLiczbamiPseudolosowymi(int *tab, int min, int max);

int sumaTablicy(int *tab);

float sredniaTablicy(int *tab);

void generujHistogram(int *tab, int *histogram);

void wypiszTablice(int *tab);

void wypiszStatystyki(int *tab, int suma, float srednia, int *histogram);

int main() {
    int tablica[ROZMIAR_TABLICY];
    int histogram[Rozmiar_Histograma];

    for (int i = 0; i < Rozmiar_Histograma; i++) {
        histogram[i] = 0;
    }

    wypelnijTabliceLiczbamiPseudolosowymi(tablica, MIN, MAX);
    wypiszTablice(tablica);
    generujHistogram(tablica, histogram);
    wypiszStatystyki(tablica, sumaTablicy(tablica), sredniaTablicy(tablica), histogram);

    return 0;
}

void wypelnijTabliceLiczbamiPseudolosowymi(int *tab, int min, int max) {
    srand(time(0));

    for (int i = 0; i < ROZMIAR_TABLICY; i++) {
        tab[i] = min + rand() % (max - min + 1);
    }
}

void wypiszTablice(int *tab) {
    printf("\n[");
    for (int i = 0; i < ROZMIAR_TABLICY; i++) {
        printf("%d ", tab[i]);
    }
    printf("]\n");
}

void generujHistogram(int *tab, int *hist) {
    for (int i = 0; i < ROZMIAR_TABLICY; i++) {
        hist[tab[i]] = hist[tab[i]] + 1;
    }
}

int sumaTablicy(int *tab) {
    int suma = 0;
    for (int i = 0; i < ROZMIAR_TABLICY; i++) {
        suma = suma + tab[i];
    }
    return suma;
}

float sredniaTablicy(int *tab) {
    float srednia = 0;
    srednia = (float) sumaTablicy(tab) / ROZMIAR_TABLICY;
    return srednia;
}

void wypiszStatystyki(int *tab, int suma, float srednia, int *hist) {
    printf("Suma: %d \n", suma);
    printf("Srednia: %.2f \n", srednia);
    for (int i = 0; i < Rozmiar_Histograma; i++) {
        printf("%d -> %d \n", i, hist[i]);
    }
}