#include <stdio.h>
#include <math.h>

main() {
	float a, b, c, a1, b1, c1, ob, p;
	double pierw, wynik;
	printf(">>Program obliczajacy pole trojkata z podanych dlugosci bokow<<\n\nPodaj dlugosc pierwszego boku: ");
	scanf("%f", &a);
	printf("Podaj dlugosc drugiego boku: ");
	scanf("%f", &b);
	printf("Podaj dlugosc trzeciego boku: ");
	scanf("%f", &c);
//obliczenia	
	ob=a+b+c;
	p=ob/2;
	a1=p-a;
	b1=p-b;
	c1=p-c;
	pierw=p*a1*b1*c1;
	wynik=sqrt(pierw);
	
	printf("pole trojkata: %d", wynik);
	return(0);
}
