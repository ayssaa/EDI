# include <stdio.h>
# include <stdlib.h>

int primo(int x){
    if (x <= 1) {
        return 0;
    }
    for (int i = 2; i < x; i++){
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

void main() {
    int n;
    
    printf("Digite um valor:");
    scanf("%d", &n);

    if (primo(n) == 1) {
        printf("O número %d é primo.\n", n);
    }
    else {
        printf("O número %d não é primo.\n", n);
    }
}