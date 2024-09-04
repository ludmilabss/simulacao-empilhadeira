#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

int empilhar(Pilha *pilha, Caixa caixa) {
    if (pilha->topo < MAX_PILHA - 1) {
        if (pilha->topo == -1 || pilha->caixas[pilha->topo].peso >= caixa.peso) {
            pilha->topo++;
            pilha->caixas[pilha->topo] = caixa;
            return 1; // Sucesso
        } else {
            printf("Erro: Não é possível empilhar uma caixa de menor peso sobre uma de maior peso.\n");
            return 0; // Falha
        }
    } else {
        printf("Erro: Pilha cheia.\n");
        return 0; // Falha
    }
}

Caixa desempilhar(Pilha *pilha) {
    Caixa caixa;
    if (pilha->topo > -1) {
        caixa = pilha->caixas[pilha->topo];
        pilha->topo--;
    } else {
        printf("Erro: Pilha vazia.\n");
        caixa.id = -1; // Indica que a pilha está vazia
    }
    return caixa;
}

int buscarCaixa(Pilha *pilha, int id) {
    for (int i = 0; i <= pilha->topo; i++) {
        if (pilha->caixas[i].id == id) {
            return i;
        }
    }
    return -1; // Não encontrado
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