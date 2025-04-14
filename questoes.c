#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TNo {
    int info;         
    struct TNo *prox;     
};

void insere_ordenado(struct TNo **l, int x);
void escreve_lista(struct TNo *l);
void destroi(struct TNo **l);
void insere(struct TNo **lista, float x);





// Questão 6 
bool verifica_ordem_ascendente(struct TNo *lista) {
    if (lista == NULL) {
        return false;
    }
    if (lista->prox == NULL) {
        return true;
    }
    if (lista->info > lista->prox->info) {
        return false;
    }
    return verifica_ordem_ascendente(lista->prox);
}


// Questão 3 - Recursiva
bool verifica_se_x_aparece_antes_de_y(struct TNo *lista, float x, float y) {

    bool verifica(bool apareceu, struct TNo *lista) {
        if (lista == NULL) {
            return false;
        }
        if (apareceu) {
            if (lista->info == y || lista->info == x) {
                return true;
            }
            return verifica(apareceu, lista->prox);
        }
        if (lista->info == x) {
            return verifica(true, lista->prox);
        }
        return verifica(false, lista->prox);
    }
    return verifica(false, lista);
}


// Questão 13 - Iterativa
void troca_ultimo_com_primeiro(struct TNo **lista) {
	struct TNo *penultimo, *ultimo;
	ultimo = *lista;
	if (ultimo != NULL && ultimo->prox != NULL) {
		penultimo = NULL;
		while (ultimo->prox != NULL) {
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}
		penultimo->prox = *lista;
		ultimo->prox = (*lista)->prox;
		(*lista)->prox = NULL;
		*lista = ultimo;
	} else {
		return; // não precisa disso no zezinhol
	}
}


// Questão 12 - Iterativa
bool remove_valores_maiores_ou_iguais(struct TNo **lista, int x) {
	struct TNo *ant, *p, *lixo;
	bool removeu = false;
	ant = NULL;
	p = *lista;
	while (p != NULL) {
		if (p->info >= x) {
			lixo = p;
			p = p->prox;
			free(lixo);
			if (ant == NULL) {
				*lista = p;
			} else {
				ant->prox = p;
			}
			removeu = true;
		} else {
			ant = p;
			p = p->prox;
		}
	}
	return removeu;
}


// Questão 12 - Recursiva
bool remover(struct TNo **l, int x) {
	struct TNo *lixo;
	if (*l == NULL) {
		return false;
	}
	if ((*l)->info >= x) {
		lixo = *l;
		*l = (*l)->prox;
		free(lixo);
		return remover(l, x) || true;
	}
	return remover(&(*l)->prox, x);
}


// Questão 15 - Iterativa
struct TNo* copialista(struct TNo *l) {
	struct TNo *l2, *p, *novo;
	l2 = (struct TNo*)malloc(sizeof(struct TNo));
	l2->info = l->info;
	l2->prox = NULL;
	p = l2;
	l = l->prox;
	while (l != NULL) {
		novo = (struct TNo*)malloc(sizeof(struct TNo));
		novo->info = l->info;
		novo->prox = NULL;
		p->prox = novo;
		p = novo;
		l = l->prox;
	}
	printf("Nova lista\n");
	escreve_lista(l2);
}


// Questão 15 - Recursiva by Kauan
struct TNo* copia(struct TNo *l) {
	struct TNo *l2, *novo;
	if (l == NULL) {
		l2 = NULL;
		return l2;
	}
	novo = (struct TNo*)malloc(sizeof(struct TNo));
	novo->info = l->info;
	novo->prox = copia(l->prox);
	l2 = novo;
	printf("Nova lista\n");
	escreve_lista(l2);
	return l2;
}


// Questão 4 - Iterativa
bool verifica_igualdade_entre_l_e_t(struct TNo *l, struct TNo *t) {
	while (l != NULL && t != NULL) {
		if (l->info != t->info) {
			return false;
		}
		l = l->prox;
		t = t->prox;
	}
	if (l == NULL && t == NULL) {
		return true;
	}
	return false;
}


// Questão 4 - Recursiva
bool verifica_igualdade_entre_l_e_t_recursiva(struct TNo *l, struct TNo *t) {
	if (l == NULL && t == NULL) {
		return true;
	}
	if (l == NULL || t == NULL) {
		return false;
	}
	if (l->info != t->info) {
		return false;
	}
	return verifica_igualdade_entre_l_e_t(l->prox, t->prox);
}


// Questão 5
bool todo_elemento_de_L_aparece_em_T(struct TNo *l, struct TNo *t) {
	if (l == NULL) {
		return false;
	}
	bool resultado = true;
	while (l != NULL && resultado) {
		struct TNo *p = t;
		bool achou = false;
		while (p != NULL && !achou) {
			if (l->info == p->info) {
				achou = true;
			}
			p = p->prox;
		}
		if (!achou) {
			resultado = false;
		}
		l = l->prox;
	}
	return resultado;
}


// Questão 7
bool insere_x_no_inicio_de_l(struct TNo **l, int x) {
	struct TNo *novo;
	novo = (struct TNo*)malloc(sizeof(struct TNo));
	if (novo == NULL) {
		return false;
	}
	novo->info = x;
	novo->prox = *l;
	*l = novo;
	return true;
}


// Questão 8 - Iterativa
bool insere_x_no_fim_de_l(struct TNo **l, int x) {
	struct TNo *novo, *p;
	p = *l;
	novo = (struct TNo*)malloc(sizeof(struct TNo));
	if (novo == NULL) {
		return false;
	}
	novo->info = x;
	novo->prox = NULL;
	if (*l == NULL) {
		*l = novo;
	} else {
		while (p->prox != NULL) {
			p = p->prox;
		}
		p->prox = novo;
	}
	return true;
}


// Questão 8 - Recursiva
bool insere_x_no_fim_de_l_recursiva(struct TNo **l, int x) {
	struct TNo *novo;
	if (*l == NULL) {
		novo = (struct TNo*)malloc(sizeof(struct TNo));
		if (novo == NULL) {
			return false;
		}
		novo->info = x;
		novo->prox = NULL;
		*l = novo;
		return true;
	}
	return insere_x_no_fim_de_l_recursiva(&(*l)->prox, x);
}


// Questão 13 - Recursiva
void troca_ultimo_com_primeiro_recursivo(struct TNo **lista) {
	struct TNo *p, *ultimo;
	
	void percorre_h(struct TNo **h) {
		if ((*h)->prox->prox == NULL) {
			ultimo = (*h)->prox;
			ultimo->prox = (*lista)->prox;
			(*h)->prox = *lista;
			(*lista)->prox = NULL;
			*lista = ultimo;
		} else {
			percorre_h(&(*h)->prox);
		}
	}
	
	p = *lista;
	if (p != NULL && p->prox != NULL){
		if (p->prox->prox == NULL) {
			ultimo = p->prox;
			ultimo->prox = *lista;
			(*lista)->prox = NULL;
			*lista = ultimo;
		} else {
			percorre_h(&p);
		}
	}
}


// Questão 1 - PROVA DRIVE
bool insere_ordenado_recursivo(struct TNo **l, int x) {
	struct TNo *novo;
	if (*l == NULL || (*l)->info > x) {
		novo = (struct TNo*)malloc(sizeof(struct TNo));
		if (novo == NULL) {
			return false;
		}
		novo->info = x;
		novo->prox = *l;
		*l = novo;
		return true;
	}
	return insere_ordenado_recursivo(&(*l)->prox, x);
}


// Questão 2 - PROVA DRIVE - André
void altere(struct TNo **l) {
	struct TNo *refer, *p, *a;
	int aux;
	a = *l;
	if (a != NULL) {
		p = a;
		while (p->prox != NULL) {
			p = p->prox;
		}
		refer = p;
		while (a != refer) {
			aux = a->info;
			a->info = refer->info;
			refer->info = aux;
			if (a->prox == refer) {
				a = refer;
			} else {
				p = a;
				while (p->prox != refer) {
					p = p->prox;
				}
				refer = p;
				a = a->prox;
			}
		}
	}
}


// Questão 16 - Iterativa
void separa_pares_de_impares(struct TNo **lista1, struct TNo **lista2) {

	struct TNo *ant, *p, *f, *novo, *lixo;

	ant = NULL;
	p = *lista1;
	f = *lista2;

	while (p != NULL) {
		if (p->info % 2 != 0) {
			novo = (struct TNo*)malloc(sizeof(struct TNo));
			if (novo != NULL) {
				novo->info = p->info;
				novo->prox = NULL;
				if (f == NULL) {
					*lista2 = novo;
				} else {
					f->prox = novo;
				}
				lixo = p;
				if (ant == NULL) {
					*lista1 = p->prox;
				} else {
					ant->prox = p->prox;
				}
				p = p->prox;
				f = novo;
				free(lixo);
			}
		} else {
			ant = p;
			p = p->prox;
		}
	}
	escreve_lista(*lista1);
	escreve_lista(*lista2);
}


// Questão 2 - Prova Drive
void inverte_lista(struct TNo **l) {
	if (*l != NULL) {
		struct TNo *anterior, *atual, *proximo;
		anterior = NULL;
		atual = *l;
		while (atual != NULL) {
			proximo = atual->prox;
			atual->prox = anterior;
			anterior = atual;
			atual = proximo;
		}
		*l = anterior;
	}
}

int main() {
	struct TNo *lista = NULL;
	struct TNo *lista2 = NULL;
	
	
	insere_ordenado_recursivo(&lista, 5);
	insere_ordenado_recursivo(&lista, 3);
	insere_ordenado_recursivo(&lista, 4);
	insere_ordenado_recursivo(&lista, 8);
	insere_ordenado_recursivo(&lista, 10);
	insere_ordenado_recursivo(&lista, 1);


	separa_pares_de_impares(&lista, &lista2);


	destroi(&lista);


    return 0;
}

// Faltam:
// 14 - Recursiva; 15; 16 - Recursiva;

// Faltam - Prova Passada:
//

// Faltam - Prova Drive:
// 4;

// Arrumar:
// (testar a de inverter e de separar impar e par)
