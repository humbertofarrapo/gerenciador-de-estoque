#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void limpa_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void limpa_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void menu() {
    printf("****************************\n");
    printf("1. INSERIR\n");
    printf("2. REMOVER\n");
    printf("3. ALTERAR\n");
    printf("4. BUSCAR\n");
    printf("5. VENDER\n");
    printf("6. ESTOQUE ATUAL\n");
    printf("7. RELATÓRIO DE VENDAS\n");
    printf("0. SAIR\n");
    printf("****************************\n\n");
    printf("Opção selecionada: ");
}
