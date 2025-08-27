#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    char cor[15];
    int tropas;
} Territorio;

void cadastrarTerritorios(Territorio *mapa, int n) {
    for(int i = 0; i < n; i++) {
        printf("Digite o nome do territorio %d: ", i+1);
        scanf("%s", mapa[i].nome);
        printf("Digite a cor: ");
        scanf("%s", mapa[i].cor);
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

void atacar(Territorio *atacante, Territorio *defensor) {
    if(atacante->tropas > defensor->tropas) {
        printf("%s conquistou %s!\n", atacante->nome, defensor->nome);
        atacante->tropas -= defensor->tropas;
        defensor->tropas = 0;
    } else {
        printf("%s resistiu ao ataque!\n", defensor->nome);
        defensor->tropas -= atacante->tropas;
        atacante->tropas = 0;
    }
}

int main() {
    int n;
    printf("Digite o numero de territorios: ");
    scanf("%d", &n);

    Territorio *mapa = (Territorio*) malloc(n * sizeof(Territorio));
    cadastrarTerritorios(mapa, n);

    // Exemplo de ataque
    atacar(&mapa[0], &mapa[1]);

    free(mapa);
    return 0;
}