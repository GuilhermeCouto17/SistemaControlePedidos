#ifndef LISTA_PRODUTO_H
#define LISTA_PRODUTO_H

#include "produto.h"

#define max_produtos 100

typedef struct {
    produto itens[max_produtos];
    int tamanho;
} lista_produto;

void listaprodutos(lista_produto *l);
int inserirproduto(lista_produto *l, produto p);
produto* produtoporid(lista_produto *l, int id);
int removerproduto(lista_produto *l, int id);

#endif
