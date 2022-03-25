/******************************************************************************

Q01 - Crie um programa que tenha uma função soma e a função main. A função main 
deve ler dois valores, enviar para a função soma. A função soma deve realizar a 
soma e retornar o valor. A Função main deve imprimir o resultado da soma.

*******************************************************************************/
#include <stdio.h>

int num1=0, num2=0, total=0;

int soma(int num1, int num2){
    total = num1 + num2;
    return total;
    
}


int main()
{
    
    printf("Informe o primeiro elemento para a soma:\n>>> ");
    scanf("%d", &num1);
    printf("\nInforme o segundo elemento para a soma:\n>>> ");
    scanf("%d", &num2);
    soma(num1, num2);

    printf("\nO resultado da soma de %d com %d é %d", num1, num2, total);

}
