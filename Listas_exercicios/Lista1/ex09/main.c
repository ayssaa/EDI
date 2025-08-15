# include <stdio.h>
# include <stdlib.h>

int potenciaRecursiva(int x, int y) {
    if (y == 0) {
        return 1;
    }
    else {
        return x * potenciaRecursiva(x, y-1);
    }
}

void main() {
    printf("%d", potenciaRecursiva(2,3));
}