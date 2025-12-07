#ifndef CLIENTE_H
#define CLIENTE_H   //O define, ifndef, endif evitam incluir o mesmo cabeçalho 2 vezes

#define pf 1       //Tipos de cliente pf-pessoa fisica e pj-pessoa juridica 
#define pj 2

typedef struct{
    char nome[100];     //Guarda as informações dos clientes fisicos 
    char cpf[20];
} pessoafisica;

typedef struct{
    char razaosocial[100];      //Guarda iformações das pessoas juridicas
    char cnpj[20];
} pessoajuridica;

typedef struct{     //Aqui ele guarda as informaações que iremos realmente usar
    int id;     //É o numero do cliente
    int tipo;       //O tipo do cliente se é pj ou pf
    int ativo;      //Se o cliente for ativo 1 se não for 0 removido 

    char endereco[100];
    char telefone[20];
    char email[50];

    pessoafisica pfdata;
    pessoajuridica pjdata;
} cliente;

#endif

//O cliente.h foi criado para organizar os dados dos clientes, ele é um modelo de estrutura de um cliente que define a forma que o cliente é armazenado na memoria.