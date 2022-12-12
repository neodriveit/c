#include <stdio.h>
#include <stdlib.h>

const int N = 100;
char klucz[10] = "plik";
char nazwa[10] = "odczyt.txt";
int l=0;

int main ()
{
FILE *file;
char tekst[N];
int i;
for(i=0;i<N;i++)
{
if((file=fopen(nazwa, "r"))==NULL) 
{	printf ("Nie mogê otworzyæ pliku tekst.txt do zapisu!\n");
    exit(1);
}else for(i=0;i<N;i++)
{	
	fgets(tekst, N, file);
	char * wynik = strstr ( tekst, klucz);
    if(wynik){printf( "%s",tekst);l++;}
	if(feof(file)) 
	{
		fclose(file);
		printf("\n\nWypisano wszystkie linie tekstu z pliku %s, ktore zawieraja slowo %s (%d linie)\n",nazwa,klucz,l);
		i=N;
	}//if
}//else
}//for(i)
 
 return(0);
}//main
