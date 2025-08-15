// Pilhas

# include <stdio.h>
# include <stdlib.h>
# define MAX 10

typedef struct pilha {
    float info[MAX]; 
    int n; // quantidade de elementos e posição da inserção/remoção
} Pilha;

Pilha* criarPilha() {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha)); // aloca espaço para uma Pilha
    p->n = 0;
    return p;
}

int estaVazia(Pilha *p) {
    return (p->n == 0);
}

int estaCheia(Pilha *p) {
    return (p->n == MAX);
}

void push(Pilha *p, float v) {
    if (estaCheia(p) == 1) {
        printf("A pilha está cheia!");
    }
    else {
        p->info[p->n] = v;
        p->n += 1;
    }
}

void imprimePilha(Pilha *p) {
    if (estaVazia(p) == 1) {
        printf("A pilha está vazia!");
    }
    else {
        for(int i = (p->n)-1; i >= 0; i--) {
            printf("%.2f ", p->info[i]);
        }
    }
        
}

float pop(Pilha *p) {
    if(estaVazia(p) == 1) {
        printf("A pilha está vazia!");
    }
    else {
        float v = p->info[(p->n)-1]; // v = valor na posição topo
        p->n -= 1;
        return v;
    }
}

void liberarPilha(Pilha *p) {
    free(p);
}

void main() {
    // Criando uma pilha
    Pilha *pilha;
    pilha = criarPilha();
    
    // Inserindo valores na pilha
    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 3);
    
    // Imprimindo a lista
    imprimePilha(pilha);
    
    // pop
    printf("%.2f", pop(pilha));
}