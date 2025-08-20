#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura da lista pra strings
typedef struct lista {
    char* str;  // Ponteiro pra string
    struct lista* prox;
} Lista;

// Função pra criar uma lista vazia
Lista* novaLista() {
    return NULL;
}

// Função para inserir uma string no final da lista (copia a string)
Lista* final(Lista* l, const char* s) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL) {
        printf("Erro de alocação\n");
        exit(1);
    }
    novo->str = (char*) malloc(strlen(s) + 1);
    if (novo->str == NULL) {
        printf("Erro de alocação\n");
        exit(1);
    }
    strcpy(novo->str, s);
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

// Função pra verificar se duas listas são iguais
int igual(Lista* l1, Lista* l2) {
    Lista* p1 = l1;
    Lista* p2 = l2;
    
    while (p1 != NULL && p2 != NULL) {
        if (strcmp(p1->str, p2->str) != 0) {
            return 0;  // Strings diferentes
        }
        p1 = p1->prox;
        p2 = p2->prox;
    }
    
    // Se ambas acabaram ao mesmo tempo, são iguais
    if (p1 == NULL && p2 == NULL) {
        return 1;
    }
    return 0;  // Tamanhos diferentes
}

// Função pra imprimir a lista
void printLista(Lista* l) {
    Lista* p = l;
    while (p != NULL) {
        printf("%s -> ", p->str);
        p = p->prox;
    }
    printf("NULL\n");
}

// Função pra liberar a memória da lista
void freeLista(Lista* l) {
    Lista* p = l;
    while (p != NULL) {
        Lista* temp = p->prox;
        free(p->str);
        free(p);
        p = temp;
    }
}

int main() {
    Lista* l1 = novaLista();
    Lista* l2 = novaLista();
    char buffer[256];  // Buffer pra ler strings 
    int n;

    // Insere valores na lista 1
    printf("Quantos elementos deseja inserir na Lista 1? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Digite o elemento %d para l1: ", i + 1);
        scanf("%s", buffer);
        l1 = final(l1, buffer);
    }

    // Insere valores na lista 2
    printf("Quantos elementos deseja inserir na Lista 2? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Digite o elemento %d para l2: ", i + 1);
        scanf("%s", buffer);
        l2 = final(l2, buffer);
    }


    // Chama função igual e imprime o resultado
    int resultado = igual(l1, l2);
    if (resultado == 1) {
        printf("As listas sao iguais.\n");
    } else {
        printf("As listas sao diferentes.\n");
    }

    // Libera memória
    freeLista(l1);
    freeLista(l2);

    return 0;
}