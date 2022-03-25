/******************************************************************************

Q07 - Crie um programa que tenha uma função ler3Palavras. Essa função deve ler 
três palavras do usuário e retornar as três palavras. A função main deve 
imprimir essas três palavras.

*******************************************************************************/
#include <stdio.h>

typedef struct {
    char palavra[50];
} palavras;

palavras vetor[3];

ler3Palavras(){
    for (int i = 0; i < 3; i++){
        printf("\nInforme a %dª palavra:\n>>> ", (i + 1));
        scanf("%s", &vetor[i]);
        getchar();
        
    }
    return vetor;
}

int main()
{
    ler3Palavras();
    for (int i = 0; i < 3; i++){
        printf("\n%dª palavra informada: %s.\n", (i + 1), vetor[i]);

    }
}
