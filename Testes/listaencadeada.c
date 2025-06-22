# include <stdio.h>
# include <stdlib.h>

typedef struct noLista {
    int info;
    struct noLista *prox;
} NoLista;

void CriarLista(NoLista **p) {
    *p = NULL;
}

int EstaVazia(NoLista **p) {
    return (*p == NULL);
}

void InserirInicio(NoLista **p) {
    NoLista *newp = (NoLista *) malloc(sizeof(NoLista));
    int valor;
    if(newp==NULL) {
        printf("Não foi possível alocar espaço");
    }
    else {
        printf("Qual valor você deseja adicionar?");
        scanf("%d", &valor);
        newp->info = valor;
        newp->prox = *p;
        *p = newp;
    }
}

void BuscarElemento() { 

}

void RemoverElemento() {

}

void LiberarLista() {

}

void QuantidadeElemento() {

}

void ImprimirLista() {

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
                InserirInicio();
                break;
            case 3:
                RemoverElemento();
                break;
            case 4:
                ImprimirLista();
                break;
            case 5:
                QuantidadeElemento();
                break;
            case 6:
                BuscarElemento();
                break;
            case 7:
                LiberarLista();
                break;
        }

    } while (opcao !=0);
}
