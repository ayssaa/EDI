// # include <stdlib.h>
// # include <stdio.h>

// void shift_string (char *str) {
//     for (int i=0; str[i] != '\0'; i++) {
//         char c = str[i];

//         if (c >= 'a' && c <= 'z') {
//             if(c == 'z') {
//                 str[i] = 'a';
//             }
//             else {
//                 str[i] = c + 1;
//             }
//         }

//         if (c >= 'A' && c <= 'Z') {
//             if(c == 'Z') {
//                 str[i] = 'A';
//             }
//             else {
//                 str[i] = c + 1;
//             }
//         }

//     }
// }

// void main() {
//     char palavra[20];
//     printf("Digite uma palavra qualquer: ");
//     scanf("%s", palavra);

//     shift_string(palavra);

//     printf("A palavra trocada é: %s", palavra);
// }



# include <stdlib.h>
# include <stdio.h>

void shift_string(char *str) {
    for(int i=0; str[i] != '\0'; i++) {
        char c = str[i];

        if(c >= 'a' && c <= 'z') {
            if (c == 'z') {
                str[i] = 'a';
            }
            else {
                str[i] = c + 1;
            }
        }

        if(c >= 'A' && c <= 'Z') {
            if (c == 'Z') {
                str[i] = 'A';
            }
            else {
                str[i] = c + 1;
            }
        }
    }
}

void main() {
    char palavra[20] = "casa";

    shift_string(palavra);

    printf("%s", palavra);
}