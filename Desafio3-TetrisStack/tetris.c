#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    char tipo;
} Peca;

typedef struct {
    Peca itens[MAX];
    int inicio, fim, total;
} Fila;

typedef struct {
    Peca itens[MAX];
    int topo;
} Pilha;

void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

int filaVazia(Fila *f) { return f->total == 0; }
int filaCheia(Fila *f) { return f->total == MAX; }

void inserirFila(Fila *f, Peca p) {
    if(filaCheia(f)) return;
    f->itens[f->fim] = p;
    f->fim = (f->fim+1)%MAX;
    f->total++;
}

Peca removerFila(Fila *f) {
    Peca vazio = {'-'};
    if(filaVazia(f)) return vazio;
    Peca p = f->itens[f->inicio];
    f->inicio = (f->inicio+1)%MAX;
    f->total--;
    return p;
}

void inicializarPilha(Pilha *p) { p->topo = -1; }
int pilhaVazia(Pilha *p) { return p->topo == -1; }
int pilhaCheia(Pilha *p) { return p->topo == MAX-1; }

void push(Pilha *p, Peca x) {
    if(!pilhaCheia(p)) p->itens[++p->topo] = x;
}

Peca pop(Pilha *p) {
    Peca vazio = {'-'};
    if(pilhaVazia(p)) return vazio;
    return p->itens[p->topo--];
}

int main() {
    Fila fila;
    Pilha reserva;
    inicializarFila(&fila);
    inicializarPilha(&reserva);

    inserirFila(&fila, (Peca){'I'});
    inserirFila(&fila, (Peca){'O'});
    inserirFila(&fila, (Peca){'T'});

    printf("Peca vinda da fila: %c\n", removerFila(&fila).tipo);

    push(&reserva, (Peca){'L'});
    printf("Peca retirada da pilha de reserva: %c\n", pop(&reserva).tipo);

    return 0;
}