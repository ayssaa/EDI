# include <stdio.h>
# include <stdlib.h>

typedef struct ponto {
    int x;
    int y;
} Ponto;

int dentro_ret(Ponto *ie, Ponto *sd, Ponto *p) {
    if (p->x >= ie->x &&  p->x <= sd->x) {
        if(p->y >= ie->y && p->y <= sd->y) {
            return 1;
        }
        else {
            return 0;
        }
    }
    return 0;
}

void main() {
    // Definindo Ponto Inferior Esquerdo
    Ponto ie;
    ie.x = 0;
    ie.y = 0;

    // Definindo Ponto Inferior Esquerdo
    Ponto sd;
    sd.x = 0;
    sd.y = 0;

    // Definindo Ponto Inferior Esquerdo
    Ponto p;
    p.x = 0;
    p.y = 0;

    // Chamada
    int resp = dentro_ret(&ie, &sd, &p);
    if (resp == 1) {
        printf("Está dentro!");
    }
    else {
        printf("Está fora!");
    }
}