// Implementando uma lista Simplesmente Encadeada
# include <stdlib.h>
# include <stdio.h>

typedef struct noLista {
    int info;
    struct noLista *prox;
} NoLista;

void CriarLista(NoLista **p) {
    *p = NULL; // Ou seja, lista = NULL;
}

int EstaVazia(NoLista **p) {
    return (*p == NULL);
}

void InserirInicio(NoLista **p, int valor) {
    NoLista *novono = (NoLista *) malloc(sizeof(int));
    
    if(novono==NULL) {
        printf("Não foi possível alocar espaço");
    }
    else {
        novono->info = valor;
        novono->prox = *p;
        *p = novono;
    }
}

void ImprimirLista(NoLista **p) {
    for (NoLista *no = *p; no != NULL; no = no->prox){
        printf("%d ", no->info);
    }
}

NoLista* Busca(NoLista **p, int valor) {
    for (NoLista *no = *p; no != NULL; no = no->prox) {
        if (no->info == valor) {
            return no;
        }
    }
    return NULL;
}

void RemoverElemento(NoLista **p, int valor) {
    NoLista *anterior = NULL;
    NoLista *no = *p;
    
    for(no = *p; no != NULL && no->info != valor; no = no->prox){
        anterior = no;
    }
    
    // Vamos tratar cada caso especial
    // Caso 1: O elemento não está na lista
    if (no == NULL) {
        printf("\nO elemento não está na lista.\n");
    }
    else {
        // Caso 2: O elemento está na lista e: é o único elemento ou é o primeiro elemento
        if(anterior == NULL) {
            *p = no->prox;
        }
        else {
            // Caso 3: O elemento está na lista e: está no meio da lista ou é o último elemento
            anterior->prox = no->prox;
        }
        free(no);
    }
}

int QuantidadeElemento (NoLista **p) {
    int qnt = 0;
    for (NoLista *no = *p; no != NULL; no = no->prox) {
        qnt += 1;
    }
    return qnt;
}

void Liberar(NoLista **p) {
    NoLista *temporario;
    for (NoLista *no = *p; no != NULL; no = temporario) {
        temporario = no->prox;
        free(no);
    }
    *p = NULL;
}

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

int maiores(NoLista **p, int n) {
    int contador = 0;
    for (NoLista *no = *p; no != NULL; no = no->prox) {
        if (no->info > n) {
            contador += 1;
        }
    }

    return contador;
}

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

void InsereOrdenado(NoLista **p, int valor) {
    NoLista *novono = (NoLista *) malloc(sizeof(NoLista));
    
    if(novono == NULL) {
        printf("Não foi possível alocar espaço.");
    }
    else {
        NoLista *anterior = NULL;
        NoLista *no;
        
        novono->info = valor;
        novono->prox = NULL;
        
        for (no = *p; no != NULL && no->info < novono->info; no = no->prox) {
               anterior = no;
        }
        
        novono->prox = no;
        if(anterior == NULL){
            *p = novono;
        }
        else {
            anterior->prox = novono;
        }
        
    }
}

NoLista* separa(NoLista **p, int n) {
    NoLista *quebra;
    NoLista *lista2;

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

int compara(NoLista **p1, NoLista **p2) {
    int diferente = 0;
    NoLista *no;
    NoLista *no2;

    for (no = *p1, no2 = *p2; no != NULL && no2 != NULL; no = no->prox, no2 = no2->prox) {
        if (no->info != no2->info) {
            diferente += 1;
        }
    }
    
    // Se uma lista tiver terminado e a outra não, são diferentes
    if (no == NULL && no2 == NULL) {
        return (diferente == 0);
    }
    else {
        return 1;
    }
}

void ImprimirRecursivo(NoLista **p) {
    if (*p == NULL) {
        return;
    }
    else {
        printf("%d ", (*p)->info);
        ImprimirRecursivo(&((*p)->prox));
    }
}

void ImprimirInversoRecursivo(NoLista **p) {
    if (*p == NULL) {
        return;
    }
    else {
        ImprimirInversoRecursivo(&((*p)->prox));
        printf("%d ", (*p)->info);
    }
}

void main() {
    // Aprendendo Recursividade
    NoLista *lista;
    CriarLista(&lista);
    InserirInicio(&lista, 1);
    InserirInicio(&lista, 2);
    InserirInicio(&lista, 3);
    ImprimirRecursivo(&lista);
    printf("\n");
    ImprimirInversoRecursivo(&lista);




    // NoLista *lista;
    // NoLista *lista2;
    
    // // Criando lista
    // CriarLista(&lista);
    // CriarLista(&lista2);
    
    // // Inserindo elementos na lista
    // InserirInicio(&lista, 1);
    // InserirInicio(&lista, 2);
    // InserirInicio(&lista, 3);
    
    // // Mostrando lista
    // ImprimirLista(&lista);
    
    // // Buscando um valor na lista
    // NoLista *auxiliar = Busca(&lista, 1);
    // printf("\nEndereço do nó procurado: %p", auxiliar);
    
    // // Removendo um elemento da lista
    //         // RemoverElemento(&lista, 2);
    //         // printf("\n");
    //         // ImprimirLista(&lista);
    
    // // Contando quantos elementos há na lista
    // printf("\nA lista possui %d elementos.", QuantidadeElemento(&lista));
    
    // // Endereço do último elementos
    // auxiliar = ultimo(&lista);
    // printf("\nEndereço do último nó: %p", auxiliar);
    
    // // Contando quantos valores são maiores que X
    // printf("\nExiste %d números maiores que 2 na lista.\n", maiores(&lista, 2));
    
    // // Concatenando lista e lista2
    // InserirInicio(&lista2, 4);
    // InserirInicio(&lista2, 5);
    // InserirInicio(&lista2, 6);
    // ImprimirLista(&lista2);
    // auxiliar = concatena(&lista, &lista2);
    // printf("\nLista concatenada: \n");
    // ImprimirLista(&auxiliar);
    
    
    // // Separando as listas de novo
    // printf("\nAntes de separar:\n");
    // ImprimirLista(&auxiliar);
    // printf("\nDepois de separar:\n");
    // NoLista *auxiliar2 = separa(&auxiliar, 6);
    // printf("\nLista parte 1:\n");
    // ImprimirLista(&auxiliar);
    // printf("\nLista parte 2:\n");
    // ImprimirLista(&auxiliar2);
    
    // // Criando uma Lista Ordenada
    // NoLista *ordenada;
    // CriarLista(&ordenada);
    // InsereOrdenado(&ordenada, 1);
    // InsereOrdenado(&ordenada, 6);
    // InsereOrdenado(&ordenada, 3);
    // InsereOrdenado(&ordenada, 2);
    // printf("\nSegue uma lista ordenada!\n");
    // ImprimirLista(&ordenada);
    

}
