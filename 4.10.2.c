//program do zamiany liczb w systemie binarnym na system ósemkowy, dziesiêtny i szesnastkowy
#include <stdio.h>
#include <math.h>
int binarnie=0, decymalnie=0, i=0, j=0, bit=0;
int main(){
	printf("Podaj liczbe w systemie binarnym\n");
	scanf("%d",&binarnie);
	decymalnie = konwert2dec(binarnie);
	printf("bin: %d   ", binarnie );
	printf("dec: %d   ", decymalnie);
	printf("okt: %o   ", decymalnie);
	printf("hex: %x   ", decymalnie);
return 0;
}//main

int konwert2dec(int bin) {
	for(i=0;i<8;i++) {
		bit = bin%10;
		if(bit==1) {decymalnie += pow(2,j); bin -= 1;}
		if(bin==0) break;
		bin=bin/10;
		j++; bit = 0;
	}//for(i)	
	return decymalnie;
}//konwert2dec
