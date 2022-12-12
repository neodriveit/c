#include <stdio.h >
#include <stdlib.h>
#define N 100
 
int main ()
{
FILE *file;
char tekst[N];
int i;
if ((file=fopen("plik1.txt", "w"))==0)
	{	printf ("Nie mogê otworzyæ pliku tekst.txt do zapisu!\n");
	    exit(1);
}else {
for(i=0;i<100;i++) 
{
	printf("Podaj tekst: ");
	gets(tekst);
    char *wynik = strstr( tekst, "koniec");
	if(wynik) i=N;
	else fprintf (file, "%s \n", tekst);
}//for(i)
fclose (file);
}//else
return 0;
}//main
