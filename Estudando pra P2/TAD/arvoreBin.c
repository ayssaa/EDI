// Implementando TAD arvore (apenas binária)
# include <stdlib.h>
# include <stdio.h>

typedef struct arvore {
    int info;
    struct arvore *esq;
    struct arvore *dir;
} Arvore;

Arvore* criarArvoreVazia() {
    return NULL;
}

Arvore* criarArvore(int n, Arvore* sae, Arvore* sad) {
    Arvore *arv = (Arvore*) malloc(sizeof(Arvore));
    if(arv == NULL) {
        printf("Erro ao alocar espaço!");
    } 
    else {
        arv->info = n;
        arv->esq = sae;
        arv->dir = sad;
    }
    return arv;
}

int estaVazia(Arvore *arv) {
    return (arv == NULL);
}

int pertenceArvore(Arvore *arv, int n) {
    if(estaVazia(arv) != 1) {
        if(arv->info == n) {
            return 1;
        }
        else {
            return (pertenceArvore(arv->esq, n) || pertenceArvore(arv->dir, n));
        }
    }
    else {
        return 0;
    }
}

void imprimeArvore(Arvore *arv) { // Pré Ordem (raíz, esq, dir)
    printf("<");
    if(estaVazia(arv) != 1) {
        printf("%d ", arv->info); // raiz
        imprimeArvore(arv->esq); // esq
        imprimeArvore(arv->dir); // dir
    }
    printf(">");
}

Arvore* liberar(Arvore *arv) {
    if(estaVazia(arv) != 1) {
        arv->esq = liberar(arv->esq);
        arv->dir = liberar(arv->dir);
        free(arv);
    }
    return NULL;
}

void main() {
    
}
