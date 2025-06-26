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

void InserirNoInicio(Descritor *p, int valor) {
    NoLista *novono = (NoLista *) malloc(sizeof(NoLista));
    
    if (novono == NULL) {
        printf("Não foi possível alocar espaço");
    }
    else {
        if(EstaVazia(p) == 1) {
            p->ult=novono;
        }
        novono->info = valor;
        novono->prox = p->prim;
        p->prim = novono;
        p->n += 1;
    }
}

void InserirOrdenadoCrescente(Descritor *p, int valor) {
    NoLista *novono = (NoLista *) malloc(sizeof(NoLista));
    NoLista *anterior = NULL;
    NoLista *no;
    
    if (novono == NULL) {
        printf("Não foi possível alocar espaço");
    }
    else {
        for(no = p->prim; no != NULL && no->info < valor; no = no->prox) {
            anterior = no;
        }
        
        novono->info = valor;
        novono->prox = NULL;
        
        if (no == NULL) {
            p->ult = novono;
            if (anterior == NULL) { // A lista está vazia
                p->prim = novono;
            }
            else { // Último a ser inserido numa lista não vazia
                anterior->prox = novono;
            }
        }
        else { 
            if (anterior == NULL) { // Ele vira o primeiro elemento
                novono->prox = p->prim;
                p->prim = novono;
            }
            else {
                anterior->prox = novono;
                novono->prox = no;
            }
        }
        p->n += 1;
    }
}

void InserirOrdenadoDecrescente(Descritor *p, int valor) {
    NoLista *novono = (NoLista *) malloc(sizeof(NoLista));
    NoLista *anterior = NULL;
    NoLista *no;
    
    if (novono == NULL) {
        printf("Não foi possível alocar espaço");
    }
    else {
        for(no = p->prim; no != NULL && no->info > valor; no = no->prox) {
            anterior = no;
        }
        
        novono->info = valor;
        novono->prox = NULL;
        
        if (no == NULL) {
            p->ult = novono;
            if (anterior == NULL) { // A lista está vazia
                p->prim = novono;
            }
            else { // Último a ser inserido numa lista não vazia
                anterior->prox = novono;
            }
        }
        else { 
            if (anterior == NULL) { // Ele vira o primeiro elemento
                novono->prox = p->prim;
                p->prim = novono;
            }
            else {
                anterior->prox = novono;
                novono->prox = no;
            }
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

void ImprimirLista(Descritor *p) {
    if (EstaVazia(p) == 1) {
        printf("A lista esta vazia.");
    }
    else {
        for (NoLista *no = p->prim; no != NULL; no = no->prox) {
            printf("%d ", no->info);
        }    
    }
}

void RemoverElemento(Descritor *p, int valor) {
    NoLista *anterior = NULL;
    NoLista *no;
    
    for(no = p->prim; no != NULL && no->info != valor; no = no->prox) {
        anterior = no;
    }
    
    if (no == NULL) { // Caso 1: elemento não está na lista
        printf("Elemento não encontrado");
    }
    else {
        if(anterior == NULL) {  // Caso 2: elemento na lista, é o primeiro elemento
            p->prim = no->prox;
            
            if(p->prim == NULL) { // alem de ser o primeiro elemento, era o único
                p->ult = NULL;
            }
        }
        else { // caso 3: elemento no meio/fim da lista
            anterior->prox = no->prox;
            
            if(anterior->prox == NULL) { // era o último
                p->ult = anterior;
            }
        }
        free(no);
        p->n -=  1;
    }
}

void Liberar(Descritor *p) {
    NoLista *temporario;
    
    for(NoLista *no = p->prim; no != NULL; no = temporario) {
        temporario = no->prox;
        free(no);
    }
    
    // zerando lista de volta
    p->prim = NULL;
    p->ult = NULL;
    p->n = 0;
}

int quantidade(Descritor *p) {
    return p->n;
}

NoLista* ultimo(Descritor *p) {
    return p->ult;    
}

int ultimovalor(Descritor *p) {
    if (EstaVazia(p) == 1) {
        return -1;
    }
    else {
        return p->ult->info;  
    }
}

NoLista* buscar(Descritor *p, int valor) {
    for(NoLista *no = p->prim; no != NULL && no->info != valor; no = no->prox) {
        if(no->info == valor) {
            return no;
        }
    }
    return NULL;
}

int maiorElemento(Descritor *p) {
    int maior = p->prim->info;
    for(NoLista *no = p->prim; no != NULL; no = no->prox) {
        if (no->info > maior) {
            maior = no->info;
        }
    }
    return maior;
}

float mediaElemento(Descritor *p) {
    float media;
    int soma = 0; 
    int qnt = 0;
    
    for(NoLista *no = p->prim; no != NULL; no = no->prox) {
        soma += no->info;
        qnt += 1;
    }
    
    media = (float) soma / qnt;
    return media;
}

Descritor* concatenar(Descritor *p, Descritor *p2) {
    if (p2->n == 0) {
        return p;
    }
    else if (p->n == 0) {
        p->prim = p2->prim;
        p->ult = p2->ult;
        p->n = p2->n;
        return p;
    }
    else {
        p->ult->prox = p2->prim;
        p->ult = p2->ult;
        p->n += p2->n;
        return p;
    }
}

Descritor separa(Descritor *p, int valor) {
    NoLista *quebra = NULL;
    NoLista *no;
    NoLista *ultimono = NULL;
    Descritor listanova;

    for(no = p->prim; no!=NULL; no = no->prox) {
        if(no->info == valor) {
            quebra = no;
        }
    }
    
    if(quebra == NULL) {
        printf("Valor não encontrado");
        listanova.prim = NULL;
        listanova.ult = NULL;
        listanova.n = 0;
        return listanova;
    }
    else {
        // Atualizar a nova lista
        listanova.prim = quebra->prox;
        listanova.n = 0;
        
        for(no = listanova.prim; no != NULL; no = no->prox) {
            if(no->prox == NULL) {
                ultimono = no;
            }
            listanova.n += 1;
        }
        
        listanova.ult = ultimono;
        
        // Atualizar p
        p->ult = quebra;
        quebra->prox = NULL;
        p->n = 0;
        for(no = p->prim; no!=NULL; no =no->prox) {
            p->n += 1;
        }
        
        return listanova;
    }
}


/*

imprimeListaOrdemInversa() //vai imprimir do fim ao início

inverterLista() //inverter a ordem dos nós

retornarImpares() //vou percorrer uma lista e criar uma nova so com os elementos impares dela e retornar ela

copiarLista() //copio toda a lista

infoMaisFrequente() //mostra valor que mais apareceu

comparaLista() //diz se sao iguais


*/


void main() {
    Descritor lista;
    Descritor lista2;
    
    // Criando uma lista
    CriarLista(&lista);
    CriarLista(&lista2);
    
    // Inserindo Elementos na lista
    InserirOrdenadoDecrescente(&lista, 1);
    InserirOrdenadoDecrescente(&lista, 2);
    InserirOrdenadoDecrescente(&lista, 4);
    InserirOrdenadoDecrescente(&lista, 3);
    
    // Inserindo Elementos na lista 2 
    InserirOrdenadoDecrescente(&lista2, 5);
    InserirOrdenadoDecrescente(&lista2, 8);
    InserirOrdenadoDecrescente(&lista2, 6);
    InserirOrdenadoDecrescente(&lista2, 7);
    
    
    // Imprimindo lista
    ImprimirLista(&lista);
    
    // Achando o maior da lista
    printf("\nO maior elemento da lista é %d\n", maiorElemento(&lista));
    
    // concatenar
    printf("\nConcatenada:\n");
    ImprimirLista(concatenar(&lista, &lista2));
    
    
}