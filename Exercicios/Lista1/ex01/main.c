# include <stdio.h>
# include <stdlib.h>

int primo(int n) {
    if (n <= 1) {
        return 0;
    }
    else {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                return 0;
            }
        }
        return 1;
    }
}

void main() {
    int valor = 9, retorno;

    retorno = primo(valor);

    if (retorno == 1) {
        printf("É primo");
    }
    else {
        printf("Não é primo");
    }
}