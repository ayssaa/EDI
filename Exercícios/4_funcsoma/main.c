# include <stdio.h>

int Soma(int a, int b) {
    return a+b;
}

void main() {
    int valor1, valor2;

    printf("Digite dois valores: ");
    scanf("%d %d", &valor1, &valor2);

    printf("%d + %d = %d", valor1, valor2, Soma(valor1, valor2));
}