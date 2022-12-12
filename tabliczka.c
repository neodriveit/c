#include <stdio.h>

int main() {
	int x, y, wynik;
	
	for(x=1; x<=10; x++) {
	for(y=1; y<=10; y++) {
		wynik = x*y;
		printf("%d ", wynik);
	}
	printf("\n");
	}
	
	return 0;
}
