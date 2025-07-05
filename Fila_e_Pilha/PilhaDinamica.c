// Pilhas com lista simplesmente encadeada

# include <stdio.h>
# include <stdlib.h>

typedef struct noLista {
	float info;
	struct noLista *prox;
} NoLista;

typedef struct pilha {
	NoLista *prim; // ponterio para o primeiro elemento da lista (topo)
} Pilha;

Pilha* criarPilha() {
	Pilha *p = (Pilha *) malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

int estaVazia(Pilha *p) {
	return (p->prim == NULL);
}

void push(Pilha *p, float v) {
	NoLista *novono = (NoLista *) malloc(sizeof(NoLista));

	if (novono == NULL) {
		printf("Não foi possível alocar espaço");
	}

	else {
		novono->info = v;
		novono->prox = p->prim;
		p->prim = novono;
	}
}

void imprimirPilha(Pilha *p) {
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

void liberarPilha(Pilha *p) {
    NoLista *temporario;
    for(NoLista *no = p->prim; no != NULL; no = temporario) {
        temporario = no->prox;
        free(no);
    }
    free(p);
}

void main() {
    // Criando Pilha
    Pilha *pilha;
    pilha = criarPilha();
    
    // Inserindo elementos na Pilha
    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 3);
    
    // Imprimindo Pilha
    imprimirPilha(pilha);
    
    // pop
    printf("\npop: %.2f", pop(pilha));
    
    // Liberar pilha
    liberarPilha(pilha);
}