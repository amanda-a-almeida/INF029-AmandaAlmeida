/******************************************************************************

Q03 - Faça um programa que tenha uma função que recebe um número inteiro e 
retorna o fatorial deste número. Esta função deve ainda verificar se é possível 
calcular o fatorial, se não for, ela deve de alguma forma retornar para a main 
que deu algum erro. A função main deve solicitar o valor do usuário e imprimir 
o fatorial dele, ou se não é possível calcular o fatorial.

*******************************************************************************/
#include <stdio.h>

int num, fat=1, resultado;

int fatorial(int num){
    if (num > 0){
        for (int i=num; i>0; i--){
        fat *= i;
        }
        return fat;
        
    } else if(num == 0){
        return 1;
        
    }
    else{
      return -1;
      
    }
}

int main()
{
    printf("Digite o número a ser fatorado:\n>>> ");
    scanf("%d", &num);
    resultado = fatorial(num);
    
    if (resultado > 0){
        printf("\n%d! = %d", num, fat);
        
    } else{
        printf("\nNão é possível calcular o fatorial de %d", num);
    }
}
