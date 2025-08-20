#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void) {
    // Cria três pilhas: uma principal e duas auxiliares
    Pilha* p = pilha_cria();
    Pilha* p1 = pilha_cria();
    Pilha* p2 = pilha_cria();

    // Lê 3 valores do usuário e empilha na pilha principal
    printf("Digite 3 valores para a pilha: \n");
    for(int i = 0; i < 3; i++){
        float valor;
        scanf("%f", &valor);
        pilha_push(p, valor);
    }

    // Mostra o valor do topo, desempilha e mostra o novo topo
    printf("Topo atual = %.2f\n", topo(p));  // Exibe o valor do topo da pilha
    printf("Desempilhando: %.2f\n", pilha_pop(p)); // Remove e exibe o topo
    printf("Novo topo = %.2f\n", topo(p));   // Exibe o novo topo após desempilhar
    printf("\n");

    // Lê 4 valores para a pilha p1
    printf("Pilha 01: \nDigite 4 valores: \n");
    for(int i = 0; i < 4; i++){
        float valor;
        scanf("%f", &valor);
        pilha_push(p1, valor);
    }

    // Lê 4 valores para a pilha p2
    printf("Pilha 02: \nDigite 4 valores: \n");
    for(int i = 0; i < 4; i++){
        float valor;
        scanf("%f", &valor);
        pilha_push(p2, valor);
    }

    // Concatena p2 no topo de p1
    concatena_pilhas(p1, p2);

    // Imprime o conteúdo da pilha p1 após a concatenação
    printf("Pilha 01 apos concatenacao: \n");
    pilha_imprime(p1);

    // Libera a memória alocada para as pilhas
    pilha_libera(p);
    pilha_libera(p1);
    pilha_libera(p2);
    return 0;
}

