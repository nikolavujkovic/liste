#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int main(){
	ptr_nodo head;
	head = NULL;
	head = inserisciintesta(head, 1);
	instesta(&head, 2);
	head = inserisciincoda(head, 3);
	head = inscoda_ric(head, 4);
	
	visualizza(head);
	printf("lungezza %d \n", lungezza(head));
	printf("lungezza ric %d \n", lungezza_ric(head));
	printf("cerca 2 %p \n", cerca(head, 2));
	printf("cerca ric 2 %p \n", cerca_ric(head, 2));
	printf("esiste 2? %d \n", esiste(head, 2));
	printf("esiste 5? %d \n", esiste(head, 5));
	
	visualizza_ric(head);
	head = cancellatesta(head);
	head = cancellaultimo(head);
	head = inserisciincoda(head, 2);
	head = inscoda_ric(head, 2);
	visualizza_ric(head);
	
	head = rimuovi(head, 2);
	
	head = ins_ordine(head, 4);
	head = ins_ordine(head, 4);
	visualizza(head);
	
	head = rimuovitutti(head, 4);
	visualizza(head);
	/* non dovrebbe dare un errore */
	head = rimuovi(head, 15);
	
	head = distruggilista(head);
	visualizza(head);
	
	return 0;
}
