#include <stdio.h>
int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int suma_tab(int tab[], int size) {
	
	int wynik = 0;
	int i = size;
	for(i=0; i<10; i++) {
		wynik =wynik + a[i];
	}
	printf("%d", wynik);
	
}
int main(void) {
	suma_tab(a[10], 10);
}
