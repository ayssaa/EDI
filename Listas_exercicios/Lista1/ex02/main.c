# include <stdio.h>
# include <stdlib.h>

int soma_impares(int n) {
    int soma = 0;
    int qnt = 0;
    for(int i = 1; qnt < n; i++) {
        if(i % 2 != 0) {
            soma += i;
            qnt += 1;
        }
    }
    return soma;
}

void main() {
    int valor = 3, retorno;

    printf("%d", soma_impares(valor));
}

























