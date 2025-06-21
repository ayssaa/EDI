# include <stdio.h>
# include <stdlib.h>

void transposta(int **x, int linha, int coluna) {
    // Criando a transposta
    int **transposta = malloc(coluna * sizeof(int*));

    for (int i=0; i<coluna; i++) {
        transposta[i] = malloc(linha * sizeof(int));
    }

    // Preencher a transposta
    for (int i=0; i<coluna; i++) {
        for(int j=0; j<linha; j++) {
            transposta[i][j] = x[j][i];
        }
    }

    // Mostrar a transposta
    for(int i=0; i<coluna; i++) {
        for (int j=0; j<linha; j++) {
            printf("[%d]", transposta[i][j]);
        }
        printf("\n");
    }

    // Liberando transposta
    for (int i=0; i<coluna; i++) {
        free(transposta[i]);
    }
    free(transposta);
}

void main() {
    int linhas, colunas;

    // Usuário escolhe paramêtros da matriz
    printf("----Boas Vindas ao Criador de Matriz Dinâmico----\n");
    printf("Digite quantas linhas e colunas sua matriz terá: ");
    scanf("%d %d", &linhas, &colunas);

    // Criando uma matriz dinamicamente
    int **matriz = malloc(linhas * sizeof(int *));

    for (int i=0; i<linhas; i++) {
        matriz[i] = malloc(colunas * sizeof(int));
    }

    // Preenchendo a matriz dinâmica
    printf("\nPreencha sua matriz:\n");
    for(int i=0; i<linhas; i++) {
        for (int j=0; j<colunas; j++) {
            printf("Posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Visualizando matriz dinâmica
    printf("\nSua matriz digitada foi:\n");
    for(int i=0; i<linhas; i++) {
        for (int j=0; j<colunas; j++) {
            printf("[%d]", matriz[i][j]);
        }
        printf("\n");
    }

    // Visualizando matriz Transposta dinâmica
    printf("\nA matriz transposta da sua:\n");
    transposta(matriz, linhas, colunas);

    // Liberando matriz
    printf("\nLiberando matriz...");
    for (int i=0; i<linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    printf("\nMatriz Liberada!\n");
}