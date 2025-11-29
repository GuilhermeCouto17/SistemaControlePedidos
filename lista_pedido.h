#ifndef LISTA_PEDIDO_H
#define LISTA_PEDIDO_H

#include "pedido.h"

#define max_pedidos 100

typedef struct {
    pedido itens[max_pedidos];
    int tamanho;
} lista_pedido;

void ListaPedidos(lista_pedido *l);
int inserirPedido(lista_pedido *l, pedido p);
pedido* PedidoPorId(lista_pedido *l, int id);
int removerPedido(lista_pedido *l, int id);

#endif
