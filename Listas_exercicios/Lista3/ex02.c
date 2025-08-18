# include <stdio.h>
# include <stdlib.h>

typedef struct noLista {
    float info;
    struct noLista *prox;
} NoLista;

typedef struct fila {
    NoLista *ini;
    NoLista *fim;
} Fila;

Fila* criarFila() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

int estaVazia(Fila *f) {
    return (f->ini == NULL);
}

void inserir(Fila *f, float v) {
    NoLista *novono = (NoLista*) malloc(sizeof(NoLista));
    
    if(novono == NULL) {
        printf("Erro ao armazenar!");
    }
    else {
        novono->info = v;
        novono->prox = NULL;
        if(estaVazia(f) == 1) {
            f->ini = novono;
        }
        else {
            f->fim->prox = novono;
        }
        f->fim = novono;
    }
}

void imprimir(Fila *f) {
    if(estaVazia(f) == 1) {
        printf("A fila está Vazia!");
    }
    else {
        for(NoLista *no = f->ini; no != NULL; no = no->prox) {
            printf("%.2f ", no->info);
        }
    }
}

float remover(Fila *f) {
    if(estaVazia(f) == 1) {
        printf("A fila está Vazia!");
    }
    else {
        NoLista *cmc = f->ini;
        float v = cmc->info;
        f->ini = cmc->prox;
        if(f->ini == NULL) {
            f->fim = NULL;
        }
        free(cmc);
        return v;
    }
}

float maiorValor(Fila *f) {
    if(estaVazia(f) == 1) {
        printf("A fila está Vazia!");
    }
    else {
        float maior = f->ini->info;
        for(NoLista *no = f->ini; no != NULL; no = no->prox) {
            if(no->info > maior) {
                maior = no->info;
            }
        }
        return maior;
    }
}

void main() {
    Fila *fila;
    
    fila = criarFila();
    
    inserir(fila, 1);
    inserir(fila, 2);
    inserir(fila, 3);
    
    imprimir(fila);
    
    printf("\nO maior elemento da Fila é: %.2f", maiorValor(fila));
}
