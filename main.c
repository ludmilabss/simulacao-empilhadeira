#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PILHA 100

typedef struct {
    int id;
    int peso;
    char descricao[100];
} Caixa;

typedef struct {
    Caixa caixas[MAX_PILHA];
    int topo;
} Pilha;

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

int main() {
    Pilha pilhaA, pilhaB, pilhaC;
    inicializarPilha(&pilhaA);
    inicializarPilha(&pilhaB);
    inicializarPilha(&pilhaC);

    // Exemplo de inserção de caixas
    Caixa caixa1 = {1, 3, "Caixa de 3 toneladas"};
    Caixa caixa2 = {2, 5, "Caixa de 5 toneladas"};
    Caixa caixa3 = {3, 7, "Caixa de 7 toneladas"};

    inserirCaixa(&pilhaA, &pilhaB, &pilhaC, caixa3);
    inserirCaixa(&pilhaA, &pilhaB, &pilhaC, caixa2);
    inserirCaixa(&pilhaA, &pilhaB, &pilhaC, caixa1);

    // Exemplo de consulta de caixa
    consultarCaixa(&pilhaA, 2);

    // Exemplo de remoção de caixa
    removerCaixa(&pilhaA, &pilhaB, &pilhaC, 2);

    return 0;
}
