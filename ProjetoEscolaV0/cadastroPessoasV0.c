#ifndef cadastroPessoasV0_H
#define cadastroPessoasV0_H

struct dados_pessoa
{
    int matricula;
    char nome[50];
    char sexo; // M , F
    int dia_nascimento;
    int mes_nascimento;
    int ano_nascimento; 
    char cpf[15];
    int classificacao; // 0 - professor / 1 - aluno

}

#endif /* adastroPessoasV0_H */