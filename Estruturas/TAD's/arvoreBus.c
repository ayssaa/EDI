// Implementando TAD arvore binaria de busca
# include <stdio.h>
# include <stdio.h>

typedef struct arvore {
    int info;
    struct arvore *esq;
    struct arvore *dir;
} Arvore;

int estaVazia(Arvore *arv) {
    return (arv == NULL);
}

int pertenceArvore(Arvore *arv, int n) {
    if(estaVazia(arv) != 1) {
        if(arv->info == n) {
            return 1;
        }
        else if(arv->info > n) {
            return pertenceArvore(arv->esq, n);
        }
        else {
            return (pertenceArvore(arv->dir, n));
        }
    }
    else {
        return 0;
    }
}

void imprimeArvore(Arvore *arv) {
    if(estaVazia(arv) != 1) {
        printf("%d ", arv->info);
        imprimeArvore(arv->esq);
        imprimeArvore(arv->dir);
    }
}

Arvore* liberarArvore(Arvore *arv) {
    if(estaVazia(arv) != 1) {
        arv->esq = liberarArvore(arv->esq);
        arv->dir = liberarArvore(arv->dir);
        free(arv);
    }
    return NULL;
}

Arvore* busca(Arvore *arv, int v)  {
    if(estaVazia(arv) != 1) {
        if(arv->info == v) {
            return arv;
        }
        else if(arv->info > v) {
            return busca(arv->esq, v);
        }
        else {
            return busca(arv->dir, v);
        }
    }
    else {
        return NULL;
    }
}

Arvore* insere(Arvore *arv, int v) {
    if(estaVazia(arv) == 1) {
        arv = (Arvore*) malloc(sizeof(Arvore));
        arv->info = v;
        arv->esq = NULL;
        arv->dir = NULL;
    }
    else {
        if(arv->info > v) {
            arv->esq = insere(arv->esq, v);
        }
        if(arv->info < v) {
            arv->dir = insere(arv->dir, v);
        }
    }
    return arv;
}

Arvore* retira(Arvore *arv, int v) {
    if(estaVazia(arv) == 1) {
        return NULL;
    }
    else {
        if(arv->info == v) {
	       if(arv->esq == NULL && arv->dir == NULL) { // 0
	           free(arv);
	           arv = NULL;
	       }

	       else if(arv->esq != NULL && arv->dir == NULL) { // 1 esq
	           Arvore *t = arv;
	           arv = arv->esq;
	           free(t);
	       }

	       else if(arv->esq == NULL && arv->dir != NULL) { // 1 dir
	           Arvore *t = arv;
	           arv = arv->dir;
	           free(t);
	       }

	       else if(arv->esq != NULL && arv->dir != NULL) { // 2
	           Arvore *temp;
	           for(temp = arv->esq; temp->dir != NULL; temp = temp->dir); // acha maior valor a esquerda
	           arv->info = temp->info;
	           temp->info = v;
	           arv->esq = retira(arv->esq, v);
	       }
        }
        else {
            
        }
        else if(arv->info > v) {
            arv->esq = = retira(arv->esq, v);
        }
        else {
            arv->dir = = retira(arv->dir, v);
        }
    }
    return arv;
}

void main() {
    
}