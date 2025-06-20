# include <stdlib.h>
# include <stdio.h>

void Troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main() {
    int n1, n2;

    printf("Digite dois valores:\n");
    scanf("%d %d", &n1, &n2);

    printf("Valores antes da troca:\n");
    printf("Valor 1: %d\nValor 2: %d", n1, n2);

    Troca(&n1, &n2);

    printf("\nValores depois da troca:\n");
    printf("Valor 1: %d\nValor 2: %d", n1, n2);
}