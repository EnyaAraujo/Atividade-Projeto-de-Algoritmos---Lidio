#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da lista para valores reais
typedef struct lista {
    float valor;
    struct lista* prox;
} Lista;

// Função para criar uma lista vazia
Lista* criaL() {
    return NULL;
}

// Função para inserir um valor no final da lista
Lista* final(Lista* l, float v) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL) {
        printf("Erro de alocação\n");
        exit(1);
    }
    novo->valor = v;
    novo->prox = NULL;
    
    if (l == NULL) {
        return novo;
    }
    
    Lista* p = l;
    while (p->prox != NULL) {
        p = p->prox;
    }
    p->prox = novo;
    return l;
}

// Função para concatenar duas listas
Lista* concatena(Lista* l1, Lista* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    
    Lista* p = l1;
    while (p->prox != NULL) {
        p = p->prox;
    }
    p->prox = l2;
    return l1;
}

// Função para imprimir a lista
void printLista(Lista* l) {
    Lista* p = l;
    while (p != NULL) {
        printf("%.1f -> ", p->valor);
        p = p->prox;
    }
    printf("NULL\n");
}

// Função pra liberar a memória da lista
void soltaLista(Lista* l) {
    Lista* p = l;
    while (p != NULL) {
        Lista* temp = p->prox;
        free(p);
        p = temp;
    }
}

int main() {
    int numL;
    printf("Quantas listas deseja criar?\n");
    scanf("%d", &numL);
    
    if (numL <= 0) {
        printf("O número de listas deve ser maior que zero.\n");
        return 1;
    }
    
    Lista** listas = (Lista**) malloc(numL * sizeof(Lista*));
    if (listas == NULL) {
        printf("Erro de alocação\n");
        return 1;
    }
    
    // Cria e preenche cada lista
    for (int i = 0; i < numL; i++) {
        listas[i] = criaL();
        int tamanho;
        printf("\nDigite o tamanho da lista %d:\n", i + 1);
        scanf("%d", &tamanho);
        
        float valor;
        for (int j = 0; j < tamanho; j++) {
            printf("\nDigite o valor %d da lista %d: ", j + 1, i + 1);
            scanf("%f", &valor);
            listas[i] = final(listas[i], valor);
        }
        
        // Imprime a lista atual
        printf("\nLista %d: ", i + 1);
        printLista(listas[i]);
    }
    
    // Concatena as listas
    Lista* resultado = listas[0];
    for (int i = 1; i < numL; i++) {
        resultado = concatena(resultado, listas[i]);
    }
    
    // Imprime o resultado
    printf("\nLista resultante apos concatenacao de todas:\n");
    printLista(resultado);
    
    // Libera memória
    soltaLista(resultado);
    free(listas);
    
    return 0;
}