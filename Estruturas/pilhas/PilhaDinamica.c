// Implementando uma Pilha usando Lista Simplesmente Encadeada!
# include <stdlib.h>
# include <stdio.h>

typedef struct noLista {
    float info;
    struct noLista *prox;
} NoLista;

typedef struct pilha {
    NoLista *prim; // ponteiro para o topo
} Pilha;

Pilha* criarPilha() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

int estaVazia(Pilha *p) {
    return (p->prim == NULL);
}

void push(Pilha *p, float v) {
    NoLista *novono = (NoLista*) malloc(sizeof(NoLista));
    if(novono == NULL) {
        printf("Erro ao dar Push!");
    }
    else {
        novono->info = v;
        novono->prox = p->prim;
        p->prim = novono;
    }
}

void imprimir(Pilha *p) {
    if(estaVazia(p) == 1) {
        printf("A pilha está vazia!");
    }
    else {
        for(NoLista *no = p->prim; no != NULL; no = no->prox) {
            printf("%.2f ", no->info);
        }
    }
}

float pop(Pilha *p) {
    if(estaVazia(p) == 1) {
        printf("A pilha está vazia!");
    }
    else {
        NoLista *topo = p->prim;
        float v = topo->info;
        p->prim = topo->prox;
        free(topo);
        return v;
    }
}

void liberar(Pilha *p) {
    NoLista *no, *temp;
    for(no = p->prim; no != NULL; no = temp){
        temp = no->prox;
        free(no);
    }
    free(p);
}

float verTopo(Pilha *p) { // considerando que não está vazia
    return p->prim->info;
}

void main() {
    // Criando a Pilha dinamica
    Pilha *pilha;
    pilha = criarPilha();
    
    // Inserindo na pilha
    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 3);
    
    // Vendo Pilha
    imprimir(pilha);
    
    // Removendo um elemento
    pop(pilha);
    
    // Vendo Pilha
    printf("\n");
    imprimir(pilha);
    
    // Vendo o topo da Pilha
    printf("\nO topo da pilha é %.2f", verTopo(pilha));
}
