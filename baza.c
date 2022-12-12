#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#define NSIZE 40
#define ASIZE 80
#define MAX 200
#define PLIK "baza.txt"

typedef struct osoba_str
{
 char nazwisko[NSIZE];
 char imie[NSIZE];
 char adres[ASIZE];
 char pesel[NSIZE];
}osobastr;

struct osoba_str osoba[MAX];
FILE *plik;
int i,j;
void setCursor(int x, int y);
int col = 40;
int row = 7;

main()
{
	system("COLOR 9e");
	
	plik=fopen(PLIK,"a");fclose(plik);
	int choice;
	while(1){
		setCursor(col,row-1);printf(">>>WYBIERZ<<<");
		setCursor(col,row+1);printf("1.Dodaj nowa osobe");
		setCursor(col,row+2);printf("2.Wyswietl baze danych");
		setCursor(col,row+3);printf("3.Szukaj po nr.PESEL");
		setCursor(col,row+4);printf("4.Szukaj po nazwisku");
		setCursor(col,row+6);printf("? ");
		setCursor(col+2,row+6);scanf("%d", &choice);
		switch(choice) 
		{
			case(1):add();break;
			case(2):display();break;
			case(3):search_PESEL();break;
			case(4):search_NAME();break;
			default:setCursor(col,row+8);printf("Zla opcja, wybierz inna");break;
		}//switch
	}//while(1)
}//main

add()
{	
	system("cls");
	struct osoba_str new_osoba;
	setCursor(1,1);printf("*zadne z wprowadzanych danych nie moze zawierac spacji (poprawny format adresu np. Legnicka123/45,Wroclaw)");
	setCursor(col,row-1);printf("DODAJ NOWA OSOBE");
	setCursor(col,row+1);printf("Nazwisko: "); scanf("%s",&new_osoba.nazwisko);	
	setCursor(col,row+2);printf("Imie: "); scanf("%s",&new_osoba.imie);
	setCursor(col,row+3);printf("Adres: "); scanf("%s",&new_osoba.adres);
	setCursor(col,row+4);printf("PESEL: "); scanf("%s",&new_osoba.pesel);
	
	i=0;
	int x = 1;
	for(i=0;i<11;i++)
	{
		if((isdigit(new_osoba.pesel[i]))==0) x = 0;
	}i=0;
	
	if(((strlen(new_osoba.pesel))!=11) || (x==0))
	{
		setCursor(col,row-1);printf("!!!Niepoprawny PESEL!!!");
		setCursor(col,row  );printf("!!!Niepoprawny PESEL!!!");
		setCursor(col,row+1);printf("!!!Niepoprawny PESEL!!!");
		setCursor(col,row+2);printf("!!!Niepoprawny PESEL!!!");
		setCursor(col,row+3);printf("!!!Niepoprawny PESEL!!!");
	}else
	{
	if((plik=fopen(PLIK,"r"))==NULL){printf ("Nie moge otworzyc pliku %s do odczytu!\n",PLIK);exit(1);}
	while(!feof(plik)){fscanf(plik,"%s %s %s %s",&osoba[i].nazwisko,&osoba[i].imie,&osoba[i].adres,&osoba[i].pesel);i++;}i=0;
	
	int t = 1;
	for(i=0;i<MAX;i++)
	{
		if(strcmp(osoba[i].pesel,new_osoba.pesel)==0) 
		{
			setCursor(col-15,row+6);printf("Podany pesel istnieje w bazie, nie mozna zapisac osoby");
			t = 0;
		}
	}//for
	i=0;
	
	if(t==1)
	{
	if((plik=fopen(PLIK,"a"))==NULL){printf ("Nie moge otworzyc pliku %s do zapisu!\n",PLIK);exit(1);}
	fprintf (plik, "\n%s %s %s %s",new_osoba.nazwisko,new_osoba.imie,new_osoba.adres,new_osoba.pesel);
	fclose(plik);
	
	setCursor(col,row-1);printf("DODANO NOWA OSOBE:");
	setCursor(col,row+1);printf("Nazwisko: %s",new_osoba.nazwisko);
	setCursor(col,row+2);printf("Imie: %s",new_osoba.imie);	 
	setCursor(col,row+3);printf("Adres: %s",new_osoba.adres);	 
	setCursor(col,row+4);printf("PESEL: %s",new_osoba.pesel);
	}//if
	}//else
	setCursor(col,row+7);printf("Nacisnij dowolny klawisz aby kontynuowac");
	getch();
   	system("cls");
}//add

display()
{	
	int col1 = 12;
	int col2 = 32;
	int col3 = 52;
	int col4 = 72;
	int row = 3;
   	system("cls");
	if((plik=fopen(PLIK,"r"))==NULL){printf ("Nie moge otworzyc pliku %s do odczytu!\n",PLIK);exit(1);}
	setCursor(col2, row);printf(">>>NAZWISKO<<<");
	setCursor(col3, row);printf(">>>IMIE<<<");
	setCursor(col4, row);printf(">>>ADRES<<<");
	setCursor(col1, row);printf(">>>PESEL<<<");row++;row++;
	while(!feof(plik))
	{
	fscanf(plik,"%s %s %s %s",&osoba[i].nazwisko,&osoba[i].imie,&osoba[i].adres,&osoba[i].pesel);
	setCursor(col2, row);printf("%s",osoba[i].nazwisko);
	setCursor(col3, row);printf("%s",osoba[i].imie);
	setCursor(col4, row);printf("%s",osoba[i].adres);
	setCursor(col1, row);printf("%s",osoba[i].pesel);row++;
	}//while
	
	setCursor(col1,row+2);printf("Nacisnij dowolny klawisz aby kontynuowac");
	fclose(plik);
	getch();
	system("cls");
}//display

search_NAME()
{	
	char name[NSIZE];
	setCursor(col,row+8);printf("Podaj szukane nazwisko: ");
	scanf("%s",&name);
	i = 0;
	if((plik=fopen(PLIK,"r"))==NULL){printf ("Nie moge otworzyc pliku %s do odczytu!\n",PLIK);exit(1);}
	while(!feof(plik)){fscanf(plik,"%s %s %s %s",&osoba[i].nazwisko,&osoba[i].imie,&osoba[i].adres,&osoba[i].pesel);i++;}
	
	int o = 0;
	i = 0;
	setCursor(col,row+8);
	for(i=0;i<MAX;i++) 
		if(stricmp(osoba[i].nazwisko,name)==0) 
			{printf("Osoba o nazwisku \"%s\" znajduje sie w bazie",osoba[i].nazwisko); o=i; i=MAX;}i=0;
	if(o!=0)
	{		
	setCursor(col,row+10);printf("Nazwisko: %s", osoba[o].nazwisko);
	setCursor(col,row+11);printf("Imie: %s",osoba[o].imie);	 
	setCursor(col,row+12);printf("Adres: %s",osoba[o].adres);	 
	setCursor(col,row+13);printf("PESEL: %s",osoba[o].pesel);
	setCursor(col,row+15);printf("Aby zmienic adres wcisnij klawisz \"T\"");
	int ch = getch();
	if(ch==84||ch==116) change_ADDR(o);
	}else {printf("Osoba o nazwisku \"%s\" nie znajduje sie w bazie",name);getch();}
	fclose(plik);
	system("cls");
}//search_NAME

search_PESEL()
{	
	char pesel[11];
	setCursor(col,row+8);printf("Podaj szukany PESEL: ");
	scanf("%s",&pesel);
	
	i=0;
	int x = 1;
	for(i=0;i<11;i++)
	{
		if((isdigit(pesel[i]))==0) x = 0;
	}i=0;
	
	if(((strlen(pesel))!=11) || (x==0))
	{
		setCursor(col,row+8);printf("!!!!!!!!!Niepoprawny PESEL!!!!!!!!!");
		getch();
	}else
	{
	i = 0;
	if((plik=fopen(PLIK,"r"))==NULL){printf ("Nie moge otworzyc pliku %s do odczytu!\n",PLIK);exit(1);}
	while(!feof(plik)){fscanf(plik,"%s %s %s %s",&osoba[i].nazwisko,&osoba[i].imie,&osoba[i].adres,&osoba[i].pesel);i++;}
	
	int o = 0;
	i = 0;
	setCursor(col,row+8);
	for(i=0;i<MAX;i++) 
		if(stricmp(osoba[i].pesel,pesel)==0) 
			{printf("Osoba z nr PESEL: \"%s\" znajduje sie w bazie",osoba[i].pesel); o=i; i=MAX;}i=0;
	if(o!=0)
	{		
	setCursor(col,row+10);printf("Nazwisko: %s", osoba[o].nazwisko);
	setCursor(col,row+11);printf("Imie: %s",osoba[o].imie);	 
	setCursor(col,row+12);printf("Adres: %s",osoba[o].adres);	 
	setCursor(col,row+13);printf("PESEL: %s",osoba[o].pesel);
	setCursor(col,row+15);printf("Aby zmienic adres wcisnij klawisz \"T\"");
	int ch = getch();
	if(ch==84||ch==116) change_ADDR(o);
	}else {printf("Osoba z nr PESEL: \"%s\" nie znajduje sie w bazie",pesel);getch();}
	}//else
	fclose(plik);
	system("cls");
}//search_PESEL

change_ADDR(int o)
{	

	char new_addr[ASIZE];
	setCursor(col,row+16);printf("Podaj nowy adres: ");scanf("%s",&new_addr);
	i=0;
	if((plik=fopen(PLIK,"r+"))==NULL){printf ("Nie moge otworzyc pliku %s do odczytu!\n",PLIK);exit(1);}
	while(!feof(plik))
	{	fscanf(plik,"%s %s %s %s",&osoba[i].nazwisko,&osoba[i].imie,&osoba[i].adres,&osoba[i].pesel);i++;}
	
	j=i;i=0;
	fseek(plik,0,SEEK_SET);
	
	for(i=0;i<j;i++)
	{
		
		if(i!=o)fprintf (plik, "\n%s %s %s %s",osoba[i].nazwisko,osoba[i].imie,osoba[i].adres,osoba[i].pesel);
		if(i==o)fprintf (plik, "\n%s %s %s %s",osoba[i].nazwisko,osoba[i].imie,new_addr,osoba[i].pesel);
		
	}//for
	setCursor(col,row+17);printf("Adres \"%s\" zostal zmieniony na \"%s\"",osoba[o].adres,new_addr);
	setCursor(col,row+19);printf("Nacisnij dowolny klawisz aby kontynuowac");getch();
	fclose(plik);
	system("cls");

}//change_ADDR

//funkcja setCursor nie jest napisana przeze mnie, zapo¿yczona z internetu, korzysta z biblioteki <windows.h>
void setCursor(int x, int y)
{
     COORD c;
     c.X = x-1;
     c.Y = y-1;
     SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), c);
}//setCursor
