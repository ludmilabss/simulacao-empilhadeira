#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarPilha(Pilha* pilha) {
    pilha->topo = 0;  // Inicializa a pilha vazia
}

int empilhar(Pilha *pilha, Caixa caixa) {
    if (pilha->topo < MAX_PILHA) {  // Corrigido para topo < MAX_PILHA
        pilha->caixas[pilha->topo] = caixa;
        pilha->topo++;
        return 1; // Sucesso
    } else {
        printf("Erro: Pilha cheia.\n");
        return 0; // Falha
    }
}

Caixa desempilhar(Pilha *pilha) {
    Caixa caixa;
    if (pilha->topo > 0) {  // Corrigido: topo > 0
        pilha->topo--;
        caixa = pilha->caixas[pilha->topo];
    } else {
        printf("Erro: Pilha vazia.\n");
        caixa.id = -1; // Indica que a pilha está vazia
    }
    return caixa;
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