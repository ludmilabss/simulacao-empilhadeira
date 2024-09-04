#ifndef PILHA_H
#define PILHA_H

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

void inicializarPilha();
int empilhar();
Caixa desempilhar();
int buscarCaixa();
void exibirCaixa();
void moverCaixa();

#endif 