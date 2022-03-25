/******************************************************************************

Q02 - Crie um programa que tenha uma função subtrai e a função main. 
A função main deve ler três valores, enviar para a função subtrai. 
A função subtrai deve realizar a subtração dos três valores (primeiro menos o 
segundo menos o terceiro) e retornar o valor. A Função main deve imprimir o
resultado da subtração.

*******************************************************************************/
#include <stdio.h>

int num1=0, num2=0, num3=0, total=0;

int subtrai(int num1, int num2, int num3){
    total = num1 - num2 - num3;
    return total;
    
}


int main()
{
    
    printf("Informe o primeiro elemento para a subtrair:\n>>> ");
    scanf("%d", &num1);
    printf("\nInforme o segundo elemento para a subtrair:\n>>> ");
    scanf("%d", &num2);
    printf("\nInforme o terceito elemento para a subtrair:\n>>> ");
    scanf("%d", &num3);
    subtrai(num1, num2, num3);

    printf("\nO resultado da subtração de %d, %d e %d é %d", num1, num2, num3, total);

}
