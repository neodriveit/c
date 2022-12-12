#include <stdio.h>
#define n 10
int main()
{
	int a[n] = {22,17,5,9,11,60,12,23,43,3};
	int i=0,t=0;
	do
	{
	t = 0;
		for(i=0;i<n;i++)
		{
			if(a[i]>a[i+1])
			{
				int tmp = a[i+1];
				a[i+1] = a[i];
				a[i] = tmp;
				t = 1;
			}//if
		}//for(j)
	}while(t==1);
for(i=0;i<n;i++) printf("%d,",a[i]);
return(0);
}//main
