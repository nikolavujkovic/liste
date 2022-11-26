# list.h #

## Contenuto: ##

1. Libreria delle funzioni e implementazione della lista *list.h*
2. Foto di codice di tutte le funzioni (cartella *foto*)
3. Esempio di utilizzo di tutte funzioni (file *esempio.c*)

## Esempio di foto ##

<img src="https://user-images.githubusercontent.com/85709802/204106743-3e4f6cb9-126b-4aee-bdf7-4f777c1468e3.png" width=50% height=50%>


## Come usare: ##

1. Scaricare questo repository (come ZIP)
2. Muovere list.h alla cartela dove si usa la libreria nei programmi
3. Mettere ```#include "list.h"``` nel codice
4. **Usare liste e le sue funzioni nel codice!**


## Esempio del codice ##

```
#include "list.h"

int main(){
    ptr_nodo head;
    head = NULL;
	
    instesta(&head, 1);
    instesta(&head, 2);
    instesta(&head, 3);
    
    visualizza(head);
    return 0;
}
```


## Funzioni disponibili nella libreria: ##
```void visualizza(ptr_nodo l);```

```void visualizza_ric(ptr_nodo l);```

```int lungezza(ptr_nodo l);```

```int lungezza_ric(ptr_nodo l);```

```ptr_nodo cerca(ptr_nodo l, int num);```

```ptr_nodo cerca_ric(ptr_nodo l, int num);```

```int esiste(ptr_nodo l, int num);```

```ptr_nodo inserisciintesta(ptr_nodo l, int num);```

```void instesta(ptr_nodo *l, int num);```

```ptr_nodo inserisciincoda(ptr_nodo l, int num);```

```ptr_nodo inscoda_ric(ptr_nodo l, int num);```

```ptr_nodo cancellatesta(ptr_nodo l);```

```ptr_nodo cancellaultimo(ptr_nodo l);```

```ptr_nodo rimuovi(ptr_nodo l, int num);```

```ptr_nodo rimuovitutti(ptr_nodo l, int num);```

```ptr_nodo distruggilista(ptr_nodo l);```

```ptr_nodo ins_ordine(ptr_nodo l, int n);```
