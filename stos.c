#include <stdio.h> 
#include <stdlib.h> 
#define MAX 10
int stack[MAX] = {333,222,444};
int top;
void display(int []); 
void push(int [],int);  
int pop(int []); 

void main() 
{
int item=0;
int choice=0;     
top = 3;
	while(1) 
	{	printf("\nWybierz (1: pokaz (display), 2: wstaw (push), 3: usun (pop)), 4: Koniec..:");         
		scanf("%d",&choice);         
		switch(choice) 
		{	case 1: display(stack);  break;             
			case 2: printf("podaj liczbe ktora mam wstawic :");                 
			scanf("%d",&item);                 
			printf(" wstawiam %d\n",item);                 
			push(stack,item); break;             
			case 3: pop(stack); break;             
			case 4: exit(0) ;
			default: printf("\nZla opcja"); break;         
		}//switch   
	}//while(1) 
}//main

void display(int stack[])
{
int i;
int t=0;
	for(i=MAX;i>=0;i--)
	{
		if(stack[i])
		{	printf("%d",stack[i]);
			if(t==0){printf(" <<<top");t=1;}
			printf("\n");
		}//if
	}//for
}//display

void push(int stack[], int item)
{	stack[top]=item;top++;
}//push

int pop(int stack[])
{	printf("usuwam %d", stack[top-1]);stack[top-1]=0;top--;
}//pop
