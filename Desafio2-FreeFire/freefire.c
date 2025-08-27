#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    int prioridade;
} Item;

void ordenar(Item *itens, int n) {
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if(strcmp(itens[j].nome, itens[min].nome) < 0)
                min = j;
        }
        Item temp = itens[i];
        itens[i] = itens[min];
        itens[min] = temp;
    }
}

int buscaBinaria(Item *itens, int n, char *nome) {
    int inicio = 0, fim = n-1;
    while(inicio <= fim) {
        int meio = (inicio+fim)/2;
        int cmp = strcmp(itens[meio].nome, nome);
        if(cmp == 0) return meio;
        else if(cmp < 0) inicio = meio+1;
        else fim = meio-1;
    }
    return -1;
}

int main() {
    int n;
    printf("Digite a quantidade de itens do inventario: ");
    scanf("%d", &n);

    Item *mochila = (Item*) malloc(n * sizeof(Item));
    for(int i = 0; i < n; i++) {
        printf("Nome do item: ");
        scanf("%s", mochila[i].nome);
        printf("Prioridade: ");
        scanf("%d", &mochila[i].prioridade);
    }

    ordenar(mochila, n);
    printf("\nInventario ordenado:\n");
    for(int i = 0; i < n; i++) {
        printf("%s (Prioridade %d)\n", mochila[i].nome, mochila[i].prioridade);
    }

    char busca[30];
    printf("\nDigite item para buscar: ");
    scanf("%s", busca);
    int pos = buscaBinaria(mochila, n, busca);
    if(pos >= 0)
        printf("Item %s encontrado na posicao %d.\n", mochila[pos].nome, pos);
    else
        printf("Item nao encontrado.\n");

    free(mochila);
    return 0;
}