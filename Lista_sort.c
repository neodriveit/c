#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   int key;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void printList() {
   struct node *ptr = head;
   while(ptr != NULL) {
      printf("%d, ",ptr->data);
      ptr = ptr->next;
   }
}


void insertElement(int key, int data) {
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = key;
   link->data = data;
   link->next = head;
   head = link;
}

void sort() {
	int *p_min = head;
	int *p = next;
	while(p!=NULL) {
		if((p->data)<(p_min->data)) p_min = p;
	}
}

int main(){
	insertElement(1,4);
	insertElement(2,7);
	insertElement(3,3);
	insertElement(4,1);
	insertElement(5,5);
	insertElement(6,6); 
	insertElement(7,9);
	insertElement(8,8); 
	insertElement(9,2);
	insertElement(10,7); 

   printf("Lista nieposortowana:\n"); 
   printList();	
   
   sort();
   
   printf("Lista posortowana:\n"); 
   printList();	
}

