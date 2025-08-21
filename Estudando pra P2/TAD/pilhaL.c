// Implementando TAD Pilha (NoLista)
# include <stdlib.h>
# include <stdio.h>

typedef struct noLista {
    float info;
    struct noLista *prox;
} NoLista;

typedef struct pilha {
    NoLista *prim;
} Pilha;

Pilha* criarPilha() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    if(p == NULL) {
        printf("Erro ao alocar espaço!");
        return NULL;
    }
    else {
        p->prim = NULL;
        return p;
    }
    
}

int estaVazia(Pilha *p) {
    return(p->prim == NULL);
}

void push(Pilha *p, float v) {
    NoLista *novono = (NoLista*) malloc(sizeof(NoLista));
    if(novono==NULL) {
        printf("Erro ao alocar espaço!");
        return;
    }
    else {
        novono->info = v;
        novono->prox = p->prim;
        p->prim = novono;
    }
}

void imprime(Pilha *p) {
    if(estaVazia(p) == 1) {
        printf("Pilha vazia!");
    }
    else {
        for(NoLista *no = p->prim; no != NULL; no = no->prox) {
            printf("%.2f", no->info);
        }
    }
}

float pop(Pilha *p) {
    if(estaVazia(p) == 1) {
        printf("Pilha vazia!");
    }
    else {
        NoLista *topo = p->prim;
        p->prim = topo->prox;
        float v = topo->info;
        free(topo);
        return v;
    }
}

void liberarPilha(Pilha *p) {
    NoLista *no, *temp;
    for(no = p->prim; no != NULL; no = temp) {
        temp = no->prox;
        free(no);
    }
    free(p);
}

void main() {
    
}
