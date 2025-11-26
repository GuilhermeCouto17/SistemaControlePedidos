#ifndef CLIENTE_H
#define CLIENTE_H //O define, ifndef, endif evitam incluir o mesmo cabeçalho 2 vezes

#define pf 1
#define pj 2

typedef struct{
    char nome[100];
    char cpf[20];
} pessoafisica;

typedef struct{
    char razaosocial[100];
    char cnpj[20];
} pessoajuridica;

typedef struct{
    int id;
    int tipo;
    int ativo;

    char endereco[100];
    char telefone[20];
    char email[50];

    pessoafisica pfdata;
    pessoajuridica pjdata;
} cliente;

#endif


