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

float primeiroFila(Fila *f) {
	if(estaVazia(f) == 1) {
		printf("A lista está Vazia!");
	}
	else {
		float v = f->ini->info;
		return v;
	}
}

void furaFila(Fila *f, float v) {
	NoLista *no, *anterior = NULL;
	for(no = f->ini; no != NULL && no->info != v; no = no->prox) {
		anterior = no;
	}

	if(no == NULL) { // não achou o valor na fila
		printf("Valor não encontrado!");
	}
	else { // achou o valor na fila
		if(anterior == NULL) { // já é o primeiro da fila
			return;
		}
		else { // está no meio ou no fim da fila!
			anterior->prox = no->prox;
			no->prox = f->ini;
			f->ini = no;
			if(f->fim == no) { // se for o último da fila, então o f->fim tem que atualizar
				f->fim = anterior;
			}
		}
	}
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
    // remover(fila);
    
    // Vendo Fila
    printf("\n");
    imprimeFila(fila);

	// Fura Fila
	furaFila(fila, 2);

	// Vendo Fila
    printf("\n");
    imprimeFila(fila);
}
