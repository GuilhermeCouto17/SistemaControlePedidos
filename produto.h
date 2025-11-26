#define PRODUTO_H
#ifndef PRODUTO_H

typedef struct{
    int id;  //Identificação do produto 
    char descricao[100];  //Nome do produto ou sua descrição
    double preco;  //Preço do produto
    int estoque;  //Quantidade de produto em estoque 
} Produto;

#endif