#include <stdio.h>
#include <stdlib.h>
#include <string.h> // elimina o '/n' durante o gets() por conta do espaço entre os inputs do usuário
#include <ctype.h>

#include "cadastroPessoasV0.h"
#include "opcoesMenuV0.h"





int mi = 0, ver1 = 1;

int main()
{
  while (ver1 == 1){
    printf("Menu inicial\n");
    printf("\n\n Digite a opção desejada.\n\n");
    printf("1 - Cadastro.\n");
    printf("2 - Relatórios.\n");
    scanf("%d", &mi);
    if (mi == 1){
      //chamar função de cadastro
    }
    if (mi == 2){
      //chamar a função de relatorios
    }
    else{
      printf("\nOpção inválida, tente novamente.\n");
      ver1 = 1;
    }       
  }
  return 0;
}
