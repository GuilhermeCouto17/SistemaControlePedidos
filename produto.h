#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct {
    int id;
    char nome[100];
    float preco;
    int ativo;
} produto;

#endif