#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct {
    int id;     //Cadastra o id do produto
    char nome[100];     //O nome do produto sendo cadastrado
    float preco;        //O preço daquele produto
    int ativo;
} produto;

#endif

//Aqui basicamente cadastra o produto colocando seu id e o nome do produto e o preço.