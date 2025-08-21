// Implementando uma fila Dinamica e todas suas funções
# include <stdlib.h>
# include <stdio.h>

// Segue o TAD padrão
typedef struct noLista {
    int info;
    struct noLista *prox;
} NoLista;

typedef struct fila {
    NoLista *ini;
    NoLista *fim;
} Fila;

Fila* criarFila() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if(f == NULL) {
        printf("Erro ao alocar!");
        return NULL;
    }
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

int estaVazia(Fila* f) {
    return (f->ini == NULL);
}

// A inserção na fila é sempre no Final
void inserirFila(Fila* f, int v) {
    NoLista *novono = (NoLista*) malloc(sizeof(NoLista));
    if(novono == NULL) {
        printf("Erro ao alocar!");
    }
    else {
        novono->info = v;
        novono->prox = NULL;
        if(estaVazia(f) == 1) { // Caso 1: Novono é o primeiro elemento
            f->ini = novono;
        }
        else { // Caso 2: Novono é o último elemento
            f->fim->prox = novono;
        }
        f->fim = novono;
    }
}

void imprimirFila(Fila* f) {
    if(estaVazia(f) == 1) {
        printf("A fila está Vazia!");
    }
    else {
        for(NoLista *no = f->ini; no != NULL; no = no->prox) {
            printf("%d ", no->info);
        }
    }
}

// A remoção é sempre feita no Início
int removerFila(Fila* f) {
    if(estaVazia(f) == 1) {
        printf("A fila está Vazia!");
    }
    else {
        NoLista *cmc = f->ini;
        int v = cmc->info;
        f->ini = cmc->prox;
        if(f->ini == NULL) { // A fila ficou vazia devido a remoção
            f->fim = NULL;
        }
        free(cmc);
        return v;
    }
}

void liberarFila(Fila* f) {
    NoLista *temp, *no;
    for(no = f->ini; no != NULL; no = temp) {
        temp = no->prox;
        free(no);
    }
    free(f);
}

// Funções que a professora cobrou
int primeiroFila(Fila* f) {
    if(estaVazia(f) == 1) {
        return -1;
    }
    return f->ini->info;
}

int qntElementos(Fila* f) {
    int qnt = 0;
    for(NoLista *no = f->ini; no != NULL; no = no->prox) {
        qnt += 1;
    }
    return qnt;
}

int compararFilas(Fila* f1, Fila* f2) {
    NoLista *no1, *no2;
    for(no1 = f1->ini, no2 = f2->ini; no1 != NULL && no2 != NULL; no1=no1->prox, no2=no2->prox) {
        if(no1->info != no2->info) {
            return 0;
        }
    }
    if(no1 == NULL && no2 == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int maxElemento(Fila* f) {
    int maior = f->ini->info;
    for(NoLista *no = f->ini; no != NULL; no = no->prox) {
        if(no->info > maior) {
            maior = no->info;
        }
    }
    return maior;
}

// Funções mais complexas
// Combina duas filas: usando TAD
void combinaFilas(Fila* fres, Fila* f1, Fila* f2){
    while(estaVazia(f1) != 1 || estaVazia(f2) != 1) {
        if(estaVazia(f1) != 1) {
            inserirFila(fres, removerFila(f1));
        }
        if(estaVazia(f2) != 1) {
            inserirFila(fres, removerFila(f2));
        }
    }
}

// Combina duas filas: usando recursivade + TAD
void combinaFilasRecursivo(Fila* fres, Fila* f1, Fila* f2) {
    if(estaVazia(f1) && estaVazia(f2)) {
        return;
    }
    else {
        if(estaVazia(f1) != 1) {
            inserirFila(fres, removerFila(f1));   
        }
        if(estaVazia(f2) != 1) {
            inserirFila(fres, removerFila(f2));   
        }
        combinaFilasRecursivo(fres, f1, f2);
    }
}

// Fura fila: fere o TAD
void furaFila(Fila* f, int v) {
    NoLista *no; 
    NoLista *anterior = NULL;
    for(no = f->ini; no != NULL && no->info != v; no = no->prox) {
        anterior = no;
    }
    if(no == NULL) {
        printf("Valor não encontrado!");
    }
    else {
        if(anterior == NULL) { // já é o primeiro da fila!
            return;
        }
        else { // está no meio (ou fim) da fila
            anterior->prox = no->prox;
            no->prox = f->ini;
            f->ini = no;
            if(anterior->prox == NULL) {
                f->fim = anterior;
            }
        }
    }
}

// Fura fila: não fere o TAD
void furaFilaBem(Fila* f, int n) {
    Fila *aux = criarFila();
    
    while(estaVazia(f) != 1) {
        int nAtual = removerFila(f);
        if(nAtual != n) {
            inserirFila(aux, nAtual);
        }
        else if(nAtual == n) {
            inserirFila(f, nAtual);
            break;
        }
    }
    
    while(estaVazia(aux) != 1) {
        inserirFila(f, removerFila(aux));
    }
}


void divideFilas(Fila* f, Fila* f1, Fila* f2, int n) {
    while(estaVazia(f) != 1) {
        int nAtual = removerFila(f);
        if(nAtual == n) {
            inserirFila(f1, nAtual);
            break;
        }
        inserirFila(f1, nAtual);
    }
    while(estaVazia(f) != 1) {
        inserirFila(f2, removerFila(f));
    }
    return;
}

void main() {
    // Criando uma fila A
    Fila *filaA;
    filaA = criarFila();
    
    // Inserindo valores na fila A
    inserirFila(filaA, 1);
    inserirFila(filaA, 3);
    inserirFila(filaA, 5);
    
    // Vendo a fila A
    imprimirFila(filaA);
    
    // Criando uma fila B
    Fila *filaB;
    filaB = criarFila();
    
    // Inserindo valores na fila B
    inserirFila(filaB, 2);
    inserirFila(filaB, 4);
    
    // Vendo a fila B
    printf("\n");
    imprimirFila(filaB);
    
    // A lista A e B são iguais?
    printf("\nComparação: %d", compararFilas(filaA, filaB));
    
    // Quantos elementos tem cada lista?
    printf("\nA Fila A tem %d elementos, a Fila B tem %d elementos", qntElementos(filaA), qntElementos(filaB));
    
    // Maior elementos
    printf("\nO maior elemento na fila A é %d\n", maxElemento(filaA));
    
    // Combinando A e B
    Fila *filaAB = criarFila();
    combinaFilasRecursivo(filaAB, filaA, filaB);
    imprimirFila(filaAB);
    
    // Fura a fila AB pra 5
    printf("\n---------Testando a FuraFila----------\n");
    furaFilaBem(filaAB, 5);
    imprimirFila(filaAB);
    
    // Vendo se a divideFilas funciona
    printf("\n---------Testando a DivideFilas----------\n");
    Fila *fila = criarFila();
    Fila *metade1 = criarFila();
    Fila *metade2 = criarFila();
    inserirFila(fila, 1);
    inserirFila(fila, 2);
    inserirFila(fila, 3);
    inserirFila(fila, 4);
    inserirFila(fila, 5);
    printf("Fila: ");
    imprimirFila(fila);
    divideFilas(fila, metade1, metade2, 6);
    printf("\nMetade 1: ");
    imprimirFila(metade1);
    printf("\nMetade 2: ");
    imprimirFila(metade2);
}