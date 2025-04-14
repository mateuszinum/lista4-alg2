#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct TNo {
	char *valor;
	struct TNo *dir, *esq;
};


bool busca_arvore_binaria(struct TNo **l, char *alvo) {
	if (*l == NULL) {
		return false;
	}
	if (strcmp((*l)->valor, alvo) == 0) {
		return true;
	}
	if (strcmp(alvo,(*l)->valor) < 0) {
		return busca_arvore_binaria(&(*l)->esq, alvo);
	}
	return busca_arvore_binaria(&(*l)->dir, alvo);
}


bool insere_arvore_binaria(struct TNo **l, char *info) {
	if (*l == NULL) {
		struct TNo *novo;
		novo = (struct TNo*)malloc(sizeof(struct TNo));
		if (novo == NULL) {
			return false;
		}
		novo->valor = info;
		novo->dir = NULL;
		novo->esq = NULL;
		*l = novo;
		return true;
	}
	if (strcmp((*l)->valor,info) == 0) {
		return false;
	}
	if (strcmp(info, (*l)->valor) < 0) {
		return insere_arvore_binaria(&(*l)->esq, info);
	}
	return insere_arvore_binaria(&(*l)->dir, info);
}


void escreve_arvore_binaria(struct TNo *l) {
	if (l != NULL) {
		escreve_arvore_binaria(l->esq);
		printf("%s\n", l->valor);
		escreve_arvore_binaria(l->dir);
	}
}


bool cria(struct TNo **l) {
	*l = NULL;
	return true;
}

void destroi(struct TNo **l) {
	if (*l != NULL) {
		destroi(&(*l)->esq);
		destroi(&(*l)->dir);
		free(*l);
	}
}

int main(int argc, char *argv[]) {
	struct TNo *arvore;
	cria(&arvore);
	
	insere_arvore_binaria(&arvore, "giovana");
	insere_arvore_binaria(&arvore, "guilherme");
	insere_arvore_binaria(&arvore, "arthur");
	insere_arvore_binaria(&arvore, "pedro");
	insere_arvore_binaria(&arvore, "andre");
	insere_arvore_binaria(&arvore, "mateus");

	escreve_arvore_binaria(arvore);


	destroi(&arvore);
	return 0;
}
