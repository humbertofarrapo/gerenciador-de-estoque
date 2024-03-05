#ifndef RELATORIO_H
#define RELATORIO_H

// Estrutura para representar um relatório de vendas
typedef struct Relatorio Relatorio;

struct Relatorio {
    int vendas;
    float preco;
    int produto_mais_vendido;
    int quantidade_produto_mais_vendido;
};

// Função para exibir o relatório de vendas
Relatorio relatorio_vendas(Relatorio relatorio);

// Função para verificar o estado do estoque
void estoque(Produto* raiz);

// Função para listar o estoque atual
void lista_estoque(Produto* raiz);

#endif
