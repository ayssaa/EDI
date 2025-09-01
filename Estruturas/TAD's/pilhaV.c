// Implementando TAD Pilha (vetor)
# include <stdlib.h>
# include <stdio.h>
# define MAX 10

typedef struct pilha {
    float info[MAX];
    int n; // quantidade de elementos
} Pilha;

Pilha* criarPilha() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    if(p == NULL) {
        printf("Erro ao alocar espaço para Pilha!");
        return NULL;
    }
    else {
        p->n = 0;
        return p;
    }
}

int estaCheia(Pilha *p) {
    return(p->n == MAX);
}

int estaVazia(Pilha *p) {
    return(p->n == 0);
}

void push(Pilha *p, float v) { // sempre no início
    if(estaCheia(p) == 1) {
        printf("A pilha está cheia!");
    }
    else {
        p->info[p->n] = float v;
        p->n += 1;
    }
}

void imprimePilha(Pilha *p)´{
    if(estaVazia(p) == 1) {
        printf("A pilha está vazia!");
    }
    else {
        for(int i = ((p->n)-1); i >= 0; i--) {
            printf("%.2f ", p->info[i]);
        }
    }
}

float pop(Pilha *p) { // sempre no início
    if(estaVazia(p) == 1) {
        printf("A pilha está vazia!");
    }
    else {
        float v = p->info[(p->n)-1];
        p->n -= 1;
        return v;
    }
}

void liberarPilha(Pilha *p) {
    free(p);
}

void main() {
    
}
