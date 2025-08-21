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

// Letra A)
// Usando TAD fila
void combinaFilas(Fila* fres, Fila* f1, Fila* f2) {
    while (estaVazia(f1) != 1 || estaVazia(f2) != 1) {
        if(estaVazia(f1) != 1) {
            inserir(fres, remover(f1));
        }
        if(estaVazia(f2) != 1) {
            inserir(fres, remover(f2));
        }
    }
}

// Letra B)
// Recursivo
void combinaFilas(Fila* fres, Fila* f1, Fila* f2) {
    if (estaVazia(f1) != 1 || estaVazia(f2) != 1) {
        if(estaVazia(f1) != 1) {
            inserir(fres, remover(f1));
        }
        if(estaVazia(f2) != 1) {
            inserir(fres, remover(f2));
        }
        combinaFilas(fres, f1, f2);
    }
}
void main() {
    // Criando Fila
    Fila *fila1, *fila2, *fila3;
    fila1 = criarFila();
    fila2 = criarFila();
    fila3 = criarFila();
    
    // Inserindo na Fila1
    inserir(fila1, 1);
    inserir(fila1, 2);
    inserir(fila1, 3);
    
    // Inserindo na Fila2
    inserir(fila2, 4);
    inserir(fila2, 5);
    inserir(fila2, 6);
    
    // Vendo a Fila 1
    imprimir(fila1);
    
    // Vendo a Fila 2
    printf("\n");
    imprimir(fila2);
    
    // Letra A)
    /*
    printf("\nFilas Juntas: ");
    combinaFilasA(fila3, fila1, fila2);
    imprimir(fila3);
    */
    
    // Letra B)
    printf("\nFilas Juntas: ");
    combinaFilasB(fila3, fila1, fila2);
    imprimir(fila3);
}
