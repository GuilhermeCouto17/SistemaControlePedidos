#include <string.h>

#include "lista_cliente.h"

void inicializarlistaclientes(listaclientes *l){        //Ela é usada para iniciar a lista de clientes, coloca o tamanho da lista em 0 que indica que ainda não exista nenhum cliente cadastrado.
    l->tamanho=0;
}
int inserircliente(listaclientes *l, cliente c){        //Adiciona um novo cliente ela verifica se a espaço e depois adiciona no final da lista.
    if(l->tamanho >= max_clientes)
    return 0;
    l->itens[l->tamanho]=c;
    l->tamanho++;
    return 1;
}

cliente* buscarclienteporid(listaclientes *l, int id){      //Aqui ele busca o id do cliente na lista de tiver ele retorna com o endereço do cliente se não ele retorna null.
    for(int i=0; i< l->tamanho; i++){
        if(l->itens[i].id == id && l->itens[i].ativo == 1)
        return &l->itens[i];
    }
    return NULL;
}

int removercliente(listaclientes *l, int id){       //Isso aqui evita do cliente ser apagado da memoria mas ele deixa de existir pro sistema.
    for(int i=0; i< l->tamanho; i++){
        if(l->itens[i].id == id && l->itens[i].ativo == 1){
            l->itens[i].ativo = 0;
            return 1;
        }
    }
    return 0;
}  

//Ele implementa todas as operações da lista de clientes do sistema, deixa sempre a lista limpa pra receber um novo cadastro, adiciona um novo cliente, busca o id do cliente, e remove o cliente.

