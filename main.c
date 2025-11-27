#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#include "validacoes.h"
#include "cliente.h"
#include "lista_cliente.h"

listaclientes lista;



void menuprincipal();
void menuclientes();
void menuprodutos();
void menupedidos();

int main(){
    initscr();   //inicia o ncurses
    cbreak();   //entra sem esperar nada 
    noecho();   //nâo mostra teclas digitadas
    keypad(stdscr, true);   //faz com que possa usar as setas
    curs_set(0);   //oculta o cursor do mouse

    inicializarlistaclientes(&lista);

    menuprincipal();   //chama o menu principal

    endwin();   //finaliza o ncurses
    return 0;
}

void menuprincipal(){

    int opcao=0;

    while(1){

        clear();
        mvprintw(1, 2, "===========================================");
        mvprintw(2, 2, "           SISTEMA DE PEDIDOS              ");
        mvprintw(3, 2, "===========================================");

        mvprintw(5, 4, "1 - Clientes");     //Aqui é as opcões q vai aparecer na tela e que o cliente vai redirecionar para qual opção deseja
        mvprintw(6, 4, "2 - Produtos");
        mvprintw(7, 4, "3 - Pedidos");
        mvprintw(8, 4, "0 - Sair");

        mvprintw(10, 4, "Escolha uma opção: ");
        refresh();
        opcao = getch();   //Lê cada tecla que for apertada

        switch(opcao){
            case '1':   //Vai pro menu do cliente
            menuclientes();
            break;

            case '2':   //Vai pro menu de produtos
            menuprodutos();
            break;

            case '3':   //Vai pro menu de pedidos
            menupedidos();
            break;

            case '0':   //Sai do menu principal
            return;
        }
    }
}



void menuclientes() {
    int opcao = 0;

    while (1) {
        clear();
        mvprintw(2, 2, "==========================================");
        mvprintw(3, 2, "                 MENU CLIENTES            ");
        mvprintw(4, 2, "==========================================");

        mvprintw(6, 4, "1 - Cadastrar Cliente");
        mvprintw(7, 4, "2 - Consultar Cliente");
        mvprintw(8, 4, "3 - Listar Clientes");
        mvprintw(9, 4, "4 - Remover Cliente");
        mvprintw(10, 4, "0 - Voltar");

        mvprintw(12, 4, "Escolha uma opcao: ");

        refresh();
        opcao = getch();

        switch (opcao) {


    case '1': {
    clear();
    cliente c;

    mvprintw(2,2,"Digite o ID: ");
    echo();
    scanw("%d",&c.id);
    noecho();

    mvprintw(3,2,"Tipo (1 = pf, 2 = pj): ");
    echo();
    scanw("%d",&c.tipo);
    noecho();

    do {
        mvprintw(4,2,"Endereco: ");
        echo();
        getstr(c.endereco);
        noecho();

        if (strlen(c.endereco) < 3) {
            mvprintw(10,2,"Endereco invalido! Tente novamente.");
            getch();
            mvprintw(10,2,"                                       ");
        }

    } while (strlen(c.endereco) < 3);

    do {
        mvprintw(5,2,"Telefone (apenas numeros): ");
        echo();
        getstr(c.telefone);
        noecho();

        if (!validarTelefone(c.telefone)) {
            mvprintw(10,2,"Telefone invalido!");
            getch();
            mvprintw(10,2,"                      ");
        }

    } while (!validarTelefone(c.telefone));

    do {
        mvprintw(6,2,"Email: ");
        echo();
        getstr(c.email);
        noecho();

        if (!validarEmail(c.email)) {
            mvprintw(10,2,"Email invalido!");
            getch();
            mvprintw(10,2,"                ");
        }

    } while (!validarEmail(c.email));


    c.ativo = 1;

    if (c.tipo == pf) {

        do {
            mvprintw(7,2,"Nome: ");
            echo();
            getstr(c.pfdata.nome);
            noecho();

            if (!validarTexto(c.pfdata.nome)) {
                mvprintw(10,2,"Nome invalido!");
                getch();
                mvprintw(10,2,"               ");
            }
        } while (!validarTexto(c.pfdata.nome));

        // ----------- CPF -------------
        do {
            mvprintw(8,2,"CPF: ");
            echo();
            getstr(c.pfdata.cpf);
            noecho();

            if (!validarCPF(c.pfdata.cpf)) {
                mvprintw(10,2,"CPF INVALIDO! Tente novamente.");
                getch();
                mvprintw(10,2,"                                   ");
            }
        } while (!validarCPF(c.pfdata.cpf));

    }
    else if (c.tipo == pj) {

        do {
            mvprintw(7,2,"Razao Social: ");
            echo();
            getstr(c.pjdata.razaosocial);
            noecho();

            if (!validarTexto(c.pjdata.razaosocial)) {
                mvprintw(10,2,"Razao Social invalida!");
                getch();
                mvprintw(10,2,"                          ");
            }
        } while (!validarTexto(c.pjdata.razaosocial));

        do {
            mvprintw(8,2,"CNPJ: ");
            echo();
            getstr(c.pjdata.cnpj);
            noecho();

            if (!validarCNPJ(c.pjdata.cnpj)) {
                mvprintw(10,2,"CNPJ INVALIDO! Tente novamente.");
                getch();
                mvprintw(10,2,"                                   ");
            }
        } while (!validarCNPJ(c.pjdata.cnpj));
    }

    inserircliente(&lista, c);

    mvprintw(12,2,"Cliente cadastrado com sucesso!");
    getch();
    break;
}


    case '2': {     //CONSULTAR CLIENTE
    clear();

    int id;

    mvprintw(2,2,"Digite o ID do cliente: ");
    echo();
    scanw("%d", &id);
    noecho();

    cliente *c = buscarclienteporid(&lista, id);

    if (c == NULL) {
        mvprintw(4,2,"Cliente nao encontrado!");
    } else {
        mvprintw(4,2,"ID: %d", c->id);
        mvprintw(5,2,"Endereco: %s", c->endereco);
        mvprintw(6,2,"Telefone: %s", c->telefone);
        mvprintw(7,2,"Email: %s", c->email);

        if (c->tipo == pf) {
            mvprintw(9,2,"[Pessoa Fisica]");
            mvprintw(10,2,"Nome: %s", c->pfdata.nome);
            mvprintw(11,2,"CPF: %s", c->pfdata.cpf);
        } else {
            mvprintw(9,2,"[Pessoa Juridica]");
            mvprintw(10,2,"Razao Social: %s", c->pjdata.razaosocial);
            mvprintw(11,2,"CNPJ: %s", c->pjdata.cnpj);
        }
    }

    mvprintw(14,2,"Pressione qualquer tecla para voltar...");
    getch();
    break;
}


    case '3': {     //LISTAR TODOS OS CLIENTES
    clear();

    if (lista.tamanho == 0) {
                mvprintw(2,2,"Nenhum cliente cadastrado.");
    } else {
        mvprintw(2,2,"LISTA DE CLIENTES:");
        int linha = 4;

    for (int i = 0; i < lista.tamanho; i++) {
        if (lista.itens[i].ativo == 1) {

        if (lista.itens[i].tipo == pf) {
            mvprintw(linha, 2,
            "ID: %d | PF | Nome: %s",
            lista.itens[i].id,
            lista.itens[i].pfdata.nome);
        }
    else {
        mvprintw(linha, 2,
        "ID: %d | PJ | Razao: %s",
        lista.itens[i].id,
        lista.itens[i].pjdata.razaosocial);
    }

    linha++;
        }
    }
    }

    getch();
    break;
    }


    case '4': {     //REMOVER CLIENTE
    clear();

    int id;

    mvprintw(2,2,"Digite o ID do cliente para remover: ");
    echo();
    scanw("%d", &id);
    noecho();

    if (removercliente(&lista, id)) {
        mvprintw(4,2,"Cliente removido com sucesso!");
    } else {
        mvprintw(4,2,"Cliente nao encontrado!");
    }

    mvprintw(6,2,"Pressione qualquer tecla para voltar...");
    getch();
    break;
}



        case '0':       //Voltar pro menu principal
            return;
        }
    }
}




void menuprodutos(){

    int opcao=0;

    while(1){
        clear();

        mvprintw(1, 2, "===========================================");
        mvprintw(2, 2, "               MENU PRODUTOS               ");
        mvprintw(3, 2, "===========================================");

        mvprintw(5, 4, "1 - Cadastrar Produto");
        mvprintw(6, 4, "2 - Consultar Produtos");
        mvprintw(7, 4, "3 - Listar Produtos");
        mvprintw(8, 4, "4 - Remover Produto");
        mvprintw(9, 4, "0 - Voltar");

        mvprintw(11, 4, "Escolha uma das opção: ");
        refresh();
        opcao = getch();

        switch(opcao){
            case '1':   //Cadastra o produto
            break;

            case '2':   //Consulta o produto
            break;

            case '3':   //Lista o produto
            break;

            case '4':   //Remove o produto
            break;

            case '0':   //Volta ao menu principal
            return;
        }
    }
}


void menupedidos(){

    int opcao=0;

    while(1){
        clear();

        mvprintw(1, 2, "===========================================");
        mvprintw(2, 2, "               MENU PEDIDOS                ");
        mvprintw(3, 2, "===========================================");

        mvprintw(5, 4, "1 - Cadastrar Pedido");
        mvprintw(6, 4, "2 - Consultar Pedido");
        mvprintw(7, 4, "3 - Listar Pedidos");
        mvprintw(8, 4, "4 - Remover Pedido");
        mvprintw(9, 4, "0 - Voltar");

        mvprintw(11, 4, "Escolha uma opção: ");
        refresh();
        opcao = getch();

        switch(opcao){
            case '1':   //Cadastra o pedido
            break;

            case '2':   //Consulta o pedido
            break;

            case '3':   //Lista o pedido
            break;

            case '4':   //Remove o pedido
            break;

            case '0':   //Volta ao menu principal
            return;
        }
    }
}