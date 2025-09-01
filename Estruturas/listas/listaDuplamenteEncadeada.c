// Implementando uma lista Duplamente Encadeada
# include <stdio.h>
# include <stdlib.h>

typedef struct noLista {
    int info;
    struct noLista *ant;
    struct noLista *prox;
} NoLista;

void CriarLista(NoLista **p) {
    *p = NULL;
}

int EstaVazia(NoLista **p) {
    return (*p == NULL);
}

void InserirElemento(NoLista **p, int valor) {
    NoLista *novono = (NoLista *) malloc(sizeof(NoLista));
    
    if (novono == NULL) {
        printf("Não foi possível alocar espaço.");
    }
    else {
        novono->info = valor;
        novono->prox = *p;
        novono->ant = NULL;
        
        if(EstaVazia(p) != 1) {
            (*p)->ant = novono;
        }
        
        *p = novono;
    }
}

void ImprimirLista(NoLista **p) {
    for(NoLista *no = *p; no != NULL; no = no->prox) {
        printf("%d ", no->info);
    }
}

void ImprimirListaInversa(NoLista **p) {
    NoLista *ultimo = NULL;
    
    for(NoLista *no = *p; no != NULL; no = no->prox) {
        if(no->prox == NULL) {
            ultimo = no;
        }
    }
    
    for(NoLista *no = ultimo; no != NULL; no = no->ant) {
        printf("%d ", no->info);
    }
}

NoLista* ultimo(NoLista **p) {
    if (EstaVazia(p) == 1) {
        return NULL;
    }
    else {
        for(NoLista *no = *p; no != NULL; no = no->prox) {
            if (no->prox ==  NULL) {
                return no;
            }
        }   
    }
}

void RemoverElemento(NoLista **p, int valor){
    NoLista *no;
    
    for(no = *p; no != NULL && no->info != valor; no = no->prox);
    
    if (no != NULL) {
        if(*p == no) {
            (*p) = no->prox;
            if(*p != NULL) {
                (*p)->ant = NULL;
            }
        }
        
        else {
            no->ant->prox = no->prox;
            
            if(no->prox != NULL) {
                no->prox->ant = no->ant;
            }
        }
        free(no);
    }
}

// ✨ Lógica da função:
// Criar ponteiro NoLista* nova = NULL;

// Percorrer a lista *l

// Para cada nó ímpar:

// Criar um novo nó

// Inserir esse novo nó no final da nova lista (nova)

// Retornar o ponteiro nova

NoLista* novaI(NoLista **p) {
    NoLista *nova = NULL;
    NoLista *anterior = NULL;

    for(NoLista *no = *p; no != NULL; no = no->prox) {
        if (no->info % 2 != 0) {
            NoLista *noimpar = (NoLista *) malloc(sizeof(NoLista));
            // Inserindo no Final
            noimpar->info = no->info;
            noimpar->prox = NULL;
            noimpar->ant = anterior;

            // Se a lista estiver vazia
            if(nova == NULL) {
                nova = noimpar;
            }
            else {
                anterior->prox = noimpar;
            }
            anterior = noimpar;
        }
    }
    return nova;
}


void main() {
    NoLista *lista;
    
    CriarLista(&lista);
    
    InserirElemento(&lista, 1);
    InserirElemento(&lista, 2);
    InserirElemento(&lista, 3);
    
    ImprimirLista(&lista);
    printf("\n");
    ImprimirListaInversa(&lista);
    
    printf("\nEndereço do último elemento: %p\n", ultimo(&lista));
    
    NoLista *auxiliar = novaI(&lista);
    ImprimirLista(&auxiliar);
}