#include <stdio.h>
// C - czerwony, B - bia³y, N - niebieski
char flaga[] = {'N','C','B','B','C','N','C','B','N','C','N','B'};
int dlugosc = 12;
int i; 
int main(){
	printf("Flaga nieposortowana: ");
	for(i=0;i<dlugosc;i++) printf("%c, ",flaga[i]);
	sortujFlage();
	return 0;
}//main

void sortujFlage(){
	int pozycjaLewy = 0;
	int pozycjaPrawy = dlugosc-1;
	for(i=pozycjaLewy;i<=pozycjaPrawy;i++) {
		if(flaga[i] == 'C') {
			char tmp = flaga[pozycjaLewy];
			flaga[pozycjaLewy] = flaga[i];
			flaga[i] = tmp;
			pozycjaLewy++;
		}//if(flaga[i] == 'C')
		if(flaga[i] == 'N') {
			char tmp = flaga[pozycjaPrawy];
			flaga[pozycjaPrawy] = flaga[i];
			flaga[i] = tmp;
			pozycjaPrawy--; i--;
		}//if(flaga[i] == 'N')
	}	//for(i)
	printf("\nFlaga posortowana: ");
	for(i=0;i<dlugosc;i++) printf("%c, ",flaga[i]);
}//sortujFlage()
