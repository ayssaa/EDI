# include <stdio.h>
# include <stdlib.h>

typedef struct realtype {
    int left;
    int right;
} Real; // left.right

void leReal(Real *r) {
    printf("Digite a parte inteira: ");
    scanf("%d", &(r->left));

    printf("Digite a parte fracional: ");
    scanf("%d", &(r->right));
}

void imprimeReal(Real *r) {
    printf("%d.%02d", r->left, r->right);
}

Real soma(Real *r1, Real *r2) {
    Real result;
    result.left = r1->left + r2->left;
    result.right = r1->right + r2->right;
    if(result.right >= 100) {
        result.left += 1;
        result.right -= 100;
    }
    return result;
}

void main() {
    Real real, real2, resultado;
    
    leReal(&real);
    leReal(&real2);

    imprimeReal(&real);
    printf("\n");
    imprimeReal(&real2);
    printf("\n");
    resultado = soma(&real, &real2);
    imprimeReal(&resultado);
}

// c) Escreva uma função chamada soma que recebe duas estruturas Real como parâmetros e defina
// o valor de uma terceira estrutura para representar o número que seja a soma das duas estruturas
// de entrada. Seu protótipo é:

// Real soma(Real* r1, Real * r2);





















