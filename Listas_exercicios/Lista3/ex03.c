# include <stdio.h>
# include <stdlib.h>

typedef struct noLista {
    float info;
    struct noLista *prox;
} NoLista;

typedef struct pilha {
    NoLista *prim;
} Pilha;

Pilha* criarPilha() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

int estaVazia(Pilha *p) {
    return(p->prim == NULL);
}

void push(Pilha *p, float v) {
    NoLista *novono = (NoLista*) malloc(sizeof(NoLista));
    if(novono == NULL) {
        printf("\nErro ao alocar memória!\n");
    }
    else {
        novono->info = v;
        novono->prox = p->prim;
        p->prim = novono;
    }
}

void imprimirPilha(Pilha *p) {
    if(estaVazia(p) == 1) {
        printf("\nA pilha está Vazia!\n");
    }
    else {
        for(NoLista *no = p->prim; no != NULL; no = no->prox) {
            printf("%.2f ", no->info);
        }
    }
}

float pop(Pilha *p) {
    if(estaVazia(p) == 1) {
        printf("\nA pilha está Vazia!\n");
    }
    else {
        NoLista *topo = p->prim;
        float v = topo->info;
        p->prim = topo->prox;
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

// Letra A)
// Concatenando usando uma pilha auxiliar
void concatenaPilhasA(Pilha *p1, Pilha *p2) {
    Pilha *auxiliar = criarPilha();

    while(estaVazia(p2) != 1) {
        push(auxiliar, pop(p2));
    }

    while(estaVazia(auxiliar) != 1) {
        push(p1, pop(auxiliar));
    }
}

// Letra B)
// Usando recursividade
void concatenaPilhasB(Pilha *p1, Pilha *p2) {
    if(estaVazia(p2) != 1) {
        float v = pop(p2);
        concatenaPilhas(p1, p2);
        push(p1, v);
    }
    else {
        return;
    }
}

// Letra C)
// Sem usar funções prontas
void concatenaPilhasC(Pilha *p1, Pilha *p2) {
    NoLista *no;

    for (no = p2->prim; no != NULL; no = no->prox) {
        if (no->prox == NULL) {
            no->prox = p1->prim;
            p1->prim = p2->prim;
            p2->prim = NULL;
            break;
        }
    }
}

void main() {
    // Criando a P1 e P2
    Pilha *pilha1, *pilha2;
    pilha1 = criarPilha();
    pilha2 = criarPilha();

    // Inserindo valores para cada Pilha
    // Pilha 1
    push(pilha1, 1);
    push(pilha1, 2);
    push(pilha1, 3);

    // Pilha 2
    push(pilha1, 4);
    push(pilha1, 5);
    push(pilha1, 6);

    // Vendo cada Pilha
    // Pilha 1
    printf("Pilha 1: ");
    imprimirPilha(pilha1);
    printf("\n");

    // Pilha 2
    printf("Pilha 2: ");
    imprimirPilha(pilha2);
    printf("\n");

    // Letra A)
    /*
    concatenaPilhasA(pilha1, pilha2);
    printf("Pilha Concatenada: ");
    imprimirPilha(pilha1);
    printf("\n");
    */

    // Letra B)
    /*
    concatenaPilhasB(pilha1, pilha2);
    printf("Pilha Concatenada: ");
    imprimirPilha(pilha1);
    printf("\n");
    */

    // Letra C)
    /*
    concatenaPilhasC(pilha1, pilha2);
    printf("Pilha Concatenada: ");
    imprimirPilha(pilha1);
    printf("\n");
    */
}