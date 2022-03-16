#include <stdio.h>

int mi = 0, ver1 = 1, ver2, ver3;//mi = escolha do menu inicial
int comp;
int matricula_exclusao;
int cont; //contador geral do vetor pessoas para o cadastro

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

int cadastro_aluno (void) { //função de cadastro de aluno criar variavel cumulativa para o vetor pessoas em cadastro
    if (ver2 == 1){
        struct dados_pessoa pessoas[cont];//u será a variavel do vetor de pessoas[u].
        printf("Digite o Numero da Matricula (11 Digitos):\n");
        scanf("%s", &pessoas[cont].matricula);
        printf("Digite o Nome do aluno:\n");
        fgets(pessoas[cont].nome, 50, stdin);
        size_t ln = strlen(pessoas[u].nome)-1;
        if (pessoas[cont].nome[ln] == '\n'){
            pessoas[cont].nome[ln] = '\0';
        }
        printf("Digite O sexo:\n");
        scanf("%c", &pessoas[cont].sexo);
        for (ver3 < 1, ver3 = 0, ver3++){//repetição para a verificação da data
            printf("Digite a data de nascimento no formato dd/mm/aaaa\n");
            scanf("%d/%d/%d", &pessoas[cont].dia_nascimento, pessoas[cont].mes_nascimento, pessoas[cont].ano_nascimento);
            //chamar função de verificação de data
        }
        for (ver3 < 1, ver3 = 0, ver3 ++){
            printf("Digite o CPF, sem pontos ou traço:\n");
            scanf("%s",&pessoas[cont].cpf);
            //chamar função de verificação de cpf
        }
        pessoas[u].classificacao = 1;
        cont++;
    }
    return(-20);//definir - 20 como cadastro realizado com sucesso.
}

int cadastro_professor (void) { //funçaõ de cadastro de professor
    if (ver2 == 2){
        struct dados_pessoa pessoas[cont];//u será a variavel do vetor de pessoas[u].
        printf("Digite o Numero da Matricula (11 Digitos):\n");
        scanf("%s", &pessoas[cont].matricula);
        printf("Digite o Nome do Professor:\n");
        fgets(pessoas[cont].nome, 50, stdin);
        size_t ln = strlen(pessoas[cont].nome)-1;
        if (pessoas[cont].nome[ln] == '\n'){
            pessoas[cont].nome[ln] = '\0';
        }
        printf("Digite O sexo:\n");
        scanf("%c", &pessoas[cont].sexo);
        for (ver3 < 1, ver3 = 0, ver3++){//repetição para a verificação da data
            printf("Digite a data de nascimento no formato dd/mm/aaaa\n");
            scanf("%d/%d/%d", &pessoas[cont].dia_nascimento, pessoas[cont].mes_nascimento, pessoas[cont].ano_nascimento);
            //chamar função de verificação de data
        }
        for (ver3 < 1, ver3 = 0, ver3 ++){
            printf("Digite o CPF, sem pontos ou traço:\n");
            scanf("%s",&pessoas[cont].cpf);
            //chamar função de verificação de cpf
        }
        pessoas[u].classificacao = 0;
    }
    return(-20);//definir - 20 como cadastro realizado com sucesso.
}

int excluir_pessoa (void){//função de excluir cadastro
    int ver4 = 0;
    printf("Digite a matricula do aluno ou professor que deseja excluir.\n");
    scanf("%d", &matricula_exclusao);
    u = 0; // contador do vetor geral do cadastro
    while (ver4 == 0){
        if (matricula_exclusao == pessoas[u].matricula){
            pessoas[u].matricula = -1;
            ver4++;
        }
        else{
            u++;
        }
    }
    return(-20);
}

int atualizar_pessoa(void){ ///função de atualizar cadastro
    int matricula_alterar;
    int ver5;
    int campo_alterar;
    printf("Digite A matricula do aluno ou professor que voce deseja alterar:\n");
    scanf("%d",& matricula_alterar);
    ver5 = 0;
    u = 0;
    while (ver5 == 0)
    {
        if(matricula_alterar == pessoas[u].matricula){
            if (pessoas[u].classificacao == 0){
                while(ver6 == 0){
                    printf("Professor:\n\n");
                    printf("1 - Matricula: %d\n2 - Nome: %s\n3 - Sexo: %c\n4 - Data de Nascimento: %d/%d/%d\n5 - CPF: %d\n6 - Sair\n", pessoas[u].matricula, pessoas[u].nome, pessoas[u].sexo, pessoas[u].dia_nascimento, pessoas[u].mes_nascimento, pessoas[u].ano_nascimento, pessoas[u].cpf);
                    printf("Digite o que você deseja alterar:\n");
                    scanf("%d", &campo_alterar);
                    switch(campo_alterar){
                        case 1:
                            printf("\nDigite a nova matricula:\n");
                            scanf("%d",&pessoas[u].matricula);
                            printf("\nMatricula Alterada.\n");
                            break;
                        case 2:
                            printf("Digite o Novo nome:\n");
                            fgets(pessoas[u].nome, 50, stdin);
                            size_t ln = strlen(pessoas[u].nome)-1;
                            if (pessoas[u].nome[ln] == '\n'){
                                pessoas[u].nome[ln] = '\0';
                            }
                            printf("\nNome Alterado.\n");
                            break;
                        case 3:
                            printf("\nDigite O sexo:\n");
                            scanf("%c", pessoas[u].sexo);
                            printf("\nSexo Alterado.\n");
                            break;
                        case 4:
                            printf("\n Digite a nova Data de Nascimento:\n");
                            scanf("%d/%d/%d",&pessoas[u].dia_nascimento, pessoas[u].mes_nascimento, pessoas[u].ano_nascimento);
                            printf("\nData de Nascimento alterada.\n");
                            break;
                        case 5:
                            printf("\nDigite o novo CPF:\n");
                            scanf("%d",& pessoas[u].cpf);
                            printf("\nCPF alterado.\n");
                            break;
                        case 6:
                            ver6 = 1;
                            break;
                        default:
                            printf("\nOpção inválida.\n")
                    }
                }
                ver5++; 
            }
            else{
                while(ver6 == 0){
                    printf("Aluno:\n\n");
                    printf("1 - Matricula: %d\n2 - Nome: %s\n3 - Sexo: %c\n4 - Data de Nascimento: %d/%d/%d\n5 - CPF: %d\n6 - Sair\n", pessoas[u].matricula, pessoas[u].nome, pessoas[u].sexo, pessoas[u].dia_nascimento, pessoas[u].mes_nascimento, pessoas[u].ano_nascimento, pessoas[u].cpf);
                    printf("Digite o que você deseja alterar:\n");
                    scanf("%d", &campo_alterar);
                    switch(campo_alterar){
                        case 1:
                            printf("\nDigite a nova matricula:\n");
                            scanf("%d",&pessoas[u].matricula);
                            printf("\nMatricula Alterada.\n");
                            break;
                        case 2:
                            printf("Digite o Novo nome:\n");
                            fgets(pessoas[u].nome, 50, stdin);
                            size_t ln = strlen(pessoas[u].nome)-1;
                            if (pessoas[u].nome[ln] == '\n'){
                                pessoas[u].nome[ln] = '\0';
                            }
                            printf("\nNome Alterado.\n");
                            break;
                        case 3:
                            printf("\nDigite O sexo:\n");
                            scanf("%c", pessoas[u].sexo);
                            printf("\nSexo Alterado.\n");
                            break;
                        case 4:
                            printf("\n Digite a nova Data de Nascimento:\n");
                            scanf("%d/%d/%d",&pessoas[u].dia_nascimento, pessoas[u].mes_nascimento, pessoas[u].ano_nascimento);
                            printf("\nData de Nascimento alterada.\n");
                            break;
                        case 5:
                            printf("\nDigite o novo CPF:\n");
                            scanf("%d",& pessoas[u].cpf);
                            printf("\nCPF alterado.\n");
                            break;
                        case 6:
                            ver6 = 1;
                            break;
                        default:
                            printf("\nOpção inválida.\n")
                    }
                }
                ver5++;
        else{
            u++;
        }
        u++;
    }
}
