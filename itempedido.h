#ifndef ITEMPEDIDO_H
#define ITEMPEDIDO_H

typedef struct{
    int pedidoid, produtoid, quantidade;   //id do pedido, do produto e  a quantidade de produto nesse item
    double subtotal;   //quantidade*preço do produto
} ItemPedido;

#endif
