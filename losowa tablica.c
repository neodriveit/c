#include <stdio.h>
#include <stdlib.h>
#define MAX 500
int main() {
	int tablica[MAX];
	int i;
	for(i=0; i<MAX; i++) tablica[i] = rand()%100;
	for(i=0; i<MAX; i++) printf("%d, ", tablica[i]);
	printf("\n\n\n podaj liczbe do zliczenia: ");
	int liczba; int licznik=0;
	scanf("%d", &liczba);
	printf("%d", liczba);
	for(i=0; i<MAX; i++) if(tablica[i]==liczba) licznik++;
	printf("\n\nliczba %d znajduje sie w tablicy %d razy", liczba, licznik);
	return 0;
}//main
