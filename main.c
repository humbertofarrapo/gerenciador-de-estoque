#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include "relatorio.h"
#include "utils.h"

int main() {
    int codigo, quantidade, opcao;
    float preco;

    Produto* p = inicia();
    Relatorio r = {0, 0, -1, 0};

    do {
        menu();
        scanf("%d", &opcao);
        limpa_tela(); 
        limpa_buffer();

        switch (opcao) {
            case 1: {
                printf("Digite o código do produto a ser inserido: ");
                scanf("%d", &codigo);
                limpa_buffer();
                if (codigo <= 0) {
                    printf("Código inválido!\n\n");
                    break;
                }
                if (busca(p, codigo)) {
                    printf("Produto com mesmo código encontrado!\n\n");
                } else {
                    char tipo[MAX_TIPO];
                    printf("Digite o tipo do produto a ser inserido: ");
                    fgets(tipo, sizeof(tipo), stdin);
                    printf("Digite o preço do produto a ser inserido: ");
                    scanf("%f", &preco);
                    p = insere(p, codigo, tipo, preco);
                    limpa_tela();
                    printf("Produto inserido com sucesso!\n\n");
                }
                break;
            }
            case 2: {
                printf("Digite o código do produto a ser removido: ");
                scanf("%d", &codigo);
                limpa_buffer();
                if (busca(p, codigo)) {
                    p = retira(p, codigo);
                    limpa_tela();
                    printf("Produto removido com sucesso!\n\n");
                } else {
                    limpa_tela();
                    printf("Produto não encontrado!\n\n");
                }
                break;
            }
			case 3: {
                printf("Digite o código do produto a ser alterado: ");
                scanf("%d", &codigo);
                if (busca(p, codigo)) {
                    p = retira(p, codigo);
                    printf("Digite o novo código do produto: ");
                    scanf("%d", &codigo);
                    getchar();
                    printf("Digite o novo tipo do produto: ");
                    char tipo[MAX_TIPO];
                    fgets(tipo, sizeof(tipo), stdin);
                    printf("Digite o novo preço do produto: ");
                    scanf("%f", &preco);
                    p = insere(p, codigo, tipo, preco);
                    limpa_tela();
                    printf("Produto alterado com sucesso!\n\n");
                } else {
                    limpa_tela();
                    printf("Produto não encontrado!\n\n");
                }
                break;
            }
            case 4: {
    			printf("Digite o código do produto a ser buscado: ");
    			scanf("%d", &codigo);
    			limpa_tela();
    			p = busca(p, codigo);
    			if (p != NULL) {
        			printf("Produto encontrado:\n");
        			printf("> CODIGO: %d --- PRECO: R$ %.2f --- TIPO: %s\n", p->codigo, p->preco, p->tipo);
    			} else {
        			printf("Produto não encontrado!\n\n");
    			}
    			break;
			}
            case 5: {
                printf("Digite o código do produto a ser vendido: ");
                scanf("%d", &codigo);
                p = busca(p, codigo);
                if (p == NULL) {
                    limpa_tela();
                    printf("Produto não encontrado!\n\n");
                    break; 
                }
                printf("Digite a quantidade a ser vendida: ");
                scanf("%d", &quantidade);
                if (quantidade <= 0) {
                    printf("Quantidade inválida!\n\n");
                    break;
                }
                limpa_tela();
                printf("Produtos vendidos!\n\n");
                r.vendas += quantidade;
                if (quantidade > r.quantidade_produto_mais_vendido) {
                    r.produto_mais_vendido = codigo;
                    r.quantidade_produto_mais_vendido = quantidade;
                }
                r.preco = p->preco * quantidade;
                break;
            }
            case 6: {
    			limpa_tela();
    			estoque(p);
    			break;
			}
            case 7: {
                relatorio_vendas(r);
                break;
            }
            case 0:
                break;
            default:
                printf("Opção inválida!\n\n");
        }
    } while (opcao != 0);
    
    libera(p);
    printf("Até mais!\n");
    return 0;
}
