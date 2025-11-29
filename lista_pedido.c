#include <string.h>
#include "lista_pedido.h"

void ListaPedidos(lista_pedido *l) {
    l->tamanho = 0;
}

int inserirPedido(lista_pedido *l, pedido p) {
    if (l->tamanho >= max_pedidos)
        return 0;

    l->itens[l->tamanho] = p;
    l->tamanho++;
    return 1;
}

pedido* PedidoPorId(lista_pedido *l, int id) {
    for (int i = 0; i < l->tamanho; i++) {
        if (l->itens[i].id == id && l->itens[i].ativo == 1)
            return &l->itens[i];
    }
    return NULL;
}

int removerPedido(lista_pedido *l, int id) {
    for (int i = 0; i < l->tamanho; i++) {
        if (l->itens[i].id == id) {
            l->itens[i].ativo = 0;
            return 1;
        }
    }
    return 0;
}
