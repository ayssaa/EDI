# include <stdio.h>
# include <stdlib.h>

void inverte(int n, int *v) {
    int i = 0;
    int j = n-1;
    while (i<j) {
        int temp =v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    }
}

void main() {
    int vetor[5] = {1,2,3,4,5};

    inverte(5, vetor);
}














