#include "empilhadeira.h"
#include <string.h> 
#include <stdio.h>

void inserirCaixa(Pilha* pilhaA, Pilha* pilhaB, Pilha* pilhaC, Caixa caixa) {
    if (pilhaA->topo > 0 && caixa.peso > pilhaA->caixas[pilhaA->topo - 1].peso) {
        while (pilhaA->topo > 0 && caixa.peso > pilhaA->caixas[pilhaA->topo - 1].peso) {
            moverCaixa(pilhaA, pilhaB);
        }
    }

    // Inserir a nova caixa na pilha A
    if (!empilhar(pilhaA, caixa)) {
        printf("Erro ao inserir caixa na pilha A.\n");
    }

    // Mover caixas da pilha B de volta para a pilha A
    while (pilhaB->topo > 0) {
        moverCaixa(pilhaB, pilhaA);
    }
}


void consultarCaixa(Pilha* pilhaA, Pilha* pilhaB, Pilha* pilhaC, int id) {
    int pos;
    // Verifica na pilha A
    pos = buscarCaixa(pilhaA, id);
    if (pos != -1) {
        printf("===================================\n");
        printf("          Consultar Caixa          \n");
        printf("===================================\n");
        printf("Caixa encontrada na pilha A.\n");
        exibirCaixa(pilhaA->caixas[pos]);
        return;
    }
    printf("Caixa não encontrada.\n");
}

void removerCaixa(Pilha *pilhaA, Pilha *pilhaB, Pilha *pilhaC, int id) {
    int pos = buscarCaixa(pilhaA, id);
    if (pos != -1) {
        // Mover as caixas acima da caixa removida para pilha B
        while (pilhaA->topo > pos + 1) {
            moverCaixa(pilhaA, pilhaB);
        }
        // Remover a caixa desejada
        Caixa caixaRemovida = desempilhar(pilhaA);
        printf("\n");
        exibirCaixa(caixaRemovida);
        printf("\nCaixa removida com sucesso!\n\n");

        // Mover as caixas da pilha B de volta para a pilha A
        while (pilhaB->topo > 0) {
            moverCaixa(pilhaB, pilhaA);
        }
    } else {
        printf("Caixa não encontrada.\n");
    }
}

void editarCaixa(Pilha* pilhaA, Pilha* pilhaB, Pilha* pilhaC, int id) {
    int pos = buscarCaixa(pilhaA, id);
    if (pos != -1) {
        Caixa caixaEditada = pilhaA->caixas[pos];
        int novoPeso;
        char novaDescricao[100];

        // Solicitar novo peso
        do {
            printf("Digite o novo peso da caixa (3, 5 ou 7 toneladas): ");
            if (scanf("%d", &novoPeso) != 1 || (novoPeso != 3 && novoPeso != 5 && novoPeso != 7)) {
                printf("Peso inválido. Por favor, digite um peso válido.\n");
                while (getchar() != '\n');
            }
        } while (novoPeso != 3 && novoPeso != 5 && novoPeso != 7);

        // Solicitar nova descrição
        printf("Digite a nova descrição da caixa: ");
        scanf(" %[^\n]", novaDescricao);

        // Atualizar a caixa
        caixaEditada.peso = novoPeso;
        strcpy(caixaEditada.descricao, novaDescricao);

        // Remover a caixa antiga silenciosamente
        int pos = buscarCaixa(pilhaA, id);
        if (pos != -1) {
            while (pilhaA->topo > pos + 1) {
                moverCaixa(pilhaA, pilhaB);
            }
            desempilhar(pilhaA);
            while (pilhaB->topo > 0) {
                moverCaixa(pilhaB, pilhaA);
            }
        }

        // Reinserir a caixa editada
        inserirCaixa(pilhaA, pilhaB, pilhaC, caixaEditada);

        printf("\nCaixa editada com sucesso!\n\n");
    } else {
        printf("Caixa não encontrada.\n");
    }
}

int buscarCaixa(Pilha* pilha, int id) {
    for (int i = pilha->topo - 1; i >= 0; i--) {
        if (pilha->caixas[i].id == id) {
            return i;  // Retorna a posição se encontrar
        }
    }
    return -1;  // Retorna -1 se não encontrar
}

void exibirCaixa(Caixa caixa) {
    printf("ID: %d, Peso: %d, Descrição: %s\n", caixa.id, caixa.peso, caixa.descricao);
}

void moverCaixa(Pilha *origem, Pilha *destino) {
    Caixa caixa = desempilhar(origem);
    if (caixa.id != -1) {
        empilhar(destino, caixa);
    }
}