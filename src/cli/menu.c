#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "pilha.h"

void limparTela() {
    system("clear");
}

void menu() {
    printf("=====================\n");
    printf("  Menu de Operações  \n");
    printf("=====================\n");
    printf("1. Inserir Caixa\n");
    printf("2. Consultar Caixa\n");
    printf("3. Remover Caixa\n");
    printf("4. Exibir Pilha\n");
    printf("5. Sair\n");
    printf("=====================\n");
    printf("Escolha uma opção: ");
}

void exibirPilha(Pilha *pilha) {
    if (pilha->topo == -1) {
        printf("Pilha Vazia\n");
    } else {
        printf("Pilha\n");
        for (int i = pilha->topo; i >= 0; i--) {
            exibirCaixa(pilha->caixas[i]);
        }
        printf("=====================\n");
    }
}
