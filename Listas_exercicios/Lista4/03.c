// Implementando uma árvore binária de busca para responder a 3)
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

Arvore* insereArvore(Arvore* a, int v) {
    if(a == NULL){
        a = (Arvore*) malloc(sizeof(Arvore));
        a->info = v;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if (a->info > v){
        a->esq = insereArvore(a->esq, v);
    }
    else {
        a->dir = insereArvore(a->dir, v);
    }
    return a;
}

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

void imprimeArvore(Arvore* arv) { // ordem simétrica ou ordem crescente!
	if(estaVazia(arv) != 1) {
		imprimeArvore(arv->esq);
		printf("%d ", arv->info);
		imprimeArvore(arv->dir);
	}
}

// 3) 
int maiorValor(Arvore *a) {
    if(estaVazia(a) != 1) {
        if(a->dir == NULL) {
            int maior = a->info;
            return maior;
        }
        return maiorValor(a->dir);
    }
    else {
        return -1;
    }
}

void main() {
    // Criando a Árvore
	Arvore *arvore = NULL;

	// Inserindo elementos na Árvore
	arvore = insereArvore(arvore, 2);
	arvore = insereArvore(arvore, 1);
	arvore = insereArvore(arvore, 4);

	// Vendo minha Árvore
    imprimeArvore(arvore);
    
    // O maior valor
    printf("\nO maior valor na árvore é %d", maiorValor(arvore));
}