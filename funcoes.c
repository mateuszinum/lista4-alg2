#include <stdio.h>
#include <stdlib.h>

struct TNo {
    int info;         
    struct TNo *prox;     
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

void escreve_lista(struct TNo* l) {
	struct TNo* p;
	int cont;

	cont = 0;
	p = l;
	while(p) {
		cont++;
		printf("%d elemento: %d\n", cont, p->info);
		p = p->prox;
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
