void imprimeFolhasDecrescente(Arv *a) {
    if (a == NULL) {
        return;
    }
    
    // Percorre a sub-árvore direita primeiro (maiores valores)
    imprimeFolhasDecrescente(a->dir);
    
    // Se for folha, imprime
    if (a->esq == NULL && a->dir == NULL) {
        printf("%d ", a->info);
    }
    
    // Percorre a sub-árvore esquerda (menores valores)
    imprimeFolhasDecrescente(a->esq);
}