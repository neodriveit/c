#include <stdio.h>
int main()
{
int h,w,i,j,k;
printf("podaj liczbe poziomow choinki: ");
scanf("%d",&h);
w=(h*2-1);
for(i=1;i<=h;i++)
{
	for(j=0;j<=(w/2-i);j++) printf(" ");
	for(k=0;k<(i*2-1);k++) printf("*");
	printf("\n");
}
}
