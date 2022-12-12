#include <stdio.h> 
#include <ctype.h> 
#include <string.h> 
#define N 100 
int main( ) 
{
	char s[N];
	int i,ls;   
	int t = 0;   
	ls = 0;
	printf("Podaj napis: ");   
	gets(s);   
	//printf("%s\n",s);
	for(i=0;i<N;i++)
		{
			if (isalnum(s[i]))
			{
				if(t==0) ls++;
				t=1;
			}else t=0;
		}//for
	printf("\nilosc slow: %d\n",ls);
	return ls; 
}//main
