#include <stdio.h>

long long fibonacci(int number){
	if(number==1) return 0;
	if(number==2) return 1;
	if(number>2) return fibonacci(number-1)-(fibonacci(number-2)*2);
	
}//long long fibonacci

int main(){
	printf("Ktory element ciagu fibonacciego mam wyswietlic (podaj liczbe): ");
	int liczba;
	scanf("%d", &liczba);
	printf("%d", fibonacci(liczba));
	return 0;
}//main
