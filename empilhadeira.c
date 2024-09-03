#include "empilhadeira.h"
#include <stdio.h>

void inserirCaixa(Pilha *pilhaA, Pilha *pilhaB, Pilha *pilhaC, Caixa caixa) {
    // Primeiro, vamos desempilhar as caixas até encontrar uma posição válida
    while (pilhaA->topo != -1 && pilhaA->caixas[pilhaA->topo].peso < caixa.peso) {
        moverCaixa(pilhaA, pilhaB);
    }
    empilhar(pilhaA, caixa);
    // Depois, colocamos de volta as caixas na pilha A
    while (pilhaB->topo != -1) {
        moverCaixa(pilhaB, pilhaA);
    }
}

void consultarCaixa(Pilha *pilha, int id) {
    int pos = buscarCaixa(pilha, id);
    if (pos != -1) {
        exibirCaixa(pilha->caixas[pos]);
    } else {
        printf("Caixa não encontrada.\n");
    }
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