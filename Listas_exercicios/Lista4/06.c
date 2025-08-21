// Fazendo a questão 6
# include <stdio.h>
# include <stdlib.h>

typedef struct arvore {
    int chave;
    struct arvore *esq;
    struct arvore *meio;
    struct arvore *dir;
}

int qntNos(Arvore *arv) {
    if(arv != NULL) { // if (estaVazia(arv) != 1)
        return 1 + qntNos(arv->esq) + qntNos(arv->meio) + qntNos(arv->dir);
    }
    else {
        return 0;
    }
}