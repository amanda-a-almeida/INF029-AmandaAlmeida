/*  Struct de cadatro de Alunos e Professores   */
struct dados_pessoa
{
    char matricula[12];
    char nome[50];
    char sexo; // M , F
    int dia_nascimento;
    int mes_nascimento;
    int ano_nascimento; 
    char cpf[15];
    int classificacao; // 0 - professor / 1 - aluno

};
