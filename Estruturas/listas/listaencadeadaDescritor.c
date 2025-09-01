# include <stdlib.h>
# include <stdio.h>

// lista com Descritor

typedef struct noLista {
    int info;
    struct noLista *prox;
} NoLista;

typedef struct descritor {
    NoLista *prim;
    NoLista *ult;
    int n;
} Descritor;

void CriarLista(Descritor *p) { // p <=> lista
    p->prim = NULL;
    p->ult = NULL;
    p->n = 0;
}

int EstaVazia(Descritor *p) {
    return (p->n==0);
}

void InserirInicio(Descritor *p) {
    NoLista *novono = (NoLista *) malloc(sizeof(NoLista));
    int valor;

    if (novono == NULL) {
        printf("\nNão foi possível alocar espaço.\n");
    }
    else {
        printf("\nQual valor você gostaria de armazenar no início? ");
        scanf("%d", &valor);

        // Armazenando valor
        novono->info = valor;
        novono->prox = p->prim;
        p->prim = novono;
        if (p->n==0) {
            p->ult = novono;
        }
        p->n += 1;
        printf("\nO valor %d foi armazenado com Sucesso!\n", valor);
    }
}

void ImprimirLista(Descritor *p) {
    if (EstaVazia(p) == 0) {
        printf("\nLista: ");
        for (NoLista *no = p->prim; no != NULL; no = no->prox) {
            printf("%d ", no->info);
        }
        printf("\n");
    }
    else {
        printf("\nA lista está Vazia!\n");
    }
}

void InserirFim(Descritor *p) {
    NoLista *novono = (NoLista *) malloc(sizeof(NoLista));
    int valor;

    if (novono == NULL) {
        printf("\nNão foi possível alocar espaço!\n");
    }
    else {
        printf("\nQual valor você gostaria de armazenar no final? ");
        scanf("%d", &valor);

        // Armazenando o valor
        novono->info = valor;
        novono->prox = NULL;      
        if (EstaVazia(p) == 0) {
            p->prim = novono;
        }
        else {
            p->ult->prox = novono;
        }
        p->ult = novono;
        p->n += 1;
        printf("\nO valor %d foi armazenado com Sucesso!\n", valor);
    }
}

void RemoverElemento(Descritor *p) {
    NoLista *anterior = NULL;
    NoLista *no = p->prim;
    int valor;

    printf("\nQual valor você deseja remover? ");
    scanf("%d", &valor);
    
    for(no = p->prim; no!=NULL && no->info != valor; no = no->prox) {
        anterior = no;
    }

    if(no == NULL) {
        printf("\nElemento não encontrado.\n");
        return;
    }
    else {
        if (anterior == NULL) { // Caso removamos o primeiro elemento, precisamos atualizar o prim
            p->prim = no->prox;
            
            if(p->prim == NULL){ // Caso tenha 1 elemento na lista e removamos o único, precisamos atualizar prim e ult
                p->ult = NULL;
            }
        }
        else {
            anterior->prox = no->prox;
            if(anterior->prox == NULL) { // Caso removamos o último elemento, também precisamos apontar o ult para o novo ultimo
                p->ult=anterior;
            }
        }
        free(no);
        p->n -= 1;
    }
}

void LiberarLista(Descritor *p) {
    NoLista *no;
    NoLista *temp;

    for(no=p->prim; no!=NULL; no = temp) {
        temp = no->prox;
        free(no);
    }
    
    p->prim = NULL;
    p->ult = NULL;
    p->n = 0;

    printf("\nLista Liberada com Sucesso.\n");
}

NoLista* BuscarElemento(Descritor* p) {
    int infoprocurado;

    printf("\nQual valor você quer buscar? ");
    scanf("%d", &infoprocurado);

    for(NoLista *no = p->prim; no != NULL;  no= no->prox) {
        if(no->info == infoprocurado){
            return no;
        }
    }
    return NULL;
}


void main() {
    int opcao;
    Descritor lista;

    do {
        printf("\n---Bem vindo ao criador de Lista Com Descritor---\n");
        printf("1- Criar Lista\n");
        printf("2- Inserir no ínicio\n");
        printf("3- Inserir no fim\n");
        printf("4- Ver Lista\n");
        printf("5- Remover Elemento\n");
        printf("6- Liberar Lista\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                CriarLista(&lista);
                break;
            case 2:
                InserirInicio(&lista);
                break;
            case 3:
                InserirFim(&lista);
                break;
            case 4:
                ImprimirLista(&lista);
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