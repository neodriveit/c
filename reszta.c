#include <stdio.h>

int N[8] = {200,100,50,20,10,5,2,1};
int reszta,ilosc;

int main(){
	printf("Ile reszty mam wydac?\n");
	scanf("%d",&reszta);
	
	int i;
	while(reszta>0) {
		if(reszta>=N[i]){        
		ilosc = reszta/N[i];
        reszta = reszta-(N[i]*ilosc);
        printf("%dzlx%d\n", N[i], ilosc);
        }//if
    i++;
	}//while(reszta>0)
return (0);
}//main
