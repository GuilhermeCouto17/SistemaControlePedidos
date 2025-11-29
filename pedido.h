#ifndef PEDIDO_H
#define PEDIDO_H

typedef struct {
    int id;
    int id_cliente;
    int id_produto;
    int quantidade;

    float valor_total;

    int ativo;
} pedido;

#endif