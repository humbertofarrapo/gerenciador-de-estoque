#ifndef PRODUTO_H
#define PRODUTO_H

#define MAX_TIPO 50

// Estrutura para representar um produto
typedef struct Produto Produto;

struct Produto {
    int codigo;
    char tipo[MAX_TIPO];
    float preco;
    struct Produto *esq;
    struct Produto *dir;
};

// Função para inicializar a árvore de produtos
Produto* inicia();

// Função para buscar um produto na árvore pelo código
Produto* busca(Produto* raiz, int codigo); 

// Função para inserir um produto na árvore 
Produto* insere(Produto* raiz, int codigo, const char* tipo, float preco); 

// Função para remover um produto da árvore
Produto* retira(Produto* raiz, int codigo);

// Função para liberar a memória alocada para a árvore de produtos
void libera(Produto* raiz);

#endif
