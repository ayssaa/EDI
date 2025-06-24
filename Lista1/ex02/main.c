# include <stdio.h>
# include <stdlib.h>

int soma_impares(int n) {
    int soma = 0;
    int qnt = 0;

    for (int i=0; qnt != n; i++) {
        if (i % 2 != 0) {
            soma += i;
            qnt += 1;
        }
    }
    return soma;
}

void main() {
    int valor;

    printf("\n---Soma Ímpares---\n");
    printf("Digite um valor: ");
    scanf("%d", &valor);

    printf("A soma dos primeiros %d números ímpares é: %d", valor, soma_impares(valor));
}