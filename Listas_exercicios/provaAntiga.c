// 1) 

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

// 2)
int diferentes(Pilha *p1, Pilha *p2) {
    while (estaVazia(p1) != 1 && estaVazia(p2) != 1) {
        float n1 = pop(p1);
        float n2 = pop(p2);
        if(n1 != n2) {
            return 1;
        }
    }
    if(estaVazia(p1) == 1 && estaVazia(p2) == 1) {
        return 0;
    }
    else {
        return 1;
    }
}

// 3) a)
int iguais(Arvore *a, Arvore *b) {
    if(a != NULL && b != NULL) {
        if(a->info == b->info) {
            return (iguais(a->esq, b->esq) && iguais(a->dir, b->dir));
        }
        else {
            return 0;
        }
    }
    
    if(a == NULL && b == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

// 3) b)
Arvore* maximo(Arvore* a) {
    if(estaVazia(a) != 1) {
        if(a->dir == NULL) {
            return a;
        }
        else {
            return maximo(a->dir);
        }
    }
    else {
        return NULL;
    }
}

// 3) a)
int iguais(Arvore *a, Arvore *b) {
    if(a != NULL && b != NULL) {
        if(a->info == b->info) {
            return (iguais(a->esq, b->esq) && iguais(a->dir, b->dir));
        }
        else {
            return 0;
        }
    }
    
    if(a == NULL && b == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

// 3) b)
Arvore* maximo(Arvore* a) {
    if(estaVazia(a) != 1) {
        if(a->dir == NULL) {
            return a;
        }
        else {
            return maximo(a->dir);
        }
    }
    else {
        return NULL;
    }
}

// 4) no caderno!

// 5)
Arvore* espelho(Arvore *a) {
    Arvore *t = NULL;
    if(a==NULL) {
        return NULL;
    }
    else {
        t = criarArvore(a->info, espelho(a->dir), espelho(a->esq));
        return t;
    }
}
