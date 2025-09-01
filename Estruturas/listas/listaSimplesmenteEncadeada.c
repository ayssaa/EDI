# include <stdio.h>
# include <stdlib.h>

// Lista Simplesmente Encadeada

typedef struct noLista {
    int info;
    struct noLista *prox;
} NoLista;

void CriarLista(NoLista **p) {
    *p = NULL; // <=> lista = NULL;
    printf("\nLista Criada com Sucesso.\n");
}

int EstaVazia(NoLista **p) {
    return (*p == NULL);
}

void InserirInicio(NoLista **p) {
    NoLista *novono = (NoLista *) malloc(sizeof(NoLista)); // Criando novo nó
    int valor;

    // Verificando malloc
    if (novono == NULL) {
        printf("\nNão foi possível alocar espaço.\n");
    }

    else {
        printf("Qual valor você gostaria de armazenar? ");
        scanf("%d", &valor);

        novono->info = valor; // Novo nó recebe valor em info
        novono->prox = *p; // Novo nó prox aponta para o primeiro nó (ou NULL) da lista
        *p = novono; // Novo nó passa a ser o primeiro nó da lista
        printf("\nValor %d armazenado com Sucesso.\n", valor);
    }
}

void ImprimirLista(NoLista **p) {
    if (EstaVazia(p) == 1) {
        printf("\nLista Vazia!\n");
    }
    else {
        printf("\nLista: ");
        for (NoLista *no = *p; no != NULL; no = no->prox) {
            printf("%d ", no->info);
        }
        printf("\n");
    }
}

int QuantidadeElemento(NoLista **p) {
    int qnt = 0;
    for (NoLista *no = *p; no != NULL; no = no->prox) {
        qnt += 1;
    }
    return qnt;
}

NoLista* BuscarElemento(NoLista **p) { // retorna o endereço do nó onde está o info procurado
    int infoprocurado;
    
    printf("\nQual valor você quer buscar? ");
    scanf("%d", &infoprocurado);
    
    for (NoLista *no = *p; no != NULL; no = no->prox) {
        if (no->info == infoprocurado) {
            return no;
        }
    }
    return NULL;
}

void RemoverElemento(NoLista **p) {
    NoLista *anterior = NULL;
    NoLista *no = *p;
    int valor;

    printf("\nQual valor você deseja remover? ");
    scanf("%d", &valor);
    
    // for que, encontra o nó anterior do que queremos remover, ou mantém o anterior como NULL
    for(no = *p; no != NULL && no->info != valor; no = no->prox) {
        anterior = no;
    }

    if (no == NULL) { // Elemento não encontrado
        printf("\nElemento não encontrado.\n");
        return;
    }

    else {
        if (anterior == NULL) { // Se o anterior é NULL, significa que o nó a ser removido é o primeiro, logo vamos atualizar *p para apontar para o
                                // 2° elemento, cujo endereço é no (primeiro elemento) -> prox <=> 2° elemento
            *p = no->prox;
            printf("\nO elemento %d foi removido com Sucesso.\n", valor);
        }
        else { // Nó removido está no meio da lista, nó anterior deve apontar para o prox do nó removido
            anterior -> prox = no -> prox;
            printf("\nO elemento %d foi removido com Sucesso.\n", valor);
        }
    }
    free(no);
}

void LiberarLista(NoLista **p) {
    NoLista *no;
    NoLista *temp;

    for (no = *p; no != NULL; no = temp) {
        temp = no->prox;
        free(no);
    }

    *p = NULL;
    printf("\nLista liberada com sucesso.\n");
}

void main() {
    int opcao;
    NoLista *lista;

    do {
        // Menu
        printf("\n-----Bem vindos ao criador de Lista Encadeada por Nós-----\n");
        printf("1- Criar Lista\n");
        printf("2- Inserir elemento no Início\n");
        printf("3- Remover elemento\n");
        printf("4- Ver Lista\n");
        printf("5- Quantidade de elementos na Lista\n");
        printf("6- Buscar na Lista\n");
        printf("7- Liberar Lista\n");
        printf("0- Sair\n");
        printf("Digite uma opção: ");
        scanf("%d", &opcao);

        // Ações
        switch (opcao) {
            case 1:
                CriarLista(&lista);
                break;
            case 2:
                InserirInicio(&lista);
                break;
            case 3:
                RemoverElemento(&lista);
                break;
            case 4:
                ImprimirLista(&lista);
                break;
            case 5:
                printf("\nA lista tem %d elementos.\n", QuantidadeElemento(&lista));
                break;
            case 6:
                NoLista *noprocurado = BuscarElemento(&lista);
                if (noprocurado == NULL){
                    printf("\nElemento não encontrado\n");
                }
                else {
                    printf("\nO seu elemento está no endereço %p\n", noprocurado);
                }
                break;
            case 7:
                LiberarLista(&lista);
                break;
        }

    } while (opcao !=0);
}
