#include <stdio.h>
#include <stdlib.h>

const int N = 100;
 
int main (int argc, char *argv[])
{
/*Nazw� pliku mo�na uzyska� z parametr�w funkcji main jako argv[1].

int main(int argc, char *argv[]) {
printf(�Parametr %s\n�,argv[1]);

co� u mnie nie dzia�a argv[1] == NULL*/

argv[1]="odczyt.txt";

FILE *file;
char tekst[N];
int i;
for(i=0;i<N;i++)
{
if((file=fopen(argv[1], "r"))==NULL) 
{	printf ("Nie mog� otworzy� pliku tekst.txt do zapisu!\n");
    exit(1);
}else for(i=0;i<N;i++)
{
	fgets(tekst, N, file);
	fputs(tekst, stdout);
	if(feof(file)) 
	{
		fclose(file);
		printf("\n\nwczytanych linii: %d", i+1);
		i=N;
	}//if
	
	
}//else
}//for(i)
 
 return(0);
}//main
