# include <stdio.h>

int Fibo(int a) {
    if (a == 0) {
        return 0;
    }
    if (a == 1) {
        return 1;
    }

    int penul = 0, antepenul, atual = 1;
    for (int i = 2; i <= a; i++) {
        antepenul = penul;
        penul = atual;
        atual = penul + antepenul;
    }
    return atual;
}

void main() {
    int num;

    printf("Digite um valor: ");
    scanf("%d", &num);

    printf("O valor %d na sequência de Fibonacci é: %d", num, Fibo(num));
}