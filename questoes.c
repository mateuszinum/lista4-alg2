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

void insere_ordenado(struct TNo **l, int x);
void insere_ordenado_recursivo(struct TNo **l, int x);
void escreve_lista(struct TNo *l);
void escreve_lista_duplamente(struct Tno *l);
void escreve_lista_duplamente_inverso(struct Tno *lista);
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
bool remove_maiores_ou_iguais_recursiva(struct TNo **l, int x) {
	struct TNo *lixo;
	if (*l == NULL) {
		return false;
	}
	if ((*l)->info >= x) {
		lixo = *l;
		*l = (*l)->prox;
		free(lixo);
		return remove_maiores_ou_iguais_recursiva(l, x) || true;
	}
	return remove_maiores_ou_iguais_recursiva(&(*l)->prox, x);
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
struct TNo* copia_lista_recursiva(struct TNo *l) {
	struct TNo *l2, *novo;
	if (l == NULL) {
		l2 = NULL;
		return l2;
	}
	novo = (struct TNo*)malloc(sizeof(struct TNo));
	novo->info = l->info;
	novo->prox = copia_lista_recursiva(l->prox);
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
		while (p != NULL) {
			p = p->prox;
		}
		p = novo;
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


// Questão 11 - Recursiva - Arthur
bool remove_ultimo_arthur(struct TNo **lista) {
	if (*lista == NULL) {
		return false;
	}
	if ((*lista)->prox == NULL) {
		free(*lista);
		*lista = NULL;
		return true;
	}
	return remove_ultimo_arthur(&(*lista)->prox);
}


// bool par_impar_guilherme(struct TNo **par, struct TNo **impar, struct TNo *l) {
	
// 	struct TNo *p, *i;

// 	void insere() {
// 		*par = (struct TNo*)malloc(sizeof(struct TNo));
// 		*impar = (struct TNo*)malloc(sizeof(struct TNo));
// 		p = *par;
// 		i = *impar;
// 		while (l != NULL) {
// 			if (l->info % 2 == 0) {
// 				if (p != NULL) {
// 					p->info = l->info;
// 					p->prox = NULL;
// 					p = p->prox;
// 					p = (struct TNo*)malloc(sizeof(struct TNo));
// 				}
// 			} else {
// 				if (i != NULL) {
// 					i->info = l->info;
// 					i->prox = NULL;
// 					i = i->prox;
// 					i = (struct TNo*)malloc(sizeof(struct TNo));
// 				}
// 			}
// 			l = l->prox;
// 		}
// 	}
// 	if (l != NULL && *par == NULL && *impar == NULL) {
// 		insere();
// 	}
// }



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


// Questão 14 - Recursiva
bool soma_posicao(struct TNo **l, int p) {
	
	bool procura_posicao(struct TNo **n, int pos) {
		struct TNo *proximo;
		if ((*n)->prox == NULL) {
			return false;
		}
		if (pos == p) {
			(*n)->prox->info = (*n)->info + (*n)->prox->info;
			return true;
		}
		procura_posicao(&(*n)->prox, pos + 1);
	}
	
	if (*l == NULL || (*l)->prox == NULL || p <= 0) {
		return false;
	}
	procura_posicao(&(*l), 1);
} 


// Questão 16 - Iterativa
void separa_pares_de_impares(struct TNo *lista, struct TNo **par, struct TNo **impar) {
	struct TNo *novo, *par_tail, *impar_tail;

	par_tail = NULL;
	impar_tail = NULL;

	if (*par == NULL && *impar == NULL) {
		while (lista != NULL) {
			novo = (struct TNo*)malloc(sizeof(struct TNo));
			if (novo != NULL) {
				novo->info = lista->info;
				novo->prox = NULL;
				if (lista->info % 2 != 0) {
					if (*par == NULL) {
						*par = novo;
						par_tail = novo;
					} else {
						par_tail->prox = novo;
						par_tail = novo;
				}
				} else {
					if (*impar == NULL) {
						*impar = novo;
						impar_tail = novo;
					} else {
						impar_tail->prox = novo;
						impar_tail = novo;
					}
				}
				lista = lista->prox;
			}
		}
	}
}


// Questão 4 - Prova Drive - by Deepseek

// struct TNo* somarPolinomios(struct TNo *p1, struct TNo *p2) {
//     struct TNo *resultado = NULL;
//     struct TNo *atual = NULL;
    
//     while (p1 != NULL || p2 != NULL) {
//         struct TNo *novo = NULL;
//         int exp1, exp2;
        
//         // Determinar exp1 sem operador ternário
//         if (p1 != NULL) {
//             exp1 = p1->expoente;
//         } else {
//             exp1 = -1;
//         }
        
//         // Determinar exp2 sem operador ternário
//         if (p2 != NULL) {
//             exp2 = p2->expoente;
//         } else {
//             exp2 = -1;
//         }
        
//         if (exp1 > exp2) {
//             novo = (struct TNo*)malloc(sizeof(struct TNo));
//             if (novo == NULL) return NULL;
//             novo->coeficiente = p1->coeficiente;
//             novo->expoente = p1->expoente;
//             novo->prox = NULL;
//             p1 = p1->prox;
//         } 
//         else if (exp2 > exp1) {
//             novo = (struct TNo*)malloc(sizeof(struct TNo));
//             if (novo == NULL) return NULL;
//             novo->coeficiente = p2->coeficiente;
//             novo->expoente = p2->expoente;
//             novo->prox = NULL;
//             p2 = p2->prox;
//         } 
//         else {
//             float soma = p1->coeficiente + p2->coeficiente;
//             if (soma != 0) {
//                 novo = (struct TNo*)malloc(sizeof(struct TNo));
//                 if (novo == NULL) return NULL;
//                 novo->coeficiente = soma;
//                 novo->expoente = p1->expoente;
//                 novo->prox = NULL;
//             }
//             p1 = p1->prox;
//             p2 = p2->prox;
//         }
        
//         if (novo != NULL) {
//             if (resultado == NULL) {
//                 resultado = novo;
//                 atual = novo;
//             } else {
//                 atual->prox = novo;
//                 atual = novo;
//             }
//         }
//     }
    
//     return resultado;
// }


// Questão 1 - Prova Drive
bool insere_ordenado_recursivo_duplamente(struct Tno **lista, int x) {
    if (*lista == NULL || (*lista)->dir == NULL) {
        struct Tno *novo = (struct Tno*)malloc(sizeof(struct Tno));
        if (novo == NULL) {
            return false;
        }
        novo->info = x;
        novo->dir = NULL;
		if (*lista != NULL) {
			novo->esq = *lista;
			(*lista)->dir = novo;
		} else {
			novo->esq = NULL;
			*lista = novo;
		}
        return true;
    }
    
    if ((*lista)->info > x) {
        struct Tno *novo = (struct Tno*)malloc(sizeof(struct Tno));
        if (novo == NULL) {
            return false;
        }

        novo->info = x;
        novo->dir = *lista;
        novo->esq = (*lista)->esq;
        
        if ((*lista)->esq != NULL) {
            (*lista)->esq->dir = novo;
        }

        (*lista)->esq = novo;
        
        if (novo->esq == NULL) {
            *lista = novo;
        }
        
        return true;
    }
    
    return insere_ordenado_recursivo_duplamente(&(*lista)->dir, x);
}


// Questão 16 - Recursiva - by Giovana
void separa_pares_de_impares_recursiva(struct TNo *lista, struct TNo **par, struct TNo **impar) {
	struct TNo *novo;

	if (lista == NULL) {
		*par = NULL;
		*impar = NULL;
	} else {
		if (lista->info % 2 == 0) {
			novo = (struct TNo*)malloc(sizeof(struct TNo));
			if (novo != NULL) {
				novo->info = lista->info;
				novo->prox = NULL;
				*par = novo;
			}
		} else {
			novo = (struct TNo*)malloc(sizeof(struct TNo));
			if (novo != NULL) {
				novo->info = lista->info;
				novo->prox = NULL;
				*impar = novo;
			}
		}

		if (lista->info % 2 == 0 && *par != NULL) {
			separa_pares_de_impares_recursiva(lista->prox, &((*par)->prox), impar);
		} else {
			if (lista->info % 2 != 0 && *impar != NULL) {
				separa_pares_de_impares_recursiva(lista->prox, par, &((*impar)->prox));
			} else {
				separa_pares_de_impares_recursiva(lista->prox, par, impar);
			}
		}
	}
}



int main() {
	struct TNo *lista = NULL;

	struct TNo *par = NULL;
	struct TNo *impar = NULL;

	struct Tno *lista2 = NULL;
	
	insere_ordenado_recursivo(&lista, 5);
	insere_ordenado_recursivo(&lista, 3);
	insere_ordenado_recursivo(&lista, 4);
	insere_ordenado_recursivo(&lista, 8);
	insere_ordenado_recursivo(&lista, 10);
	insere_ordenado_recursivo(&lista, 1);

	escreve_lista(lista);

	separa_pares_de_impares_recursiva(lista, &par, &impar);


	escreve_lista(par);
	escreve_lista(impar);


	destroi(&lista);

    return 0;
}


// Faltam:
// Olhar a 15 recursiva do Kauan, a 16 iterativa, a 1 do drive, a 13 do zezinho, a 12
// Falta a 16 recursiva
// Revisar