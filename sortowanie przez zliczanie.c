#include <stdio.h>
#define n 8

int main()
{
	int a[n] = {3,6,3,2,7,1,7,1};
	int max=0;
	int i;
	for(i=0;i<n;i++) if(a[i]>max) max=a[i];
	int z[max];
	for(i=0;i<n;i++) z[i] = 0;
	for(i=0;i<n;i++) z[a[i]]++;
	int w[n];
	int j = 0;
	for(i=0;i<n;i++) 
	{
		while(z[j]==0) j++;
		w[i] = j;
		z[j]--;
	}//for(i)
	for(i=0;i<n;i++) printf("%d,",w[i]);
	return(0);
}//main
