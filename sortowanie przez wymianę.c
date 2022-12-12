#include <stdio.h>
#define n 10
int main()
{
	int a[n] = {33,27,1,14,40,72,22,11,9,5};
	int i=0,j=0,index,min;
	for(j=0;j<n;j++){
	min=2147483647;
	for(i=j;i<n;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
			index=i;
		}//if
	}//for(i)
	int tmp=a[j];
	a[j]=a[index];
	a[index]=tmp;
	}//for(j)
	for(i=0;i<n;i++) printf("%d,",a[i]);
	return(0);
}//main
