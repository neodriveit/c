#include <stdio.h> 
#include <ctype.h> 
#include <string.h> 
#define N 100 
#define klucz "lampa"
int main( ) 
{
	char s[N]; 
	printf("Wpisz tekst: ");   
	gets(s);   
	printf("%s\n",s);
    char * wynik = strstr( s, klucz );
    if(wynik)
	{
    	printf( "w tekscie \"%s\" znaleziono slowo-klucz: %s\n", s, klucz);
	}else
    	printf( "w tekscie nie znaleziono slowa-klucza(%s)\n",klucz);
	return 0; 
}//main
