// Implementando uma Pilha usando Vetores!
# include <stdio.h>
# include <stdlib.h>
# define MAX 10

typedef struct pilha {
    float info[MAX]; // vetor com os dados da pilha
    int n; // quantidade total de elementos na pilha
} Pilha;

Pilha* criarPilha() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0;
    return p;
}

int estaVazia(Pilha *p) {
    return(p->n==0);
}

int estaCheia(Pilha *p) {
    return(p->n==MAX);
}

void push(Pilha *p, float v) {
    if(estaCheia(p) == 1) {
        printf("A pilha está Cheia!");
    }
    else {
        p->info[p->n] = v;
        p->n += 1;
    }
}

void imprime(Pilha *p) {
    if (estaVazia(p) == 1) {
        printf("A pilha está Vazia!");
    }
    else {
        for(int i = (p->n)-1; i >= 0; i--) {
            printf("%.2f ", p->info[i]);
        }
    }
}

float pop(Pilha *p) {
    if(estaVazia(p) == 1) {
        printf("A pilha está Vazia!");
    }
    else {
        float v = p->info[(p->n)-1]; // v = valor na posição topo
        p->n -= 1;
        return v;
    }
}

float verTopo(Pilha *p) { // Considerando que a pilha não está vazia
    float v = p->info[(p->n)-1];
    return v;
}

void main() {
    // Criando uma Pilha
    Pilha *pilha;
    pilha = criarPilha(); // ponteiro pilha aponte para onde *p aponta!
    
    // Inserindo valores na Pilha
    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 3);
    
    // Mostrando a Pilha
    imprime(pilha);
    
    // Vendo o topo da Pilha
    printf("\nO topo da pilha é: %.2f", verTopo(pilha));
    
    // Removendo um valor da Pilha
    pop(pilha);
    
    // Mostrando a Pilha pós pop
    printf("\n");
    imprime(pilha);
    
    // Vendo o topo da Pilha pós pop
    printf("\nO topo da pilha é: %.2f", verTopo(pilha));
    
}