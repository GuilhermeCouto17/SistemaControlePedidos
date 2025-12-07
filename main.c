#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#include "validacoes.h"
#include "cliente.h"
#include "lista_cliente.h"
#include "lista_produto.h"
#include "lista_pedido.h"


listaclientes lista;
lista_produto produtos;
lista_pedido pedidos;


void menuprincipal();
void menuclientes();
void menuprodutos();
void menupedidos();
void menuprodutos();


int main(){
    initscr();   //inicia o ncurses
    cbreak();   //entra sem esperar nada 
    noecho();   //nâo mostra teclas digitadas
    keypad(stdscr, true);   //faz com que possa usar as setas
    curs_set(0);   //oculta o cursor do mouse

    inicializarlistaclientes(&lista);
    listaprodutos(&produtos);
    ListaPedidos(&pedidos);


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

        mvprintw(10, 4, "Escolha uma opcao: ");
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
        mvprintw(3, 2, "                 MENU CLIENTES            ");       //Menu de clientes onde ele vai cadastrar os clientes e fazer tudo 
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


    case '2': {
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

    case '3': {
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

    case '4': {
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

        case '0':
            return;
        }
    }
}


void menuprodutos() {
    int opcao = 0;

    while (1) {
        clear();
        mvprintw(2, 2, "=============================");
        mvprintw(3, 2, "        MENU PRODUTOS        ");
        mvprintw(4, 2, "=============================");

        mvprintw(6, 4, "1 - Cadastrar Produto");
        mvprintw(7, 4, "2 - Consultar Produto");
        mvprintw(8, 4, "3 - Listar Produtos");
        mvprintw(9, 4, "4 - Remover Produto");
        mvprintw(10,4, "0 - Voltar");

        mvprintw(12, 4, "Escolha uma opcao: ");
        refresh();
        opcao = getch();

        switch (opcao) {

        case '1': { 
            clear();
            produto p;

            echo();

            mvprintw(2,2,"ID: ");
            scanw("%d",&p.id);

            mvprintw(3,2,"Nome: ");
            getstr(p.nome);

            mvprintw(4,2,"Preco: ");
            scanw("%f",&p.preco);

            noecho();

            p.ativo = 1;

            inserirproduto(&produtos, p);

            mvprintw(6,2,"Produto cadastrado!");
            getch();
            break;
        }

        case '2': { 
            clear();
            int id;

            echo();
            mvprintw(2,2,"Digite o ID: ");
            scanw("%d",&id);
            noecho();

            produto *p = produtoporid(&produtos, id);

            if (p == NULL) {
                mvprintw(4,2,"Produto nao encontrado.");
            } else {
                mvprintw(4,2,"ID: %d", p->id);
                mvprintw(5,2,"Nome: %s", p->nome);
                mvprintw(6,2,"Preco: %.2f", p->preco);
            }

            getch();
            break;
        }

        case '3': { 
            clear();

            if (produtos.tamanho == 0) {
                mvprintw(2,2,"Nenhum produto cadastrado.");
            } else {
                mvprintw(2,2,"LISTA DE PRODUTOS:");

                int linha = 4;
                for (int i = 0; i < produtos.tamanho; i++) {
                    if (produtos.itens[i].ativo == 1) {
                        mvprintw(linha,2,
                            "ID: %d | Nome: %s | Preco: %.2f",
                            produtos.itens[i].id,
                            produtos.itens[i].nome,
                            produtos.itens[i].preco
                        );
                        linha++;
                    }
                }
            }

            getch();
            break;
        }

        case '4': { 
            clear();
            int id;

            echo();
            mvprintw(2,2,"Digite o ID do produto: ");
            scanw("%d",&id);
            noecho();

            if (removerproduto(&produtos, id)) {
                mvprintw(4,2,"Produto removido!");
            } else {
                mvprintw(4,2,"Produto nao encontrado.");
            }

            getch();
            break;
        }

        case '0':
            return;
        }
    }
}


void menupedidos() {
    int opc = 0;

    while (1) {
        clear();
        mvprintw(2,2, "===============================");
        mvprintw(3,2, "          MENU PEDIDOS         ");
        mvprintw(4,2, "===============================");

        mvprintw(6,2, "1 - Cadastrar Pedido");
        mvprintw(7,2, "2 - Consultar Pedido");
        mvprintw(8,2, "3 - Listar Pedidos");
        mvprintw(9,2, "4 - Remover Pedido");
        mvprintw(10,2,"0 - Voltar");

        mvprintw(12,2,"Escolha uma opcao: ");
        refresh();
        opc = getch();

        switch(opc) {

            case '1': {
                clear();
                pedido p;

                mvprintw(2,2,"ID do pedido: ");
                echo(); scanw("%d", &p.id); noecho();

                mvprintw(3,2,"ID do cliente: ");
                echo(); scanw("%d", &p.id_cliente); noecho();

                mvprintw(4,2,"ID do produto: ");
                echo(); scanw("%d", &p.id_produto); noecho();

                mvprintw(5,2,"Quantidade: ");
                echo(); scanw("%d", &p.quantidade); noecho();

                produto *pr = produtoporid(&produtos, p.id_produto);

                if (pr == NULL) {
                    mvprintw(7,2,"Produto nao encontrado!");
                    getch();
                    break;
                }

                p.valor_total = pr->preco * p.quantidade;
                p.ativo = 1;

                inserirPedido(&pedidos, p);

                mvprintw(8,2,"Pedido cadastrado!");
                getch();
                break;
            }

            case '2': {
                clear();
                int id;

                mvprintw(2,2,"Digite o ID do pedido: ");
                echo(); scanw("%d", &id); noecho();

                pedido *p = PedidoPorId(&pedidos, id);

                if (p == NULL)
                    mvprintw(4,2,"Pedido nao encontrado!");
                else {
                    mvprintw(4,2,"ID: %d", p->id);
                    mvprintw(5,2,"Cliente: %d", p->id_cliente);
                    mvprintw(6,2,"Produto: %d", p->id_produto);
                    mvprintw(7,2,"Qtd: %d", p->quantidade);
                    mvprintw(8,2,"Total: %.2f", p->valor_total);
                }

                getch();
                break;
            }

            case '3': {
                clear();
                mvprintw(2,2,"LISTA DE PEDIDOS:");

                int linha = 4;
                for (int i = 0; i < pedidos.tamanho; i++) {
                    if (pedidos.itens[i].ativo == 1) {
                    mvprintw(linha,2,
                    "ID: %d | Cliente: %d | Produto: %d | Qtd: %d | Total: %.2f",
                    pedidos.itens[i].id,
                    pedidos.itens[i].id_cliente,
                    pedidos.itens[i].id_produto,
                    pedidos.itens[i].quantidade,
                    pedidos.itens[i].valor_total
                    );
                    linha++;
                }
            }

                getch();
                break;
            }

            case '4': {
                clear();
                int id;
                mvprintw(2,2,"ID do pedido: ");
                echo(); scanw("%d", &id); noecho();

                if (removerPedido(&pedidos, id))
                    mvprintw(4,2,"Pedido removido!");
                else
                    mvprintw(4,2,"Pedido nao encontrado!");

                getch();
                break;
            }

            case '0':
                return;
        }
    }
}
