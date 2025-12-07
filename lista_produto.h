#ifndef LISTA_PRODUTO_H
#define LISTA_PRODUTO_H

#include "produto.h"

#define max_produtos 100        //Aqui mostra a quantidade maxima de produtos 

typedef struct {        //Aqui ele armazena os produtos 
    produto itens[max_produtos];
    int tamanho;
} lista_produto;

void listaprodutos(lista_produto *l);       //Inicia a lista de produtos com tamanho 0
int inserirproduto(lista_produto *l, produto p);        //Adiciona um produto novo na lista de produtos
produto* produtoporid(lista_produto *l, int id);        //Busca o produto pelo id que foi cadastrado no produto
int removerproduto(lista_produto *l, int id);       //Aqui ele remove o produto do sistema 

#endif

//Aqui mostra as funções e oq elas devem fazer basicamente como um guia