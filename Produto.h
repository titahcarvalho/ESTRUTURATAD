#ifndef PRODUTO_H
#define PRODUTO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct produto {
    int codigo;
    char descricao[100];
    char nome[100];
    int quantidade;
    float preco;
} TProduto;

typedef struct celula {
    TProduto item;
    struct celula* prox;
} TCelula;

typedef struct {
    TCelula* primeiro;
    TCelula* ultimo;
    int tamanho;
} TLista;

void FLVazia(TLista *Lista);
int Vazia(TLista Lista);
void Inserir(TProduto x, TLista *Lista);
TCelula* Pesquisar(TLista Lista, TProduto Item);
void Excluir(TLista *Lista, TProduto *Item);
void LerProduto(TProduto *Item);
void ImprimirProduto(TProduto Item);
void Imprimir(TLista Lista);
void LiberarLista(TLista *Lista); //void LiberarLista2(TLista *Lista);
void AtualizarLista(TLista *Lista, TProduto Item);
#endif
