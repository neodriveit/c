#include <stdio.h>

main() {
	int a, b;
	int wynik;
	int x;
	scanf("%d", &a);
	x=getchar();
	scanf("%d", &b);
	
	switch(x) {
		case 43:
			wynik=a+b;
			printf("%d", wynik);
			break;
		case 45:
			wynik=a-b;
			printf("%d", wynik);
		break;
		case 42:
			wynik=a*b;
			printf("%d", wynik);
		break;
		case 47:
			wynik=a/b;
			printf("%d", wynik);
		break;
		default:
			printf("error!");
		break;
	}
}
