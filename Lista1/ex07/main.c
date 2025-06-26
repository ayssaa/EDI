# include <stdlib.h>
# include <stdio.h>
# include <string.h>

char* shift_string(char *str) {
    char *nova = malloc(strlen(str) + 1);  // +1 pro '\0'
    strcpy(nova, str);  // copia a string original

    for(int i=0; nova[i] != '\0'; i++) {
        char c = nova[i];

        if(c >= 'a' && c <= 'z') {
            if (c == 'z') {
                nova[i] = 'a';
            }
            else {
                nova[i] = c + 1;
            }
        }

        if(c >= 'A' && c <= 'Z') {
            if (c == 'Z') {
                nova[i] = 'A';
            }
            else {
                nova[i] = c + 1;
            }
        }
    }
    return nova;
}

void main() {
    char palavra[20] = "casa";

    char *nova = shift_string(palavra);

    printf("Original: %s\n", palavra);
    printf("Modificada: %s\n", nova);

    free(nova);
}