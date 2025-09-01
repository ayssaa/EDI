# include <stdio.h>
# include <stdlib.h>

// lista com cabeça e cauda

typedef struct noLista {
    int info;
    struct noLista *prox;
} NoLista;

typedef struct lista {
    NoLista *cab;
    NoLista *cau;
} Lista;

void CriarLista(Lista *p) {
    p->cab = (NoLista *) malloc(sizeof(NoLista));
    p->cau = (NoLista *) malloc(sizeof(NoLista));

    p->cab->prox = p->cau;
    p->cau->prox = NULL;

    printf("\nLista Criada com Sucesso!\n");
}

int EstaVazia(Lista *p) {
    return (p->cab->prox == p->cau);
}

void InserirElemento(Lista *p) {
    NoLista *novono = (NoLista*) malloc(sizeof(NoLista));
    int valor;

    if(novono == NULL) {
        printf("\nNão foi possível alocar espaço.\n");
    }
    else {
        printf("\nQual valor você gostaria de armazenar no início? ");
        scanf("%d", &valor);

        // Armazenando...
        novono->info = valor;
        novono->prox = p->cab->prox;
        p->cab->prox = novono;
        printf("\nO valor %d foi armazenado com Sucesso!\n", valor);
    }
}

void ImprimirLista(Lista *p) {
    if (EstaVazia(p) != 0) {
        printf("\nA lista está vazia!\n");
    }
    else {
        printf("\nLista: ");
        for(NoLista *no = p->cab->prox; no != p->cau; no = no->prox) {
            printf("%d ", no->info);
        }
        printf("\n");
    }
}

void InserirElementoFim(Lista *p) {
    NoLista *novono = (NoLista*) malloc(sizeof(NoLista));
    int valor;

    if(novono == NULL) {
        printf("\nNão foi possível alocar espaço.\n");
    }
    else {
        printf("\nQual valor você gostaria de armazenar no início? ");
        scanf("%d", &valor);

        // Armazenando...
        novono->prox = NULL;
        p->cau->info = valor;
        p->cau->prox = novono;
        p->cau= novono;
    }
}

void RemoverElemento(Lista *p) {
    NoLista *anterior = p->cab;
    NoLista *no;
    int valor;

    printf("\nQual valor você deseja remover? ");
    scanf("%d", &valor);

    for (no = p->cab->prox; no != p->cau && no->info != valor; no = no->prox) {
        anterior = no;
    }

    if(no == p->cau) { // Ou seja, chegamos no fim da lista e não achamos o valor para remover
        printf("\nElemento não encontrado.\n");
    }
    else { 
        anterior->prox = no->prox;
        free(no);
        printf("\nElemento Removido.\n");
    }
}

void LiberarLista(Lista *p) {
    NoLista *no;

    for(no = p->cab->prox; no != p->cau; no = p->cab->prox) {
        p->cab->prox = no->prox;
        free(no);
    }
    
    printf("\nLista Liberada com Sucesso.\n");
}

void main() {
    int opcao;
    Lista lista;

    do {
        printf("\n---Bem vindo a Lista com Cabeça e Cauda---\n");
        printf("1- Criar Lista\n");
        printf("2- Inserir Elemento\n");
        printf("3- Ver Lista\n");
        printf("4- Inserir no final da Lista\n");
        printf("5- Remover Elemento\n");
        printf("6- Liberar\n");
        printf("0- Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
                CriarLista(&lista);
                break;
            case 2: 
                InserirElemento(&lista);
                break;
            case 3: 
                ImprimirLista(&lista);
                break;
            case 4: 
                InserirElementoFim(&lista);
                break;
            case 5: 
                RemoverElemento(&lista);
                break;
            case 6: 
                LiberarLista(&lista);
                break;
        }

    } while (opcao != 0);
}