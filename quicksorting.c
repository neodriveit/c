#include <stdio.h>
int i,j,k;
int dlugosc = 10;//         pivot
int main() {                 //
	int tablica[] = {6,2,8,3,4,9,0,1,5,7};
	//////////////////////////////
	quicksort(tablica,0,dlugosc-1);
	//////////////////////////////
}//main

void quicksort(int tablica[], int lewy, int prawy){
	
	for(i=0;i<dlugosc;i++) printf("%d, ",tablica[i]);printf("\n");
	int pivot = (lewy+prawy+1)/2;
	for(i=0;i<dlugosc;i++) printf("%d, ",tablica[i]);printf("\n");
	i = 0; j = dlugosc - 1; int t = 0;
	while(i<j){
		while(tablica[pivot]>tablica[i]) i++;
		while(tablica[pivot]<tablica[j]) j--;
		k++;
		if(i<=j) {
			int tmp = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = tmp;
			for(i=0;i<dlugosc;i++) printf("%d, ",tablica[i]);printf("\n");
			i = 0; j = dlugosc - 1;
		}//if(i<=j)
		if(k==8) break;
	}//while(i<j)
	for(i=0;i<dlugosc;i++) printf("%d, ",tablica[i]);
}
