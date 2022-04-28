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

#include <stdio.h>
#include "AmandaAlmeida20212160004T1.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Verificador data
int valida_data (int d,int m,int a){
    int mes_fev;
    // Verificar se é Ano Bisexto
    if( (a%4 == 0)||((a%100 == 0)&&(a%400 == 0)) ){
      mes_fev = 29;
    } else{
      mes_fev = 28;
    }

    // Definir valor máximo de dias pors meses
    if( ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12)) && (d <= 31) ){
      return 1;

    } else if( (m == 2) && (d <= mes_fev) ){
      return 1;

    } else if( ((m == 4) || (m == 6) || (m == 9) || (m == 11)) && (d <= 30) ){
      return 1;
    }
    else{
        return 0;
    } 
}

DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

  dd = dq.iDia;
  mm = dq.iMes;
  aa = dq.iAno;
  

  if (dq.iDia == 0 || dq.iMes == 0 || dq.iAno == 0){
    dq.valido = 0;
  }else{
    dq.valido = valida_data(dq.iDia, dq.iMes, dq.iAno);
  }  
  respQuebData = dq.valido;
}

// Questão 01
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */

int q1(char data[])
{
  quebraData(data);
  return respQuebData;
}

// Questão 02
/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */

int validadma(){
  int totali = diano * 365 + dimes * 30 + didia;
  int totalf = dfano * 365 + dfmes*30 + dfdia;
  if(totalf < totali){
    return 0;
  }else{
    return 1;
  }
}

int difdma(){
  DiasMesesAnos dma;
  if(didia <= dfdia){
    difdia = dfdia - didia;
  }else{
    difdia = 30 - (didia - dfdia);
    dfmes --;
  }
   if(dimes <= dfmes){
      difmes = dfmes - dimes;
  }else{
      difmes = 12 - (dimes - dfmes);
      dfano--;
  }
  difano = dfano - diano;
}

DiasMesesAnos q2(char datainicial[], char datafinal[])
{ 
  //calcule os dados e armazene nas três variáveis a seguir
  DiasMesesAnos dma;

  quebraData (datainicial);
  didia = dd; 
  dimes = mm;
  diano = aa;

  quebraData (datafinal);
  dfdia = dd; 
  dfmes = mm;
  dfano = aa;
  
  if (q1(datainicial) == 0){
    dma.retorno = 2;
    return dma;

  }else if (q1(datafinal) == 0){
    dma.retorno = 3;
    return dma;

  //verifique se a data final não é menor que a data inicial
  } else if (validadma() == 0){
    dma.retorno = 4;
    return dma;
    
  }else if (validadma() == 1){
    //calcule a distancia entre as datas
    difdma();
    dma.qtdDias = difdia;
    dma.qtdMeses = difmes;
    dma.qtdAnos = difano;
    dma.retorno = 1;  
    return dma;
  }  
}

// Questão 03
/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int varredura(char *texto, char c, int isCaseSensitive, int cont,  int tam){
  char verificador[250];

  for (int i = 0; i < tam; i++){    
    if (isCaseSensitive == 0){
      verificador[i] = tolower(texto[i]);
    }else if (isCaseSensitive == 1){
      verificador[i] = texto[i];
    }
    
    if (verificador[i] == ("a" || "á" || "â" || "ã" || "à")){
      verificador[i] = 'a';      
    }else if (verificador[i] == ("A" || "Á" || "Â" || "Ã" || "À")){
      verificador[i] = 'A';      
    }else if (verificador[i] == ("e" || "é" || "ê")){
      verificador[i] = 'e';      
    }else if (verificador[i] == ("E" || "É" || "Ê")){
      verificador[i] = 'E';      
    }else if (verificador[i] == ("i" || "í")){
      verificador[i] = 'i';      
    }else if (verificador[i] == ("I" || "Í")){
      verificador[i] = 'I';      
    }else if (verificador[i] == ("o" || "ó" || "õ")){
      verificador[i] = 'o';      
    }else if (verificador[i] == ("O" || "Ó" || "Õ")){
      verificador[i] = 'O';      
    }else if (verificador[i] == ("u" || "ú")){
      verificador[i] = 'u';      
    }else if (verificador[i] == ("U" || "Ú" )){
      verificador[i] = 'U';      
    }

    if (c == verificador[i]){
      cont++;
    }
  }
  return cont;
}

int ocorrencia(char *texto, char c, int isCaseSensitive){
  int tam;
  tam = strlen(texto);
  int cont = 0;
 
  if (isCaseSensitive == 1){
    cont = varredura(texto, c, isCaseSensitive, cont, tam);    
  }else if (isCaseSensitive == 0){
    c = tolower(c);
    cont = varredura(texto, c, isCaseSensitive, cont, tam);
  }
  return cont;
}

int q3(char *texto, char c, int isCaseSensitive){  
  int qtdOcorrencias;
  qtdOcorrencias = ocorrencia(texto, c, isCaseSensitive);
  return qtdOcorrencias;
}

// Questão 04
/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */

int buscarPalavra(char *strTexto, char *strBusca, int posicoes[30]){ 
  int tamTexto, tamBusca, contTexto = 0, p = 0, a = 0;
  tamTexto = strlen(strTexto);
  tamBusca = strlen(strBusca);
  for (int i = 0; i < tamTexto; i++){
    if (strTexto[i] == strBusca[0]){      
      for (a = 0; a < tamBusca; a++){
        if (strTexto[i+a] == strBusca[a]){
          contTexto++;
        }else{
          contTexto = 0;
          a = tamBusca;
        }        
      }
      if (contTexto == (tamBusca)){
        if (p == 0){
          posicoes[p] = (i + 1);
          p++;
          posicoes[p] = (i + a);
        }else if (p > 0){
          p++;
          posicoes[p] = (i + 1);
          p++;
          posicoes[p] = (i + a);
        }        
        contTexto = 0;
        i += (a - 1);
      }
    }
  }
  return p;
}

int printPosicoes(int posicoes[30], int qtdPosicoes){
  int u = 0;
  for (int i = 0; i < qtdPosicoes; i++){
    if (i % 2 == 0){
      printf("%dª posição inicial: %d", u, posicoes[i]);
    }else if (i % 2 != 0){
      printf("%dª posição final: %d", u, posicoes[i]);
      u++;
    }    
  }
}

int q4(char *strTexto, char *strBusca, int posicoes[30])
{
  int qtdPosicoes;
  qtdPosicoes = buscarPalavra(strTexto, strBusca, posicoes);
  return ((qtdPosicoes + 1)/2);
  if (qtdPosicoes > 0){
    printPosicoes(posicoes, qtdPosicoes);
  }  
}

// Questão 05
/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int converter(int num){
  int inverte = 0, temp, powint, powint2, u = 0, x = 0;
  for (int i = 0; i <= x; i++){
    if (num >= pow(10.0,i)){
      x++;
    }
  }  
  for (int i = (x-1); i >= 0; i--){
    powint = (int) pow(10.0, i);
    temp = num / powint;
    powint2 = (int) pow(10.0, u);
    inverte += (temp * powint2);
    u++;
    num = num % powint;
  }
  return inverte;
}

int q5(int num)
{
  int valor = 0;
  valor = converter(num);
  return valor;
}

// Questão 06
/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int buscar(int numerobase, int numerobusca){ 
  //numerobase
  int x= 0, u = 0, powint;
  for (int i = 0; i <= x; i++){
    if (numerobase >= pow(10.0,i)){
      x++;
    }
  }   
  int vetorBase[x];
  
  for (int i = (x-1); i >= 0; i--){
    powint = (int) pow(10.0, i);
    vetorBase[u] = numerobase / powint;
    numerobase = numerobase % powint;
    u++;
  }
  //numerobusca  
  int y= 0, z = 0;
  for (int i = 0; i <= y; i++){
    if (numerobusca >= pow(10.0,i)){
      y++;
    }
  } 
  
  int vetorBusca[y];
  
  for (int i = (y-1); i >= 0; i--){
    powint = (int) pow(10.0, i);
    vetorBusca[z] = numerobusca / powint;
    numerobusca = numerobusca % powint;
    z++;
  }

  // encontrando os dados
  int contGeral = 0, contxx = 0, a = 0;
  for (int w = 0; w < x; w++){
    if (vetorBase[w] == vetorBusca[0]){
      if (y == 1){
        contGeral++;
      }else if (y > 1){
        for (a = 1; a < y; a++){
          if (vetorBase[w+a] == vetorBusca[a]){
            contxx++;

          }else{
            contxx = 0;
          }      
        }
        if (contxx == (y - 1)){
          contGeral++;
          contxx = 0;
          w += (a - 1);
        }
      }  
    }      
  }
  return contGeral;
}

int q6(int numerobase, int numerobusca)
{
  int qtdOcorrencias;
  qtdOcorrencias = buscar(numerobase, numerobusca);
  return qtdOcorrencias;
}
