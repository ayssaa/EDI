# include <stdlib.h>
# include <stdio.h>

struct realtype {
    int left;
    int right;
};

typedef struct realtype Real;

void leReal(Real *p) {
    printf("Digite a parte inteira do número real: ");
    scanf("%d", &(p->left));

    printf("Digite a parte decimal do número real: ");
    scanf("%d", &(p->right));
}

void imprimeReal(Real *p) {
    printf("Número Real: %d.%d\n", p->left, p->right);
}

Real soma(Real *p1, Real *p2) {
    Real resultado;

    resultado.left = p1->left + p2->left;
    resultado.right = p1->right + p2->right;

    if (resultado.right >= 100) {
        resultado.left += 1;
        resultado.right -= 100;
    }

    return resultado;
}

void main() {
    Real n1, n2, resultado;
    int opcao;

    do {
        printf("------Boas Vindas ao Leitor de número Real-----\n");
        printf("1. Ler real 1\n");
        printf("2. Ler real 2\n");
        printf("3. Imprimir real\n");
        printf("4. Somar reais\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                leReal(&n1);
                break;
            case 2:
                leReal(&n2);
                break;
            case 3:
                imprimeReal(&n1);
                break;
            case 4:
                resultado = soma(&n1, &n2);
                printf("Resultado da soma: ");
                imprimeReal(&resultado);
                break;
        }

    } while (opcao != 0);
    
}
