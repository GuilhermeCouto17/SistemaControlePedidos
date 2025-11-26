#ifndef lista_cliente_h
#define lista_cliente_h

#include "cliente.h"

#define max_clientes 100

typedef struct{
    cliente itens[max_clientes];
    int tamanho;
} listaclientes;
void inicializarlistaclientes(listaclientes *l);
int inserircliente(listaclientes *l, cliente c);
cliente* buscarclienteporid(listaclientes *l, int id);
int removercliente(listaclientes *l, int id);

#endif