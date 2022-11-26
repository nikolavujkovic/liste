/*
	IMPLEMENTAZIONE DELLA LISTA E LE SUE FUNZIONI
		Anno: 2022/2023
		Prof: MIRANDOLA RAFFAELA
		
	Codice scaricato da:
	https://github.com/nikola-vujkovic/liste.git
*/

#include<stdio.h>
#include<stdlib.h>

/* SIMBOLI:
	<!> - funzione dipende da un'altra funzione
	<o> - implementazione NON fatta da prof Mirandola
	<?> - codice potrebbe dare un errore
*/

/* INIZIALIZZAZIONE DELLA LISTA: */
typedef struct nodo{
	int dato;
	struct nodo*next;
}nodo_t;

typedef nodo_t* ptr_nodo;
/**/

/* FUNZIONI PRESENTI IN QUESTO FILE: */
	void visualizza(ptr_nodo l);
	void visualizza_ric(ptr_nodo l);
	int lungezza(ptr_nodo l);
	int lungezza_ric(ptr_nodo l);
	ptr_nodo cerca(ptr_nodo l, int num);
	ptr_nodo cerca_ric(ptr_nodo l, int num);
	int esiste(ptr_nodo l, int num);
	ptr_nodo inserisciintesta(ptr_nodo l, int num);
	void instesta(ptr_nodo *l, int num);
	ptr_nodo inserisciincoda(ptr_nodo l, int num);
	ptr_nodo inscoda_ric(ptr_nodo l, int num); /* <!> */
	ptr_nodo cancellatesta(ptr_nodo l);
	ptr_nodo cancellaultimo(ptr_nodo l); /* <o> */
	ptr_nodo rimuovi(ptr_nodo l, int num);
	ptr_nodo rimuovitutti(ptr_nodo l, int num); /* <o> */
	ptr_nodo distruggilista(ptr_nodo l);
	ptr_nodo ins_ordine(ptr_nodo l, int n); /* <!> */
/**/

/* IMPLEMENTAZIONE DELLE FUNZIONI: */
void visualizza(ptr_nodo l){
	while(l){
		printf("%d ", l->dato);
		l = l->next;
	}
	printf("-|\n");
}

void visualizza_ric(ptr_nodo l){
	if(!l)
		printf("-|\n");
	else {
		printf("%d ", l->dato);
		visualizza_ric(l->next);
	}
}

int lungezza(ptr_nodo l){
	int i;
	i=0;
	while(l){
		i++;
		l = l->next;	
	}
	return i;
}

int lungezza_ric(ptr_nodo l){
	if(!l) return 0;
	return (1+lungezza_ric(l->next));
}

ptr_nodo cerca(ptr_nodo l, int num){
	int found;
	found = 0;
	while(l && !found){
		if(l->dato == num) found = 1;
		else l = l->next;
	}
	
	return l;
}

ptr_nodo cerca_ric(ptr_nodo l, int num){
	if(!l || l->dato==num) return l;
	return cerca_ric(l->next, num);
}

int esiste(ptr_nodo l, int num){
	while(l && l->dato!=num)
		l = l->next;
	if(!l) return 0;
	return 1;
}

ptr_nodo inserisciintesta(ptr_nodo l, int num){
	ptr_nodo tmp;
	tmp = malloc(sizeof(nodo_t));
	
	if(tmp){
		tmp->dato = num;
		tmp->next = l;
		l = tmp;
	}
	else
		printf("errore d'allocazione \n");
	
	return l;
}

void instesta(ptr_nodo *l, int num){
	ptr_nodo tmp;
	tmp = malloc(sizeof(nodo_t));
	if(tmp){
		tmp->dato = num;
		tmp->next = *l;
		*l = tmp;
	}
	else printf("errore d'allocazione \n");
}

ptr_nodo inserisciincoda(ptr_nodo l, int num){
	ptr_nodo tmp, prec;
	tmp = malloc(sizeof(nodo_t));
	
	if(tmp){
		tmp->dato = num;
		tmp->next = NULL;
		
		if(!l) l = tmp;
		else {
			for(prec = l; prec->next != NULL; prec = prec->next);
			prec->next = tmp;
		}
	}
	else printf("errore d'allocazione \n");
	
	return l;
}

/* DIPENDE DA inserisciintesta() <!> */
ptr_nodo inscoda_ric(ptr_nodo l, int num){
	if(!l) return inserisciintesta(l, num); 
	l->next = inscoda_ric(l->next, num);
	return l;
}

ptr_nodo cancellatesta(ptr_nodo l){
	ptr_nodo tmp;
	if(l){
		tmp = l;
		l = l->next;
		free(tmp);
	}
	return l;
}

/* era un esercizio da fare per casa <o> */
ptr_nodo cancellaultimo(ptr_nodo l){
	if(!l) return NULL;
	ptr_nodo tmp, prec;
	prec = NULL;
	tmp = l;
	
	while(tmp->next){
		prec = tmp;
		tmp = tmp->next;
	}
	free(tmp);
	if(!prec) return NULL;
	prec->next = NULL;
	
	return l;
}

/*	<?>
	nella lezione non c'era il "&& curr" nel while
	senza esso la funzione da' un errore se non c'e' il numero richiesto
*/
ptr_nodo rimuovi(ptr_nodo l, int num){
	ptr_nodo curr, prec, tmp;
	int found;
	found = 0;
	curr = l;
	prec = NULL;
	
	while(l && !found && curr){
		if(curr->dato == num){
			found = 1;
			tmp = curr;
			curr = curr->next;
			if(prec) prec->next = curr;
			else l = curr;
			free(tmp);
		}
		else {
			prec = curr;
			curr = curr->next;
		}
	}
	
	return l;
}

/* rimuovi(), ma senza la variabile found <o> */
ptr_nodo rimuovitutti(ptr_nodo l, int num){
	ptr_nodo curr, prec, tmp;
	curr = l;
	prec = NULL;
	
	while(l && curr){
		if(curr->dato == num){
			tmp = curr;
			curr = curr->next;
			if(prec) prec->next = curr;
			else l = curr;
			free(tmp);
		}
		else {
			prec = curr;
			curr = curr->next;
		}
	}
	
	return l;
}

ptr_nodo distruggilista(ptr_nodo l){
	ptr_nodo tmp;
	while(l){
		tmp = l;
		l = l->next;
		free(tmp);
	}
	return NULL;
}

/* DIPENDE DA inserisciintesta() <!> */
ptr_nodo ins_ordine(ptr_nodo l, int n){
	if(!l || l->dato>n) return inserisciintesta(l, n);
	l->next = ins_ordine(l->next, n);
	return l;
}

/* --- */