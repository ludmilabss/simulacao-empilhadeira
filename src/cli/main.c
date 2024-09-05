#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/empilhadeira.h"

int validarInteiro(int inteiro) {
    return inteiro > 0 && inteiro <=1000;
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
                caixa.id = rand() % 10000 + 1;  // Generate random ID between 1 and 10000
                printf("ID gerado para a caixa: %d\n", caixa.id);
                do {
                    printf("Digite o peso da caixa (em toneladas): ");
                if (scanf("%d", &caixa.peso) != 1 || !validarInteiro(caixa.peso)) {
                    printf("Idade inválida. Por favor, digite um peso válido.\n");
                    while (getchar() != '\n');
        } 
    }while (!validarInteiro(caixa.peso));
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
                        while (getchar() != '\n');
                    } 
                }while (!validarInteiro(id));
                consultarCaixa(&pilhaA, id);
                break;

            case 3:
                printf("===================================\n");
                printf("          Remover Caixa            \n");
                printf("===================================\n");
                do {
                    printf("Digite o peso da caixa : ");
                if (scanf("%d", &id) != 1 || !validarInteiro(id)) {
                    printf("ID inválido. Por favor, digite um ID válido.\n");
                    while (getchar() != '\n');
                } }while (!validarInteiro(id));
                removerCaixa(&pilhaA, &pilhaB, &pilhaC, id);
                limparTela();
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
