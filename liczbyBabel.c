//sortowanie b¹belkowe liczb
#include <stdio.h>
#define n 7
int tab[n] = {2,6,3,4,5,1,7};
int tmp,i,j,m,k;
void print_tab();

int main ()
{	
	print_tab();
	m=n-1;
	for(k=0;k<n-1;k++)
	{
	for(j=0;j<n-1;j++)
	{	
	for(i=0;i<n-1;i++)
	{	
	tmp = tab[j+1];
		if(tab[j]>tab[j+1])
		{	
			tab[j+1] = tab[j];
			tab[j]=tmp;
			tmp=0;
			print_tab();
		}//if
	}//for(i)
	}//for(j)	
	}//for(k)
return(0);
}//main

void print_tab()
{
	for(i=0;i<n;i++)
		{
			printf("%d ", tab[i]);
		}printf("\n\n");
}//print_tab
