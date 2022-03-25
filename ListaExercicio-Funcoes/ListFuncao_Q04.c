/******************************************************************************

Q04 - Crie um programa que tenha uma função ler3Numeros. Essa função deve ler 
três números do usuário e retornar os três números. A função main deve imprimir 
esses três números. Utilize vetor para fazer o retorno.

*******************************************************************************/
#include <stdio.h>

int vetor[3];

int ler3Numeros(){
    for (int i = 0; i < 3; i++){
        printf("\nInforme o %dº elemento:\n>>> ", (i + 1));
        scanf("%d", &vetor[i]);
    }
    return vetor[3];
}

int main()
{
    ler3Numeros();
    for (int i = 0; i < 3; i++){
        printf("\n%dº elemento informado: %d.\n", (i + 1), vetor[i]);

    }
    
}
