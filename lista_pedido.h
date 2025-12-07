#ifndef LISTA_PEDIDO_H
#define LISTA_PEDIDO_H

#include "pedido.h"

#define max_pedidos 100     //Define o numero maximo de pedidos.

typedef struct {        //Ele armazena todos os pedidos cadastrados
    pedido itens[max_pedidos];
    int tamanho;
} lista_pedido;

void ListaPedidos(lista_pedido *l);     //Iniciar a lista de pedidos com o tamanho 0
int inserirPedido(lista_pedido *l, pedido p);       //Serve para inserir os pedidos 
pedido* PedidoPorId(lista_pedido *l, int id);       //Busca o id do pedido
int removerPedido(lista_pedido *l, int id);     //Remove o pedido

#endif

//Aqui é basicamente a estrutura dos pedidos, nele tem todas as funções que iremos usar no lista de pedidos e oq cada uma dela faz