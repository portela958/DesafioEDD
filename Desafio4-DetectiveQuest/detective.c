#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nó da árvore binária
typedef struct No {
    char valor[50];
    struct No *esq, *dir;
} No;

No* novoNo(char *valor) {
    No* n = (No*) malloc(sizeof(No));
    strcpy(n->valor, valor);
    n->esq = n->dir = NULL;
    return n;
}

// Inserção em árvore de busca
No* inserir(No* raiz, char *valor) {
    if(raiz == NULL) return novoNo(valor);
    if(strcmp(valor, raiz->valor) < 0)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

// Exibir em ordem (alfabética)
void emOrdem(No* raiz) {
    if(raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%s\n", raiz->valor);
        emOrdem(raiz->dir);
    }
}

// Hash simples para suspeitos
#define TAM 10
typedef struct {
    char pista[50];
    char suspeito[30];
} Entrada;

Entrada tabela[TAM];

int hash(char *pista) {
    int soma = 0;
    for(int i=0; pista[i]!='\0'; i++) soma += pista[i];
    return soma % TAM;
}

void inserirHash(char *pista, char *suspeito) {
    int h = hash(pista);
    strcpy(tabela[h].pista, pista);
    strcpy(tabela[h].suspeito, suspeito);
}

char* buscarHash(char *pista) {
    int h = hash(pista);
    if(strcmp(tabela[h].pista, pista) == 0)
        return tabela[h].suspeito;
    return "Desconhecido";
}

int main() {
    // Árvore de pistas
    No* pistas = NULL;
    pistas = inserir(pistas, "Pegadas");
    pistas = inserir(pistas, "Arma");
    pistas = inserir(pistas, "Testemunha");

    printf("Pistas encontradas em ordem:\n");
    emOrdem(pistas);

    // Hash de suspeitos
    inserirHash("Pegadas", "Sr. Mostarda");
    inserirHash("Arma", "Sra. White");
    inserirHash("Testemunha", "Coronel Mustarda");

    printf("\nSuspeito relacionado a 'Arma': %s\n", buscarHash("Arma"));
    return 0;
}