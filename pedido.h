#ifndef PEDIDO_H
#define PEDIDO_H

typedef struct{
    int id, clienteid;
    char data[11];
    double total;
} Pedido;

#endif