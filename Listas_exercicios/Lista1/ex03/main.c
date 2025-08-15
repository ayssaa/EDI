# include <stdlib.h>
# include <stdio.h>
# include <math.h>

double pi(int x){
    double valor = 0.0;
    for (int i = 0; i < x; i++) {
        valor += ((pow(-1, i)) / (2 * i + 1));
    }

    return 4 * valor;
}

void main() {
    int n;

    printf("-----Pi-----\n");
    printf("Digite um valor para avaliar o valor de pi: ");
    scanf("%d", &n);

    printf("Resultado: %lf", pi(n));
}