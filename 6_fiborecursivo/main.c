# include <stdio.h>

int Fibo(int a) {
    int fib;
    if (a == 0) {
        fib = 0;
    }
    else if (a == 1) {
        fib = 1;
    }
    else {
        fib = Fibo(a-1) + Fibo(a-2);
    }
    return fib;
}

void main() {
    int num;

    printf("Digite um valor: ");
    scanf("%d", &num);

    printf("O valor %d na sequência de Fibonacci é: %d", num, Fibo(num));
}