#ifndef lista_cliente_h
#define lista_cliente_h

#include "cliente.h"

#define max_clientes 100        //Usado para definir a quantidade maxima de clientes

typedef struct{
    cliente itens[max_clientes];        //Ela funciona como um vetor organizado onde todos os cliente vão ser guardados e fala a quantidade de clientes
    int tamanho;
} listaclientes;        //Aqui são todas as funções usadas para manipular a lista de clientes 
void inicializarlistaclientes(listaclientes *l);        //Deixa a lista vazia 
int inserircliente(listaclientes *l, cliente c);        //Adiciona um novo cliente
cliente* buscarclienteporid(listaclientes *l, int id);      //Procuta o id do cliente
int removercliente(listaclientes *l, int id);       //E remove o cliente do sistema 

#endif

//Ele define como que as lista funcionão e para que serve cada uma delas e sua função