/******************************************************************************

Q08 - Crie um programa que tenha uma função cadastrarCliente. Essa função deve 
ler os dados do cliente (nome, dataNascimento, cpf, sexo) e retornar os dados 
do cliente. A função main deve imprimir os dados do cliente.

*******************************************************************************/
#include <stdio.h>

char nome[50];
int dataNascimento_dia;
int dataNascimento_mes;
int dataNascimento_ano;
char cpf[12];
char sexo;
    
int cadastrarCliente(){
    printf("Nome Cliente:\n >>> ");
    fflush(stdin);
    fgets(nome, 50, stdin);
    for(int i=0; nome[i]; i++) if(nome[i] =='\n') nome[i]=0;
    
    printf("Data nascimento (dd/mm/aaaa):\n >>> ");
    scanf("%d/%d/%d", &dataNascimento_dia, &dataNascimento_mes, &dataNascimento_ano);
    
    printf("CPF Cliente:\n >>> ");
    scanf("%s", &cpf);
    
    getchar();
    printf("Digite o sexo (F / M):\n>>> ");    
    scanf("%c", &sexo);
    sexo = toupper(sexo);
    
}


int main()
{
    cadastrarCliente();
    printf("\nNome: %s", nome);
    printf("\nData nascimento: %d/%d/%d", dataNascimento_dia, dataNascimento_mes, dataNascimento_ano);
    printf("\nCPF: %s", cpf);
    printf( "\nSexo: %c", sexo);
    
}
