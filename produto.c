#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

Produto* inicia() {
    return NULL;
}

Produto* busca(Produto* raiz, int codigo) {
    if (raiz == NULL || raiz->codigo == codigo)
        return raiz;   
    if (raiz->codigo > codigo)
        return busca(raiz->esq, codigo);
    else
        return busca(raiz->dir, codigo);
}

Produto* insere(Produto* raiz, int codigo, const char* tipo, float preco) {
    if (raiz == NULL) {
        Produto* novo_produto = (Produto*)malloc(sizeof(Produto));
        if (novo_produto == NULL) {
            printf("Erro ao alocar memória.\n");
            return NULL;
        }
        novo_produto->codigo = codigo;
        strncpy(novo_produto->tipo, tipo, MAX_TIPO);
        novo_produto->tipo[MAX_TIPO - 1] = '\0'; 
        novo_produto->preco = preco;
        novo_produto->esq = novo_produto->dir = NULL;
        return novo_produto;
    }
    else if (codigo < raiz->codigo)
        raiz->esq = insere(raiz->esq, codigo, tipo, preco);
    else if (codigo > raiz->codigo)
        raiz->dir = insere(raiz->dir, codigo, tipo, preco); 
    return raiz;
}

Produto* retira(Produto* raiz, int codigo) {
    if (raiz == NULL)
        return NULL;
    if (codigo < raiz->codigo)
        raiz->esq = retira(raiz->esq, codigo);
    else if (codigo > raiz->codigo)
        raiz->dir = retira(raiz->dir, codigo);
    else {
        if (raiz->esq == NULL) {
            Produto* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            Produto* temp = raiz->esq;
            free(raiz);
            return temp;
        } else {
            Produto* substituto = raiz->esq;
            while (substituto->dir != NULL)
                substituto = substituto->dir;
            *raiz = *substituto;
            raiz->esq = retira(raiz->esq, substituto->codigo);
        }
    }
    return raiz;
}

void libera(Produto* raiz) {
    if (raiz == NULL)
        return;    
    libera(raiz->esq);
    libera(raiz->dir);
    free(raiz);
}
