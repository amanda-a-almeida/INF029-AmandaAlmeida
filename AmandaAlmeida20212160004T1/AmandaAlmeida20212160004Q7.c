// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Amanda Araújo Almeida
//  email: amanda.mecatronica@gmail.com
//  Matrícula: 20212160004
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021

// #################################################

// Questão 07

#include <stdio.h>
#include <ctype.h>
char pos[3][3], coluna;
int linha, i, j, jogador = 1, resultado = 1;


int print()
{
    printf(" %c  | %c  | %c \n----+----+----\n %c  | %c  | %c  \n----+----+----\n %c  | %c  | %c  \n", pos[0][0], pos[0][1], pos[0][2], pos[1][0], pos[1][1], pos[1][2], pos[2][0], pos[2][1], pos[2][2]);

    return 0;
}
int jogada(){
  do{
      printf("\nDigite a posição que deseja jogar:\n");
      scanf("%c%d",&coluna, &linha);
      getchar();
      if(linha > 3){
          printf("Casa Invalida!");
      }
  }while(linha > 3);
  coluna = tolower(coluna);
  j = linha -1;
  switch (coluna){
    case 'a':
      i = 0;
      break;
    case 'b':
      i = 1;
      break;
    case 'c':
      i = 2;
      break;
    default:
      print("Casa invalida!\n");
      jogada();
      break;
  }
  if(pos[i][j]==' '){
    if((jogador % 2) == 0){
      pos[i][j] = 'O';
    }else{
      pos[i][j] = 'X';
    }
  }
  else if(pos[i][j] == 'X' || pos[i][j] == 'O'){
    printf("Casa já ocupada!\n");
    jogada();
  }
}
int verificar(){
  if(pos[0][0]==pos[0][1]&&pos[0][2]==pos[0][1]&&pos[0][0]!=' '){//linha a
    return 0;
  }else if(pos[0][0]==pos[1][0]&&pos[2][0]==pos[1][0]&&pos[0][0]!=' '){//coluna 0
    return 0;
  }else if(pos[1][0]==pos[1][1]&&pos[1][2]==pos[1][1]&&pos[1][0]!=' '){//linha b
    return 0;
  }else if(pos[0][1]==pos[1][1]&&pos[2][1]==pos[1][1]&&pos[0][1]!=' '){// coluna 1
    return 0;
  }else if(pos[2][0]==pos[2][1]&&pos[2][2]==pos[2][1]&&pos[2][0]!=' '){//linha c
    return 0;
  }else if(pos[0][2]==pos[1][2]&&pos[2][2]==pos[1][2]&&pos[0][2]!=' '){//coluna 2
    return 0;
  }else if(pos[0][0]==pos[1][1]&&pos[2][2]==pos[1][1]&&pos[0][0]!=' '){//diagonal 1
    return 0;
  }else if(pos[0][2]==pos[1][1]&&pos[2][0]==pos[1][1]&&pos[0][2]!=' '){//diagonal 2
    return 0;
  }else{
    return 1;
  }
}

int main(){
  for(i = 0; i < 3; i++){
    for (j = 0; j < 3; j++){
      pos[i][j] = ' ';
    }
  }
  print();
  printf("\nJogador 1\n");
  do{
    jogada();
    resultado = verificar();
    if(resultado == 0){
      if(jogador % 2 == 0){
        print();
        printf("\nO jogador 2 Venceu!\n");
      }else{
        print();
        printf("\nO Jogador 1 venceu!\n");
      }
    }else{
      jogador ++;
      if(jogador > 9){
        printf("\nEmpate!\n");
        resultado = 0;
      }
      print();
      if(resultado!=0){
        if(jogador %2 != 0){
          printf("\nJogador 1\n");
        }else{
          printf("\nJogador 2\n");
        }
      }
    }
  }while(resultado != 0);
}
