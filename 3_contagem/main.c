# include <stdio.h>

void main() {
    int valor, i;
    do {
        printf("Digite um valor para a contagem: ");
        scanf("%d", &valor);

        for(i=valor; i>=0;i--){
            printf("%d...\n", i);
        }
    } while (valor != -1);
        
}