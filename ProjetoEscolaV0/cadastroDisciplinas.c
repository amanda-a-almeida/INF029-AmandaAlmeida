#include <stdio.h>
#include <string.h> /* elimina o '/n' durante o gets() por conta do espaço entre os inputs do usuário  */
#define TAM = ln(disciplina[])
i=0;

/*   Criando a função de chamada para cadastro de disciplina    */
int inserirDisciplina(void){
  printf("******************************  CADASTRO DE DISCIPLINA ******************************  \n");

  struct cadastro_disciplina disciplina[i];
  printf("Nome da Disciplina: ");
  fgets(disciplina[i].nome_disciplina, 50, stdin); /* leitura da string nome_disciplina */
  size_t ln = strlen(disciplina[i].nome_disciplina) -1;
  if (disciplina[i].nome_disciplina[ln] == '\n'){
    disciplina[i].nome_disciplina[ln] = '\0';
  };

  printf("Código da Disciplina (5 dígitos): ");
  scanf("%s", &disciplina[i].codigo_disciplina);

  printf("Semestre (x): ");
  scanf("%i", &disciplina[i].semestre);

  printf("Matricula do Professor da Disciplina (11 dígitos): ");
  scanf("%s", &disciplina[i].codigo_disciplina);
};
