#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define MAX 100 // Define o tamanho máximo da pilha

// Definição da estrutura da pilha (implementação opaca)
struct pilha {
    int topo;           // Índice do topo da pilha
    float dados[MAX];   // Vetor para armazenar os elementos da pilha
};

// Cria uma nova pilha e retorna seu ponteiro
Pilha* pilha_cria(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if(p == NULL){
        printf("ERRO: Memoria insuficiente\n");
        exit(1);
    }
    p->topo = 0; // Inicializa o topo como 0 (pilha vazia)
    return p;
}

// Empilha um valor no topo da pilha
void pilha_push(Pilha* p, float v) {
    if (p->topo == MAX) {
        printf("Erro: pilha cheia!\n");
        exit(1);  
    }
    p->dados[p->topo++] = v; // Adiciona o valor e incrementa o topo
}

// Remove e retorna o valor do topo da pilha
float pilha_pop(Pilha* p) {
    if (p->topo == 0) {
        printf("Erro: pilha vazia!\n");
        exit(1);
    }
    return p->dados[--p->topo]; // Decrementa o topo e retorna o valor removido
}

// Retorna 1 se a pilha está vazia, 0 caso contrário
int pilha_vazia(Pilha* p) {
    return (p->topo == 0);
}

// Libera a memória alocada para a pilha
void pilha_libera(Pilha* p) {
    free(p);
}

// Retorna o valor do topo da pilha sem remover (usando pop e push)
float topo(Pilha *p){
    if(pilha_vazia(p)){
        printf("Pilha vazia!\n");
        exit(1); // Encerra o programa em caso de erro
    }
    float valor = pilha_pop(p); // Remove o topo
    pilha_push(p, valor);       // Recoloca o valor no topo
    return valor;               // Retorna o valor do topo
}

// Concatena p2 no topo de p1, mantendo a ordem dos elementos de p2
void concatena_pilhas(Pilha* p1, Pilha* p2){
    Pilha* temp = pilha_cria();
    // Transfere todos os elementos de p2 para temp (inverte a ordem)
    while(!pilha_vazia(p2)){
        pilha_push(temp, pilha_pop(p2));
    }
    // Transfere de temp para p1 (restaura a ordem original de p2)
    while(!pilha_vazia(temp)){
        pilha_push(p1, pilha_pop(temp));
    }
    pilha_libera(temp);
}

// Imprime todos os elementos da pilha sem alterar seu conteúdo
void pilha_imprime(Pilha* p) {
    Pilha* aux = pilha_cria();
    // Desempilha todos os elementos, imprime e coloca em aux
    while (!pilha_vazia(p)) {
        float valor = pilha_pop(p);
        printf("%.2f\n", valor);
        pilha_push(aux, valor);
    }
    // Restaura os elementos para a pilha original
    while (!pilha_vazia(aux)) {
        pilha_push(p, pilha_pop(aux));
    }
    pilha_libera(aux);
}
