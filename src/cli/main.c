#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/empilhadeira.h"

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
                printf("===================================\n");
                printf("        Inserir Nova Caixa         \n");
                printf("===================================\n");
                caixa.id = rand() % 10000 + 1;  // Generate random ID between 1 and 10000
                printf("ID gerado para a caixa: %d\n", caixa.id);
                printf("Digite o peso da caixa (em toneladas): ");
                scanf("%d", &caixa.peso);
                printf("Digite a descrição da caixa: ");
                scanf(" %[^\n]", caixa.descricao);
                inserirCaixa(&pilhaA, &pilhaB, &pilhaC, caixa);
                printf("\nCaixa inserida com sucesso!\n");
                limparTela();
                break;
                
            case 2:
                printf("===================================\n");
                printf("          Consultar Caixa          \n");
                printf("===================================\n");
                printf("Digite o ID da caixa para consulta: ");
                scanf("%d", &id);
                consultarCaixa(&pilhaA, id);
                break;

            case 3:
                printf("===================================\n");
                printf("          Remover Caixa            \n");
                printf("===================================\n");
                printf("Digite o ID da caixa para remoção: ");
                scanf("%d", &id);
                removerCaixa(&pilhaA, &pilhaB, &pilhaC, id);
                printf("\nCaixa removida com sucesso!\n");
                break;

            case 4:
                printf("===================================\n");
                printf("           Exibir Pilha            \n");
                printf("===================================\n");
                exibirPilha(&pilhaA);
                break;

            case 5:
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("Opção inválida! Por favor, tente novamente.\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}
