#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "pilha.h"

void limparTela() {
    system("clear");
}

void menu() {
    printf("===================================\n");
    printf("   Gerenciamento de Empilhadeira   \n");
    printf("===================================\n");
    printf("1. Inserir nova caixa\n");
    printf("2. Consultar caixa\n");
    printf("3. Remover caixa\n");
    printf("4. Exibir pilha A\n");
    printf("5. Sair\n");
    printf("===================================\n");
    printf("Escolha uma opção: ");
}
