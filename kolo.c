 #include <stdio.h>
 
 main() {
 	
 	const float pi = 3.14;
 	float r, P, L;
 	printf(">>Program do obliczania pola i obwodu kola na podstawie podanego promienia<<\n\nPodaj dlugosc promienia kola: ");
 	scanf("%f", &r);
 	//obliczenia
 	P=pi*r*r;
 	L=2*pi*r;
 	
 	printf("Pole kola wynosi: %.2f\nObwod kola wynosi: %.2f", P, L);
 	return(0);
 	
 }
