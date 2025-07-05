// Implementando funções para uma lista simplesmente encadeada
// a) Uma função que retorna um ponteiro para o último elemento da lista
NoLista* ultimo(NoLista **p) {
    if (EstaVazia(p) == 1){
        printf("A lista está vazia!");
        return NULL;
    }
    else {
        for (NoLista *no = *p; no != NULL; no = no->prox) {
            if (no->prox == NULL) {
                return no;
            }
        }      
    }
}

// b) Uma função que retorna o número de nós da lista que possuem o campo info com valores maiores que n
int maiores(NoLista **p, int n) {
    int contador = 0;
    for (NoLista *no = *p; no != NULL; no = no->prox) {
        if (no->info > n) {
            contador += 1;
        }
    }

    return contador;
}

// c) Função que concatena duas listas l1 e l2. 
NoLista * concatena(NoLista **p1, NoLista **p2) {
    NoLista *ultimop1;

    for (NoLista *no = *p1; no != NULL; no = no->prox) {
        if (no->prox == NULL) {
            ultimop1 = no;
        }
    }

    if (*p1 == NULL) {
        return *p2;
    }
    else {
        ultimop1->prox = *p2;
        return *p1;
    }
}

// d) Função que recebe uma lista encadeada e um valor n. Divida a lista em duas, de modo que a segunda inicie logo
// após a primeira ocorrência de n na lista original. A função retorna um ponteiro para a segunda, e a primeira é 
// atualizada para estar pela metade.
NoLista* separa(NoLista **p, int n) {
    NoLista *quebra = NULL;
    NoLista *lista2 = NULL;

    for (NoLista *no = *p; no != NULL; no = no->prox) {
        if(no->info == n) {
            quebra = no;
        }
    } 

    // Quebrando em duas listas
    lista2 = quebra->prox;
    quebra->prox = NULL;

    return lista2;
}