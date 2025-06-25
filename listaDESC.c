// Implementando uma lista com Descritor
# include <stdio.h>
# include <stdlib.h>

typedef struct noLista {
    int info;
    struct noLista *prox;
} NoLista;

typedef struct descritor {
    NoLista *prim;
    NoLista *ult;
    int n;
} Descritor;

void CriarLista(Descritor *p) {
    p->prim = NULL;
    p->ult = NULL;
    p->n = 0;
}

int EstaVazia(Descritor *p) {
    return (p->n == 0);
}

void InserirInicio(Descritor *p, int valor) {
    NoLista *novono = (NoLista *) malloc(sizeof(int));
    
    if(novono == NULL) {
        printf("Não foi possível alocar espaço.");
    }
    else {
        novono->info = valor;
        novono->prox = p->prim;
        p->prim = novono;
        
        if(EstaVazia(p) == 1) {
            p->ult = novono;
        }
        
        p->n += 1;
    }
}

void InserirNoFim(Descritor *p, int valor) {
    NoLista *novono = (NoLista *) malloc(sizeof(NoLista));
    
    if (novono == NULL) {
        printf("Não foi possível alocar espaço");
    }
    else {
        novono->info = valor;
        novono->prox = NULL;
        if(EstaVazia(p) == 1){
            p->prim = novono;
        }
        else {
            p->ult->prox = novono;
        }
        p->ult = novono;
        p->n += 1;
    }
}

void RemoverElemento(Descritor *p, int valor) {
    NoLista *anterior = NULL;
    NoLista *no;
    
    for(no = p->prim; no != NULL && no->info != valor; no = no->prox) {
        anterior = no;
    }
    
    if (no == NULL) { // Caso 1: elemento não está na lista
        printf("\nElemento não está na lista\n");
    }
    else {
        // Caso 2: elemento está na lista e: é o primeiro elemento
        if (anterior == NULL) {
            p->prim = no->prox;
            
            if(p->prim == NULL) { // Se p->prim ficou nulo, significa que além do elemento ser o primeiro, ele era o único
                p->ult = NULL;
            }
        }
        else { // Caso 3: elemento está na lista e: está no meio
            anterior->prox = no ->prox;
            
            if (anterior->prox == NULL) { // Se anterior->prox ficou nulo, significa que esse elemento era o último
                p->ult = anterior;
            }
            
        }
        free(no);
        p->n -= 1;
    }
}

void Imprimir(Descritor *p) {
    if (EstaVazia(p) == 1) {
        printf("\nA lista está vazia!\n");
    }
    else {
        for(NoLista *no = p->prim; no != NULL; no = no->prox) {
            printf("%d ", no->info);
        }   
    }
}

void Liberar(Descritor *p) {
    NoLista *no;
    NoLista *temporario;
    
    for(no = p->prim; no !=NULL; no = temporario) {
        temporario = no->prox;
        free(no);
    }
    
    p->prim = NULL;
    p->ult = NULL;
    p->n = 0;
    
}

NoLista* Busca(Descritor *p, int valor) {
    for (NoLista* no = p->prim; no != NULL; no = no->prox) {
        if(no->info == valor) {
            return no;
        }
    }
    return NULL;
}

NoLista* ultimo(Descritor *p) {
    return p->ult;
}

int quantidade(Descritor *p) {
    return p->n;
}

int maiores(Descritor *p, int valor) {
    int contador = 0;
    for(NoLista *no = p->prim; no != NULL; no = no->prox) {
        if(no->info > valor) {
            contador += 1;
        }
    }
    return contador;
}

void concatena(Descritor *p, Descritor *p2) {
    if (p->prim == NULL) {
        p->prim = p2->prim;
        p->ult = p2->ult;
        p->n = p2->n;
    }
    else if (p2->prim == NULL) {
        return;
    }
    else {
        p->ult->prox = p2->prim;
        p->ult=p2->ult;
        p->n += p2->n;
    }
}

Descritor separa(Descritor *p, int valor) {
    Descritor listanova;
    CriarLista(&listanova);
    NoLista *no;

    for (no = p->prim; no != NULL && no->info != valor; no = no->prox);

    if (no == NULL || no->prox == NULL) {
        // valor não encontrado ou não tem nada depois dele
        return listanova; // lista nova vazia
    }

    listanova.prim = no->prox;
    listanova.ult = p->ult;

    no->prox = NULL;
    p->ult = no;

    return listanova;
}

/*
1- Busca (ok)
2- Quantidade de elementos (ok)
3- Achar ultimo elemento (ok)
4- maiores que int n (ok)
5- concatenar (ok)
6- Inserir ordenado
7- separar
8- comparar
*/


void main() {
    Descritor lista;
    Descritor lista2;
    
    // Criando Lista
    CriarLista(&lista);
    CriarLista(&lista2);
    
    // Preenchendo Lista
    InserirInicio(&lista, 1);
    InserirInicio(&lista, 2);
    InserirInicio(&lista, 3);
    InserirInicio(&lista, 4);
    
    // Removendo 4 da lista
    RemoverElemento(&lista, 4);
    
    // Mostrando a lista
    Imprimir(&lista);

    // Buscando um elemento na lista
    NoLista *auxiliar = Busca(&lista, 1);
    printf("\nEndereço procurado (1): %p\n", auxiliar);
    
    // Mostrando o ultim elemento da lista
    auxiliar = ultimo(&lista);
    printf("\nUltimo da lista (1): %p\n", auxiliar);
    
    // Mostrando quantos elementos tem na lista
    printf("\nExiste %d elementos na lista\n", quantidade(&lista));
    
    // Mostrando quantos elementos são maiores que 2
    printf("\nExiste %d elementos maiores que 2 na lista\n", maiores(&lista, 2));
    
    // Concatenando duas listas
    InserirInicio(&lista2, 4);
    InserirInicio(&lista2, 5);
    
    printf("\nLista 1:\n");
    Imprimir(&lista);
    
    printf("\nLista 2:\n");
    Imprimir(&lista2);
    
    printf("\nLista 1 e Lista 2 concatenadas:\n");
    concatena(&lista, &lista2);
    Imprimir(&lista);
    
}