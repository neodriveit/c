#include <stdio.h>
#define n 5
int main()
{
	int a[n] = {4,6,2,1,3};
	int min=a[0],max=a[0];
	
	int i;
	for(i=0;i<n;i++) if(a[i]<min) min=a[i];
	for(i=0;i<n;i++) if(a[i]>max) max=a[i];
	
	printf("min = %d\nmax = %d",min,max);
	return(0);
}//main
