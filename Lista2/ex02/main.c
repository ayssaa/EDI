// Funções recursivas

void imprimirRecursivo(NoLista **p) {
    if (*p == NULL) {
        return;
    }
    else {
        printf("%d ", (*p)->info);
        imprimirRecursivo(&((*p)->prox));
    }
}

void imprimirRecursivoReverso(NoLista **p) {
    if (*p == NULL) {
        return;
    }
    else {
        imprimirRecursivoReverso(&((*p)->prox));
        printf("%d ", (*p)->info);
    }
}

void liberarRecursivo(NoLista **p) {
    if (*p == NULL) {
        return;
    }
    else {
        liberarRecursivo(&((*p)->prox));
        free(*p);
        *p = NULL;
    }
}

NoLista* buscaRecursiva(NoLista **p, int valor) {
    if (*p == NULL) {
        return;
    }
    if ((*p)->info == valor) {
        return *p;
    }
    buscaRecursiva(((*p)->prox), valor);
}

void removerRecursivo(NoLista **p, int valor){
    if(*p == NULL) {
        return;
    }
    if((*p)->info == valor) {
        NoLista *temp = *p;
        *p = (*p) -> prox;
        free(temp);
        return;
    }
    removerRecursivo(&((*p)->prox), valor);
}