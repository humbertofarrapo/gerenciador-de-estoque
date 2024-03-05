#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include "relatorio.h"

Relatorio relatorio_vendas(Relatorio relatorio) {
    printf("> TOTAL DE VENDAS REALIZADAS: %d\n", relatorio.vendas);
    printf("> LUCRO TOTAL DAS VENDAS: R$ %.2f\n", relatorio.preco);
    if (relatorio.produto_mais_vendido != -1) {
        printf("> PRODUTO MAIS VENDIDO: CÓDIGO %d --- QUANTIDADE %d\n\n", 
        relatorio.produto_mais_vendido, relatorio.quantidade_produto_mais_vendido);
    } else {
        printf("Nenhum produto vendido ainda.\n\n");
    }
    return relatorio;
}

void estoque(Produto* raiz) {
    if (raiz == NULL) {
        printf("Estoque vazio!\n\n");
    } else {
    	lista_estoque(raiz);
    }
}

void lista_estoque(Produto* raiz) {
    if (raiz != NULL) {
        lista_estoque(raiz->esq);
        printf("> CODIGO: %d --- PRECO: R$ %.2f --- TIPO: %s\n", raiz->codigo, raiz->preco, raiz->tipo);
        lista_estoque(raiz->dir);
    }
}
