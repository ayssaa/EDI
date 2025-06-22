# include <stdlib.h>
# include <stdio.h>
# define MAX 3

// Lista com Estrutura Estática usando alocação Sequencial ou Conjutiva

typedef struct lista {
    int itens[MAX];
    int n; // número de elementos (também indica o índice que estamos)
} Lista;

Lista* CriarLista() {
    Lista *p = (Lista*)malloc(sizeof(Lista));

    // Verificar se o Malloc funcionou
    if(p != NULL) {
        p->n = 0; // Lista Vazia
        return p;
    }
    else {
        printf("\nNão foi possível alocar espaço!\n");
    }
}

int EstaVazia(Lista *p) {
    return (p->n == 0);
}

int EstaCheia(Lista *p) {
    return (p->n == MAX);
}

void InserirFim(Lista *p) {
    int valor;

    if (EstaCheia(p) == 1){
        printf("\nNão é possível armazenar mais elementos, a lista está cheia!\n");
    }

    else {
        printf("\nQual valor você gostaria de armazenar? ");
        scanf("%d", &valor);

        p->itens[p->n] = valor;
        p->n += 1;

        printf("\nValor %d armazenado com sucesso!\n", valor);
    }
}

void RemoverElemento(Lista *p) {
    int indice;
    if (EstaVazia(p) == 1){
        printf("\nNão é possível remover nenhum elemento, lista vazia!\n");
    }

    else {
        // Verificando o índice
        printf("\nQual o índice do valor que você deseja remover? ");
        scanf("%d", &indice);
        if (indice >= 1 && indice <= p->n) {
            for (int i = indice; i < p->n; i++) {
                p->itens[i-1] = p->itens[i];             
            }
            p->n -= 1;
            printf("\nElemento removido com sucesso!\n");
        }
        else {
            printf("\nÍndice Inválido!\n");
        }
    }
}

void LiberarLista(Lista *p) {
    free(p);
    printf("\nLista Liberada!\n");
}

void ImprimirLista(Lista *p) {
    if (EstaVazia(p) == 1) {
        printf("\nA lista está vazia!\n");
    }

    else {
        printf("\nLista: ");
        for(int i=0; i < p->n; i++) {
            printf("%d ", p->itens[i]);
        }
        printf("\n");
    }
}

void main() {
    int opcao;
    Lista *lista = NULL;
    do {
        // Menu
        printf("\n---Bem vindo ao Criador de Lista----\n");
        printf("1- Criar Lista\n");
        printf("2- Inserir no Final da Lista\n");
        printf("3- Ver Lista\n");
        printf("4- Remover Elemento\n");
        printf("5- Liberar Lista\n");
        printf("0- Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Ações para cada opção
        switch (opcao) {
            case 1:
                lista = CriarLista();
                printf("\nLista criada com Sucesso!\n");
                break;
            case 2:
                if(lista == NULL) {
                    printf("\nCrie a lista primeiro!\n");
                }
                else{
                    InserirFim(lista);
                }
                break;
            case 3:
                if(lista == NULL) {
                    printf("\nCrie a lista primeiro!\n");
                }
                else{
                    ImprimirLista(lista);
                }
                break;
            case 4:
                RemoverElemento(lista);
                break;
            case 5:
                LiberarLista(lista);
                break;
        }

    } while (opcao != 0);

}