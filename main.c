#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "empilhadeira.h"

void limparTela() {
    system("clear");
}

int main() {
    Pilha pilhaA, pilhaB, pilhaC;
    inicializarPilha(&pilhaA);
    inicializarPilha(&pilhaB);
    inicializarPilha(&pilhaC);

    int opcao, id;
    Caixa caixa;

    do {
        menu();
        scanf("%d", &opcao);
        limparTela();

        switch (opcao) {
        case 1:
            printf("==============\n");
            printf("Inserir Caixa\n");
            printf("==============\n");
            printf("ID: ");
            scanf("%d", &caixa.id);
            printf("Peso: ");
            scanf("%d", &caixa.peso);
            printf("Descrição: ");
            scanf(" %[^\n]", caixa.descricao);
            inserirCaixa(&pilhaA, &pilhaB, &pilhaC, caixa);
            limparTela();
            break;
        case 2:
            printf("===============\n");
            printf("Consultar Caixa\n");
            printf("===============\n");
            printf("ID: ");
            scanf("%d", &id);
            consultarCaixa(&pilhaA, id);
            break;
        case 3:
            printf("==============\n");
            printf("Remover Caixa\n");
            printf("==============\n");
            printf("ID: ");
            scanf("%d", &id);
            removerCaixa(&pilhaA, &pilhaB, &pilhaC, id);
            break;
        case 4:
            printf("==============\n");
            printf("Exibir Pilha\n");
            printf("==============\n");
            exibirPilha(&pilhaA);
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (opcao != 5);
    
    return 0;
}
