#include <stdlib.h>

#include "lista_produto.h"

void listaprodutos(lista_produto *l) {      //Inicia a lista de produtos com tamanho 0
    l->tamanho = 0;
}

int inserirproduto(lista_produto *l, produto p) {       //Adiciona o produto e a quantidade de itens daquele produto
    if (l->tamanho >= max_produtos)
        return 0;

    l->itens[l->tamanho] = p;
    l->tamanho++;
    return 1;
}

produto* produtoporid(lista_produto *l, int id) {       //Busca o produto pelo id dele e se tiver cadastrado mostra o produto e sua quantidade
    for (int i = 0; i < l->tamanho; i++) {
        if (l->itens[i].id == id && l->itens[i].ativo == 1)
            return &l->itens[i];
    }
    return NULL;
}

int removerproduto(lista_produto *l, int id) {      //Remove o produto cadastrado do sistema
    for (int i = 0; i < l->tamanho; i++) {
        if (l->itens[i].id == id && l->itens[i].ativo == 1) {
        l->itens[i].ativo = 0;
            return 1;
        }
    }
    return 0;
}

        //Aqui ele define todas as funções da lista de produtos e oq cada uma delas faz no caso a sua função