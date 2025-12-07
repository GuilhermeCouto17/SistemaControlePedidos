#ifndef PEDIDO_H
#define PEDIDO_H

typedef struct {        //Mostra o pedido feito pelo cliente
    int id;     //Identifica o id do pedido que foi cadastrado 
    int id_cliente;     //O id do cliente que fez o pedido 
    int id_produto;     //O id do produto que o cliente pediu 
    int quantidade;     //A quantidade de de itens que o cliente pediu

    float valor_total;      //Mostra o valor total do produto pedido, somando a quantidade de itens 

    int ativo;
} pedido;

#endif

//Ele mostra qualquer pedido só vc ter o id do cliente e do pedido que consegue ver os itens a quantidade e o valor total a ser pago.