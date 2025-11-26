#include <string.h>

#include "lista_cliente.h"

void inicializarlistaclientes(listaclientes *l){
    l->tamanho=0;
}
int inserircliente(listaclientes *l, cliente c){
    if(l->tamanho >= max_clientes)
    return 0;
    l->itens[l->tamanho]=c;
    l->tamanho++;
    return 1;
}

cliente* buscarclienteporid(listaclientes *l, int id){
    for(int i=0; i< l->tamanho; i++){
        if(l->itens[i].id == id && l->itens[i].ativo == 1)
        return &l->itens[i];
    }
    return NULL;
}

int removercliente(listaclientes *l, int id){
    for(int i=0; i< l->tamanho; i++){
        if(l->itens[i].id == id && l->itens[i].ativo == 1){
            l->itens[i].ativo = 0;
            return 1;
        }
    }
    return 0;
}