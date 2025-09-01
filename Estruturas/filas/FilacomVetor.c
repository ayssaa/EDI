// Implementando uma Fila usando Vetores!
# include <stdlib.h>
# include <stdio.h>
# define MAX 10

typedef struct fila {
	float info[MAX];
	int ini; // posicao inicio
	int n; // nC:mero de elementos na lista
} Fila;

Fila* criarFila() {
	Fila *f = (Fila*) malloc(sizeof(Fila));
	f->n = 0;
	f->ini = 0;
	return f;
}

int estaVazia(Fila *f) {
	return(f->n == 0);
}

int estaCheia(Fila *f) {
	return(f->n == MAX);
}

void inserir(Fila *f, float v) {
	// Sempre inserimos no fim, mas quem C) a posiC'C#o fim?
	// A posiC'C#o fim C) "ini+n"
	if(estaCheia(f) == 1) {
		printf("A Fila esta Cheia!");
	}
	else {
		// Calculando o fim, e a parte de "%" C) para incremento circular
		int fim = ((f->ini) + (f->n)) % MAX;

		f->info[fim] = v;

		f->n += 1;
	}
}

void imprime(Fila *f) {
	if(estaVazia(f) == 1) {
		printf("A Fila estC! Vazia!");
	}
	else {
		for(int i = 0; i < f->n; i++) {
			int indice = (f->ini + i) % MAX;
			printf("%.2f ", f->info[indice]);
		}
	}
}

float remover(Fila *f) {
	if(estaVazia(f) == 1) {
	    printf("A Fila está Vazia!");
	}
	else {
	    float v = f->info[f->ini];
	    f->ini = (f->ini + 1) % MAX;
	    f->n -= 1;
	    return v;
	}
}

void liberar(Fila *f) {
	free(f);
}

void main() {
	// Criando uma Fila
	Fila *fila;
	fila = criarFila();

	// Inserindo valores na Fila
	inserir(fila, 1);
	inserir(fila, 2);
	inserir(fila, 3);

	// Mostrando a Fila
	imprime(fila);

	// Removendo um valor da Pilha
	remover(fila);

	// Mostrando a fila
	printf("\n");
	imprime(fila);

}
