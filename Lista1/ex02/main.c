# include <stdlib.h>
# include <stdio.h>

int soma_impares(int x) {
    int soma = 0, quantidade = 0;

    for (int i = 1; quantidade != x; i++) {
        if (i % 2 != 0) {
            quantidade += 1;
            soma += i;
        }
    }
    return soma;
}

void main() {
    int n;

    printf("Digite um valor: ");
    scanf("%d", &n);

    printf("A soma dos n primeiros números naturais ímpares é: %d", soma_impares(n));

}