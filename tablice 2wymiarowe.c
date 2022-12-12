//tablice 2wymiarowe
#include <stdlib.h>
#include <stdio.h> 
#define ROW 5 
#define COL 10 
#define ZAKRES 1000
int losuj(int zakres); 
int utworz_tab(int tab[ROW][COL],int row, int col); 
int znajdz_max(int tab[ROW][COL],int row, int col); 
double znajdz_sredn(int tab[ROW][COL],int row, int col); 

int main() 
{   
	int i,j;   
	int max;   
	double sredn;   
	int tab[ROW][COL]; 
	utworz_tab(tab,ROW,COL);  
	max = znajdz_max(tab,ROW,COL);   
	printf("maksimum %d\n",max);  
	sredn = znajdz_sredn(tab,ROW,COL);   
	printf("Srednia %.2f\n",sredn);  
	return 0; 
}//main

int losuj(int zakres) 
{   
	int tmp;   
	tmp = (int)(rand() / (RAND_MAX + 1.0) * zakres);   
	return tmp; 
}//losuj

int utworz_tab(int tab[ROW][COL],int row, int col)  
{
int i,j;
int losowa;   
   for(i=0;i<row;i++) 
   {
   		printf("Wiersz  %d\n\n", i+1);
   		for(j=0;j<col;j++) 
		{
			losowa = losuj(ZAKRES);           
			printf("Liczba: %d\n",losowa);          
			tab[i][j] =losowa; 
		}//for(j)
		printf("\n");   
	}//for(i)
	return 0; 
}//utworz_tab

int znajdz_max(int tab[ROW][COL],int row, int col) 
{
int i,j;
int max; 

   	for(i=0;i<row;i++) 
   	{
   		for(j=0;j<col;j++) 
		{
			if (tab[i][j]>max) max = tab[i][j];
		}//for{j}
	}//for(i)
	return(max);
}//znajdz_max

double znajdz_sredn(int tab[ROW][COL],int row, int col)
{
int i,j;
double q = row*col;
double sredn;
int suma=0;
	
   	for(i=0;i<row;i++) 
   	{
   		for(j=0;j<col;j++) 
		{
			suma=suma+tab[i][j];
			sredn=suma/q;
		}//for(j)
	}//for(i)
	return(sredn);
}//znajdz_sredn
