#include <stdio.h>
#include <stdlib.h>

const int N = 1000;
 
int main ()
{

FILE *file;
int c;
int i;
for(i=0;i<N;i++)
{
if((file=fopen("odczyt.txt", "r"))==NULL) 
{	printf ("Nie mogê otworzyæ pliku odczyt.txt do odczytu!\n");
    exit(1);
}else for(i=0;i<N;i++)
{
	while(c != EOF) {
		c = fgetc(file);
		switch(c) {
			case 9: printf("HT\n"); break;
			case 10: printf("LF\n"); break;
			case 12: printf("FF\n"); break;
			case 13: printf("CR\n"); break;
			default: 
				if(c>127) printf("<U+0x%x ", c);
				else printf("0x%x ", c); 
			break;
		}
	if(feof(file)) fclose(file);
	}
}//else
}//for(i)
 return(0);
}//main
