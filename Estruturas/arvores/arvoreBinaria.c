// Implementando uma Arvore Binaria

# include <stdio.h>
# include <stdlib.h>

typedef struct arvore {
	char info;
	struct arvore *esq;
	struct arvore *dir;
} Arvore;

Arvore* criarArvoreVazia()  {
	return NULL;
}

Arvore* criarArvore(char c, Arvore *sae, Arvore *sad) {
	Arvore* arv = (Arvore*) malloc(sizeof(Arvore));
	if(arv == NULL) {
		printf("Erro na alocação de memória!");
	}
	else {
		arv->info = c;
		arv->esq = sae;
		arv->dir = sad;
	}
	return arv;
}

int estaVazia(Arvore *arv) {
	return(arv == NULL);
}

int pertenceArvore(Arvore* arv, char c) {
	if(estaVazia(arv) != 1) {
        if(arv->info == c) { // se está na raíz, retorna 1!
			return 1;
		}
		return (pertenceArvore(arv->esq, c) || pertenceArvore(arv->dir, c)); // basta estar em algum lado que retorna 1
    }
    else {
        return 0;
    }
}

/*
Obs.: A função Imprime pode ser:
. Pré-Ordem: nó, esquerda, direita
. Ordem Simétrica: esquerda, nó, direita
. Pós-Ordem: esquerda, direita, nó
E para alterar isso na função, basta trocar a ordem da 'recursividade' e 'print'!
*/
void imprimeArvore(Arvore *arv) {
    printf("<");
    if(estaVazia(arv) != 1) {
        printf("%c", arv->info);
        imprimeArvore(arv->esq);
        imprimeArvore(arv->dir);
    }
    printf(">");
}

Arvore* liberarArvore(Arvore *arv) {
    if(estaVazia(arv) != 1) {
        arv->esq = liberarArvore(arv->esq);
        arv->dir = liberarArvore(arv->dir);
        free(arv);
    }
    return NULL;
}

int qntNos(Arvore* arv) {
    if(estaVazia(arv) != 1) {
        return 1 + (qntNos(arv->esq) + qntNos(arv->dir));
    }
    else {
        return 0;
    }
}

void main() {
	// Criando a arvore <a<b<><d<><>>><c<e<><>><f<><>>>>
	Arvore *a, *b, *c, *d, *e, *f;
	f = criarArvore('f', criarArvoreVazia(), criarArvoreVazia());
	e = criarArvore('e', criarArvoreVazia(), criarArvoreVazia());
	d = criarArvore('d', criarArvoreVazia(), criarArvoreVazia());
	
	c = criarArvore('c', e, f);
	b = criarArvore('b', criarArvoreVazia(), d);
	
	a = criarArvore('a', b, c);
    
    // Imprimindo Arvore
    imprimeArvore(a);
    
	// Verificando se 'a' pertence a Arvore
	printf("\n%d", pertenceArvore(a, 'b'));
	
	// Quantidade de nós
	printf("\nA árvore tem %d nós", qntNos(a));
	
	// Liberando nós para termos uma árvore <a <b<><>> <c<><>>> (a b c)
	a->esq->dir = liberarArvore(d);
	a->dir->dir = liberarArvore(f);
	a->dir->esq = liberarArvore(e);
	
	// Criando um ramo (d e f)
	f = criarArvore('f', criarArvoreVazia(), criarArvoreVazia());
	e = criarArvore('e', criarArvoreVazia(), criarArvoreVazia());
	d = criarArvore('d', e, f);
	
	// Enxertando!
	a->esq->esq = d;
	
	// Imprimindo Arvore
	printf("\n");
    imprimeArvore(a);
}
