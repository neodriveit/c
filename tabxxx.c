#include <stdlib.h>
#include <stdio.h>
#define ROW 5
#define COL 10
int losuj(int zakres);
int utworz_tab(int tab[ROW][COL],int row, int col) ;
int znajdz_max(int tab[ROW][COL],int row, int col);
double znajdz_sredn(int tab[ROW][COL],int row, int col);
int main() {
 int i,j;
 int max;
 double sredn;
 int tab[ROW][COL];
 // Tworzymy tablice
 utworz_tab(tab,ROW,COL);
 // Maksimum
 max = znajdz_max(tab,ROW,COL);
 printf("maksimum %d\n",max);
 // Srednia
 sredn = znajdz_sredn(tab,ROW,COL);
 printf("Srednia %f\n",sredn);
 return 0;
}
int losuj(int zakres) {
 int tmp;
 tmp = (int)(rand() / (RAND_MAX + 1.0) * zakres);
 return tmp;
}
int utworz_tab(int tab[ROW][COL],int row, int col)
{
 int i,j;
 int losowa;
 for(i=0;i<row;i++) {
 for(j=0;j<col;j++) {
 losowa = losuj(100);
 // printf("Liczba: %d\n",losowa);
 tab[i][j] =losowa;
 printf("%2d ",losowa);
 }
 printf("\n");
 }
}

