#include "empilhadeira.h"
#include <stdio.h>

void inserirCaixa(Pilha* pilhaA, Pilha* pilhaB, Pilha* pilhaC, Caixa caixa) {
    if (caixa.peso == 3) {
        if (!empilhar(pilhaA, caixa)) {
            printf("Erro ao inserir caixa na pilha A.\n");
        }
    } else if (caixa.peso == 5) {
        if (!empilhar(pilhaB, caixa)) {
            printf("Erro ao inserir caixa na pilha B.\n");
        }
    } else if (caixa.peso == 7) {
        if (!empilhar(pilhaC, caixa)) {
            printf("Erro ao inserir caixa na pilha C.\n");
        }
    } else {
        printf("Peso inválido. As caixas devem pesar 3, 5 ou 7 toneladas.\n");
    }
}

void consultarCaixa(Pilha* pilhaA, Pilha* pilhaB, Pilha* pilhaC, int id) {
    int pos;

    // Verifica na pilha A
    pos = buscarCaixa(pilhaA, id);
    if (pos != -1) {
        printf("Caixa encontrada na pilha A.\n");
        exibirCaixa(pilhaA->caixas[pos]);
        return;
    }

    // Verifica na pilha B
    pos = buscarCaixa(pilhaB, id);
    if (pos != -1) {
        printf("Caixa encontrada na pilha B.\n");
        exibirCaixa(pilhaB->caixas[pos]);
        return;
    }

    // Verifica na pilha C
    pos = buscarCaixa(pilhaC, id);
    if (pos != -1) {
        printf("Caixa encontrada na pilha C.\n");
        exibirCaixa(pilhaC->caixas[pos]);
        return;
    }

    printf("Caixa não encontrada.\n");
}

void removerCaixa(Pilha *pilhaA, Pilha *pilhaB, Pilha *pilhaC, int id) {
    int pos = buscarCaixa(pilhaA, id);
    if (pos != -1) {
        // Mover as caixas para B e C, se necessário
        while (pilhaA->topo > pos) {
            moverCaixa(pilhaA, pilhaB);
        }
        // Remover a caixa desejada
        Caixa caixaRemovida = desempilhar(pilhaA);
        printf("Caixa removida: ");
        exibirCaixa(caixaRemovida);

        // Retornar as caixas para A
        while (pilhaB->topo > -1) {
            moverCaixa(pilhaB, pilhaA);
        }
    } else {
        printf("Caixa não encontrada.\n");
    }
}