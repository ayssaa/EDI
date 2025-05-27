#include <stdio.h>

void Troca(int *a, int *b) {
    int temp = *a;  // Guarda o valor apontado por 'a' em uma variável temporária
    *a = *b;        // Coloca o valor apontado por 'b' no endereço apontado por 'a'
    *b = temp;      // Coloca o valor temporário no endereço apontado por 'b'
}

void main() {
    int v1, v2;

    printf("Digite dois valores: ");
    scanf("%d %d", &v1, &v2);  // Lê os dois valores e armazena em v1 e v2

    printf("Antes da troca: valor 1 = %d, valor 2 = %d\n", v1, v2);

    // Declara dois ponteiros que apontam para v1 e v2
    int *p1 = &v1;
    int *p2 = &v2;

    Troca(p1, p2);

    printf("Depois da troca: valor 1 = %d, valor 2 = %d\n", v1, v2);
}
