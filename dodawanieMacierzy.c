//dodawanie, mno¿enie macierzy
#include <stdlib.h>
#include <stdio.h> 
#define x 5
#define y 5
#define w 15
#define k 15
#define pmin 11
#define qmin 33
#define amin 131
#define bmin 421
int a[w][k];
int b[w][k];
int c[w][k];
int p[x][y];
int q[x][y];
int i,j;

int main()
{
printf("\n>>>>>%dx%d<<<<<\n\n",x,y);
printf("A\n");
wypelnij_maci(p,x,y,pmin);
printf("B\n");
wypelnij_maci(q,x,y,qmin);
dodaj_maci(p,q,x,y);
mnoz_maci(p,q,x,y);

printf("\n>>>>>%dx%d<<<<<\n\n",w,k);
printf("A\n");
wypelnij_maci(a,w,k,amin);
printf("B\n");
wypelnij_maci(b,w,k,bmin);
dodaj_maci(a,b,w,k);
mnoz_maci(a,b,w,k);

return(0);
}//main
int wypelnij_maci(int a[w][k],int row,int col,int liczba) 
{
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
		a[i][j] = liczba;
		liczba++;
		printf("%d ", a[i][j]);
		}	
	printf("\n");
	}
	printf("\n");
}//wypelnij_maci
int dodaj_maci(int a[w][k],int b[w][k],int row,int col) 
{
	printf("A+B\n");
	int c[w][k];
	for(i=0; i<row; i++)
	{		
		for(j=0; j<col; j++)
		{
		c[i][j]  =  a[i][j]  +  b[i][j];
		printf("%d ", c[i][j]);
		}//for(j)
	printf("\n");
	}//for(i)
	printf("\n");
}//dodaj_maci

int mnoz_maci(int a[w][k],int b[w][k],int row,int col) 
{
	printf("A*B\n");
	int c[w][k];
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			int tmp,m;
							/*a00*b00+a01*b10+a02*b20...
							  a00*b01+a01*b11+a02*b21...
							  a00*b02+a01*b12+a02*b22...
							  
							  a10*b00+a11*b10+a12*b20...
							  a10*b01+a11*b11+a12*b21...
							  a10*b02+a11*b12+a12*b22...
							  
							  a20*b00+a21*b10+a22*b20...
							  a20*b01+a21*b11+a22*b21...
							  a20*b01+a21*b12+a22*b22...
							  .	.	.	.	.	.	.
							  .	.	.	.	.	.	.
							  .	.	.	.	.	.	.  */
							for(m=0;m<w;m++)
							{
								tmp  =  a[i][m] * b[m][j] + tmp;
								
							}c[i][j]=tmp;tmp=0;printf("%d  ", c[i][j]);
		}//for(j)
		printf("\n\n");
	}//for(i)
}//mnoz_maci
