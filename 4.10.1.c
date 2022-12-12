//program do zamiany liczb w systemie dziesiêtnym na system dwójkowy, ósemkowy, szesnastkowy
#include <stdio.h>
int liczba;
int main(){
	printf("Podaj liczbe w systemie dziesietnym:\n");
	scanf("%d", &liczba);
	konwert2bin(liczba);
	return 0;
}
void konwert2bin(int liczba){
	int size = 8;
	int bin[size];
	int i;
	int reszta;
	int liczb = liczba;
	for(i=size-1;i>=0;i--) {
		reszta = liczb%2;
		bin[i] = reszta;
		liczb = (liczb-reszta)/2;
	}
	printf("binarnie - ");
	for(i=0;i<size;i++) printf("%d",bin[i]);
	printf("\noktalnie - %o\n", liczba);
	printf("heksadecymalnie - %x\n", liczba);
	return 0;
}
