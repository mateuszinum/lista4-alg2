#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TNo {
    int info;         
    struct TNo *prox;     
};

struct Tno {
	int info;
	struct Tno *esq;
	struct Tno *dir;
};


void insere_ordenado(struct TNo **l, int x) {
	struct TNo *p, *ant, *novo;

	ant = NULL;
	p   = *l;
	while(p && x > p->info)
	{
		ant = p;	
		p = p->prox;
	}
	novo = (struct TNo*)malloc(sizeof(struct TNo));
	if(novo)
	{
		novo->info = x;
		novo->prox  = p;
	}

	if(ant)
		ant->prox = novo;
	else
		*l = novo;
}


bool insere_ordenado_recursivo(struct TNo **lista, int x) {
	if (*lista == NULL || (*lista)->info > x) {
		struct TNo *novo;
		novo = (struct TNo*)malloc(sizeof(struct TNo));
		if (novo == NULL) {
			return false;
		}
		novo->info = x;
		novo->prox = *lista;
		*lista = novo;
		return true;
	}
	insere_ordenado_recursivo(&(*lista)->prox, x);
}


void escreve_lista(struct TNo* l) {
	int cont;

	cont = 0;
	while(l) {
		cont++;
		printf("%d elemento: %d\n", cont, l->info);
		l = l->prox;
	}
	printf("\n");

}


void destroi(struct TNo **l) {
    struct TNo *lixo;
    while (*l) {
        lixo = *l;
        *l = (*l)->prox;
        free(lixo);
    }
}


void insere(struct TNo **lista, float x) {
    struct TNo *novo;
    novo = (struct TNo*)malloc(sizeof(struct TNo));
    novo->info = x;
    novo->prox = NULL;

    if (*lista == NULL)
    *lista = novo;
    else {
        struct TNo *p = *lista;
        while (p->prox != NULL)
            p = p->prox;
        p->prox = novo;
    }
}


void escreve_lista_duplamente(struct Tno *l) {
    int cont = 1;
    struct Tno *atual = l;
    
    while (atual != NULL) {
        printf("%d elemento: %d\n", cont, atual->info);
        atual = atual->dir;
        cont++;
    }
    printf("\n");
}


void escreve_lista_duplamente_inverso(struct Tno *lista) {

    struct Tno *atual = lista;
    while (atual->dir != NULL) {
        atual = atual->dir;
    }

    int cont = 1;
    while (atual != NULL) {
        printf("%d elemento (inverso): %d\n", cont, atual->info);
        atual = atual->esq;
        cont++;
    }
}