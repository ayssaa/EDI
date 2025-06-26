# include <stdio.h>
# include <stdlib.h>

int somaSerieRecursivo(int i, int j, int k) {
    if (i>j) {
        return 0;
    }
    else {
        return i + somaSerieRecursivo(i+k, j, k);
    }
}

void main() {
    int v1 = 1, v2 = 10, v3 = 1;
    
    printf("Resultado: %d", somaSerieRecursivo(v1, v2, v3));
}