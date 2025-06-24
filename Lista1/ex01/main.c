# include <stdio.h>
# include <stdlib.h>

int primo(int n) {
    if (n <= 1) {
        return 0;
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
          return 0;
        }
    }
    return 1;
}

void main() {
    int valor;

    printf("\n---Testando se é Primo---\n");
    printf("Digite um valor: ");
    scanf("%d", &valor);

    if (primo(valor) == 0) {
        printf("\nO valor %d não é primo.\n", valor);
    }
    else {
        printf("\nO valor %d é primo.\n", valor);
    }
}