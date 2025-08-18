// Implementando Fila com Lista Simplesmente Encadeada!
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
	Fila *f= (Fila*) malloc(sizeof(Fila));
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
		printf("NC#o foi possC-vel alocar!");
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

void imprimeFila(Fila *f) {
	if(estaVazia(f) == 1) {
		printf("A fila esta Vazia!");
	}
	else {
		for(NoLista *no = f->ini; no != NULL; no = no->prox) {
			printf("%.2f ", no->info);
		}
	}
}

float remover(Fila *f) {
	if(estaVazia(f) == 1) {
		printf("A fila esta Vazia!");
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

void liberar(Fila *f) {
    NoLista *no, *temp;
    for(no = f->ini; no != NULL; no = temp) {
        temp = no->prox;
        free(no);
    }
    free(f);
}

void main() {
    // Criando uma Fila
    Fila *fila;
    fila = criarFila();

    // Inserindo na Fila
    inserir(fila, 1);
    inserir(fila, 2);
    inserir(fila, 3);
    
    // Vendo Fila
    imprimeFila(fila);
    
    // Removendo um elemento
    remover(fila);
    
    // Vendo Pilha
    printf("\n");
    imprimeFila(fila);
}
