// Implementando uma Fila usando Vetores!
# include <stdlib.h>
# include <stdio.h>
# define MAX 10

typedef struct fila {
    float info[MAX];
    int ini; // posicao inicio
    int n; // número de elementos na lista 
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
    // Sempre inserimos no fim, mas quem é a posição fim?
    // A posição fim é "ini+n"
    if(estaCheia(f) == 1) {
        printf("A Fila está Cheia!");
    }
    else {
        // Calculando o fim, e a parte de "%" é para incremento circular
        int fim = ((f->ini) + (f->n)) % MAX;
        
        f->info[fim] = v;
        
        f->n += 1;
    }
}

void imprimeFila(Fila *f) {
    if(estaVazia(f) == 1) {
        printf("A Fila está Vazia!");
    }
    else {
        for()
    }
}

void main() {
    
}

/*
Fila* criarFila( );		       	// Cria uma fila vazia
int estaVazia(Fila* f); 		// Verifica se a fila está vazia
int estaCheia(Fila* f); 		// Verifica se a fila está cheia
void inserir(Fila* f, float v); // Insere um elemento no fim
void imprimeFila(Fila* f); 	    // Imprime a fila
float remover(Fila* f);		    // Remove elemento do início
void liberarFila(Fila* f); 	    // Libera a fila
*/