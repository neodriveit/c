#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int main() {
	int tablica[MAX];
	int i;
	for(i=0; i<MAX; i++) tablica[i] = rand()%100;
	for(i=0; i<MAX; i++) printf("%d, ", tablica[i]);
	printf("\n\n\n");


    int tmp, j;
    for(i=0;i<MAX; i++) {
        tmp = tablica[i];
        for( j=i-1; j>=0 && tablica[j]>tmp;j--)
             tablica[j+1] = tablica[j];
        tablica[j+1] = tmp;
    }//for
    for(i=0; i<MAX; i++) {tmp=tablica[i];tablica[i]=tablica[MAX-1-i];tablica[MAX-1-i]=tmp;}
	for(i=0; i<MAX; i++) printf("%d, ", tablica[i]);
	return 0;
}//main
