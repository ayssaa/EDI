// Implementando uma Árvore Binária de Busca
# include <stdio.h>
# include <stdlib.h>

typedef struct arvore {
	int info;
	struct arvore *esq;
	struct arvore *dir;
} Arvore;

int estaVazia(Arvore* arv) {
	return(arv == NULL);
}

void imprimeArvore(Arvore* arv) { // ordem simétrica ou ordem crescente!
	if(estaVazia(arv) != 1) {
		imprimeArvore(arv->esq);
		printf("%d ", arv->info);
		imprimeArvore(arv->dir);
	}
}

Arvore* liberarArvore(Arvore* arv) {
	if(estaVazia(arv) != 1) {
		liberarArvore(arv->esq);
		liberarArvore(arv->dir);
		free(arv);
	}
	else {
		return NULL;
	}
}

int pertenceArvore(Arvore* arv, int v) {
	if(estaVazia(arv) != 1) {
		if(arv->info == v) {
			return 1;
		}
		return (pertenceArvore(arv->esq, v) || pertenceArvore(arv->dir, v));
	}
	else {
		return 0;
	}
}

// Funçoes da Árvore Binária de Busca
Arvore* buscaArvore(Arvore* arv, int v) {
	if(estaVazia(arv)!= 1) {
		if(arv->info == v) {
			return arv;
		}
		else if(arv->info > v) {
			return buscaArvore(arv->esq, v);
		}
		else {
			return buscaArvore(arv->dir, v);
		}
	}
	else {
		return NULL;
	}
}

Arvore* insereArvore(Arvore* arv, int v) {
	if(arv == NULL) {
		arv = (Arvore*) malloc(sizeof(Arvore));
		arv->info = v;
		arv->esq = NULL;
		arv->dir = NULL;
	}
	else if(arv->info > v) {
		arv->esq = insereArvore(arv->esq, v);
	}
	else {
		arv->dir = insereArvore(arv->dir, v);
	}
	return arv;
}

Arvore* retira(Arvore* arv, int v) {
	if(estaVazia(arv) == 1) {
		return NULL;
	}
	else {
	    if(arv->info == v) { // Achei o nó
	       // ele tem 0 filhos (folha)
	       if(arv->esq == NULL && arv->dir == NULL) {
				free(arv);
				arv = NULL;
			}
	       // ele tem 1 filhos à esquerda
	       else if(arv->dir == NULL) {
				Arvore *temp = arv;
				arv = arv->esq;
				free(temp);
			}
	       // ele tem 1 filhos à direita
	       else if(arv->esq == NULL) {
				Arvore *temp = arv;
				arv = arv->dir;
				free(temp);
			}
	       // ele tem 2 filhos
	       else {
	           Arvore *temp = arv->esq;
	           while(temp->dir != NULL) {
	               temp = temp->dir;
	           }        
	           arv->info = temp->info;
	           temp->info = v;
	           arv->esq = retira(arv->esq, v);
	       }
	    }
		else if(arv->info > v) {
			arv->esq = retira(arv->esq, v);
		}
		else {
			arv->dir = retira(arv->dir, v);
		}
	}
	return arv;
}

void main() {
	// Criando a Árvore
	Arvore *arvore = NULL;

	// Inserindo elementos na Árvore
	arvore = insereArvore(arvore, 2);
	arvore = insereArvore(arvore, 1);
	arvore = insereArvore(arvore, 4);
	arvore = insereArvore(arvore, 3);
	arvore = insereArvore(arvore, 5);

	// Vendo minha Árvore
    imprimeArvore(arvore);
    
    // Buscando valor
    printf("\n");
    Arvore *buscando = buscaArvore(arvore, 4);
    imprimeArvore(buscando);
    
    // Removendo a raíz
    arvore = retira(arvore, 2);
    
    // Vendo a árvore depois de remover
    printf("\n");
    imprimeArvore(arvore);
}