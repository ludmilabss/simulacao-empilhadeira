#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/empilhadeira.h"

int validarInteiro(int inteiro) {
    return inteiro > 0 && inteiro <= 1000;
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
                printf("===================================\n");
                printf("        Inserir Nova Caixa         \n");
                printf("===================================\n");
                caixa.id = rand() % 1000 + 1;  // Gera ID aleatório entre 1 e 1000
                printf("ID gerado para a caixa: %d\n", caixa.id);
    do {
        printf("Digite o peso da caixa (3, 5 ou 7 toneladas): ");
        if (scanf("%d", &caixa.peso) != 1 || (caixa.peso != 3 && caixa.peso != 5 && caixa.peso != 7)) {
            printf("Peso inválido. Por favor, digite um peso válido.\n");
            while (getchar() != '\n');
        }
    } while (caixa.peso != 3 && caixa.peso != 5 && caixa.peso != 7);
                
                printf("Digite a descrição da caixa: ");
                scanf(" %[^\n]", caixa.descricao);
                inserirCaixa(&pilhaA, &pilhaB, &pilhaC, caixa);
                limparTela();
                printf("\nCaixa inserida com sucesso!\n\n");
                break;

            case 2:
                printf("===================================\n");
                printf("          Consultar Caixa          \n");
                printf("===================================\n");
                do {
                    printf("Digite o ID da caixa: ");
                    if (scanf("%d", &id) != 1 || !validarInteiro(id)) {
                        printf("ID inválido. Por favor, digite um ID válido.\n");
                        while (getchar() != '\n');  // Limpa o buffer de entrada
                    }
                } while (!validarInteiro(id));
                limparTela();
                // Verifica nas três pilhas
                consultarCaixa(&pilhaA, &pilhaB, &pilhaC, id);
                printf("\n");
                break;


            case 3:
                printf("===================================\n");
                printf("          Remover Caixa            \n");
                printf("===================================\n");
                do {
                    printf("Digite o ID da caixa: ");
                    if (scanf("%d", &id) != 1 || !validarInteiro(id)) {
                        printf("ID inválido. Por favor, digite um ID válido.\n");
                        while (getchar() != '\n');
                    }
                } while (!validarInteiro(id));
                removerCaixa(&pilhaA, &pilhaB, &pilhaC, id);
                break;

            case 4:
                printf("===================================\n");
                printf("           Exibir Pilha            \n");
                printf("===================================\n");
                exibirPilha(&pilhaA);
                printf("\n");
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
