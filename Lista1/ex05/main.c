# include <stdio.h>
# include <stdlib.h>

void inverte(int n, int *v) {
    /* Pensando ...*/
}

void main() {
    int elementos;

    printf("\nQuantos elementos você deseja armazenar? ");
    scanf("%d", &elementos);

    int *vetor = malloc(elementos * sizeof(int));
    
    for (int i = 0; i < elementos; i++) {
        printf("\nDigite o valor do elemento de índice %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    printf("\nAqui está o seu vetor: ");
    for(int i=0; i < elementos; i++) {
        printf("%d ", vetor[i]);
    }

    inverte(elementos, vetor);

    printf("\nAqui está o seu vetor invertido: ");
    for(int i=0; i < elementos; i++) {
        printf("%d ", vetor[i]);
    }
}