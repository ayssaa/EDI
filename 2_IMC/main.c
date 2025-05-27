# include <stdio.h>

void main() {
    float altura, peso, imc;

    printf("Digite sua altura: ");
    scanf("%f", &altura);
    printf("\nDigite seu peso: ");
    scanf("%f", &peso);

    imc = peso / (altura * altura);

    printf("Sua altura e de %.2f metros\n", altura);
    printf("Seu peso e de %.2f quilos\n", peso);
    if (imc < 18.5) {
        printf("Voce esta abaixo do peso normal.\n");
    }
    else if (imc >= 40) {
        printf("Voce esta com obesidade grau III.\n");
    }
    else if(imc >= 35 && imc < 40) {
        printf("Voce esta com obesidade grau II.\n");
    }
    else if(imc >= 30 && imc < 35) {
        printf("Voce esta com obesidade grau I.\n");
    }
    else if(imc >= 25 && imc < 30) {
        printf("Voce esta com sobrepeso.\n");
    }
    else if(imc >= 18.5 && imc < 25) {
        printf("Voce esta com o peso normal.\n");
    }
    printf("Seu IMC vale %.2f", imc);
}