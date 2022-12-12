#include <stdio.h>

long long fibonacci(int number){
	int a = 0; int b = 1; int i;
	if(number==1) return a;
	if(number==2) return b;
	if(number>2) 
	for(i=0; i<number; i++) {
		int tmp=b;
		b += a;
		a= tmp;
	}//for
	return b;
}//long long fibonacci

int main(){
	printf("Ktory element ciagu fibonacciego mam wyswietlic (podaj liczbe): ");
	int liczba;
	scanf("%d", &liczba);
	printf("%d", fibonacci(liczba));
	return 0;
}//main
