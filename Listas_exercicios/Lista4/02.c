// Implementando uma árvore binária para responder a 2)
# include <stdio.h>
# include <stdlib.h>

typedef struct arvore {
    char info;
    struct arvore *esq;
    struct arvore *dir; 
} Arvore;

Arvore* criarArvoreVazia() {
    return NULL;
}

int estaVazia(Arvore *arv) {
    return (arv == NULL);
}

Arvore* criarArvore(char c, Arvore *sae, Arvore *sad) {
    Arvore *arv = (Arvore*) malloc(sizeof(Arvore));
    if(arv == NULL) {
        printf("Erro ao alocar!");
    }
    else {
        arv->info = c;
        arv->esq = sae;
        arv->dir = sad;
    }
    return arv;
}

int pertenceArvore(Arvore *arv, char c) {
    if(estaVazia(arv) != 1) {
        if(arv->info == c) {
            return 1;
        }
        return (pertenceArvore(arv->esq, c) || pertenceArvore(arv->dir, c));
    }
    else {
        return 0;
    }
}

void imprimeArvore(Arvore *arv) {
    printf("<");
    if(estaVazia(arv) != 1) {
        printf("%c ", arv->info);
        imprimeArvore(arv->esq);
        imprimeArvore(arv->dir);
    }
    printf(">");
}

Arvore* liberarArvore(Arvore *arv) {
    if(estaVazia(arv) != 1) {
        liberarArvore(arv->esq);
        liberarArvore(arv->dir);
        free(arv);
    }
    return NULL;
}

int qntNo(Arvore *arv) {
    if(estaVazia(arv) != 1) {
        return 1 + qntNo(arv->esq) + qntNo(arv->dir);
    }
    else {
        return 0;
    }
}

// 2) a) quantidade de folhas
int qtdeFolhas(Arvore *a) {
    if(estaVazia(a) != 1) {
        if(a->esq == NULL && a->dir == NULL) {
            return 1;
        }
        return qtdeFolhas(a->esq) + qtdeFolhas(a->dir);
    }
    else {
        return 0;
    }
}

// 2) b) quantidade de char repetido
int qtdeChar(Arvore *a, char c) {
    if(estaVazia(a) != 1) {
        if(a->info == c) {
            return 1 + qtdeChar(a->esq, c) + qtdeChar(a->dir, c);
        }
        return qtdeChar(a->esq, c) + qtdeChar(a->dir, c);
    }
    else {
        return 0;
    }
}

// 2) c) comparando
int iguais(Arvore *a, Arvore *b) {
    if(estaVazia(a) != 1 && estaVazia(b) != 1) { // ambas tem algo, temos que comparar os nós
        if(a->info == b->info){
            return ((iguais(a->esq, b->esq)) && (iguais(a->dir, b->dir)));
        }
        return 0;
    }
    else if(a == NULL && b == NULL){ // ambas vazias, logo iguais
        return 1;
    }
    else { // uma vazia e outra não, logo diferentes
        return 0;
    }
}

// 2) d) Copia
Arvore* copia(Arvore *a){
    Arvore *copia = criarArvoreVazia();
}

// 2) e) Maior valor (considerando int's)
int maiorValor(Arvore *a) {
    if (estaVazia(a) == 1) {
        return -1;
    }
    else {
        int maior = a->info;
        int maiorEsq = maiorValor(a->esq);
        int maiorDir = maiorValor(a->dir);
        if (maiorEsq > maior) {
            maior = maiorEsq;
        }
        if (maiorDir > maior) {
            maior = maiorDir;
        }
        return maior;
    }
}

void main() {
    // Criando a árvore <a<b<><c<><>>><d<e<><>><f<><g<><>>>>>
    Arvore *g = criarArvore('g', criarArvoreVazia(), criarArvoreVazia());
    Arvore *c = criarArvore('c', criarArvoreVazia(), criarArvoreVazia());
    Arvore *e = criarArvore('e', criarArvoreVazia(), criarArvoreVazia());

    Arvore *f = criarArvore('f', criarArvoreVazia(), g);
    Arvore *d = criarArvore('d', e, f);
    Arvore *b = criarArvore('b', criarArvoreVazia(), c);
    Arvore *a = criarArvore('a', b, d);

    // 2) a) 
    printf("\nA árvore tem %d folhas", qtdeFolhas(a));

    // 2) b)
    printf("\n A letra 'a' aparece %d vezes", qtdeChar(a, 'a'));

    //2

}