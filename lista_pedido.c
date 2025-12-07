#include <string.h>
#include "lista_pedido.h"

void ListaPedidos(lista_pedido *l) {        //Inicia a lista de pedidos com o tamanho 0 
    l->tamanho = 0;
}

int inserirPedido(lista_pedido *l, pedido p) {      //Adiciona um pedido novo na lista e que não possa passar o maximo de pedidos 
    if (l->tamanho >= max_pedidos)
    return 0;

    l->itens[l->tamanho] = p;
    l->tamanho++;
    return 1;
}

pedido* PedidoPorId(lista_pedido *l, int id) {      //Ele busca o pedido pelo id que foi cadastrado no pedido 
    for (int i = 0; i < l->tamanho; i++) {
        if (l->itens[i].id == id && l->itens[i].ativo == 1)
        return &l->itens[i];
    }
    return NULL;
}

int removerPedido(lista_pedido *l, int id) {        //Ele apaga um pedido da lista de pedidos
    for (int i = 0; i < l->tamanho; i++) {
        if (l->itens[i].id == id) {
        l->itens[i].ativo = 0;
        return 1;
        }
    }
    return 0;
}

//Ele é o arquivo que vai para o main que é o principal e ele comanda tudo, como adicionar um pedido, consultar, ver a lista de pedidos, e remover os pedidos