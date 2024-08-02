#ifndef PRODUTO_H
#define PRODUTO_H

#include <stdio.h>
#include <stdlib.h>


typedef struct produto{ //cria os quadradinhos
    int codigo;
    char descricao[100];
    char nome[100];
    int quantidade;
    float preco;
}TProduto;

typedef struct celula{
    TProduto item;      //utilizou o Tproduto antes declarado como variável para para declarar o item do tipo produto.
    struct celula* prox;        // a célula cria um ponteiro chamado "prox"
}TCelula;

typedef struct{  //realizar a lista com os parametros a serem seguidos.
    TCelula* primeiro;
    TCelula* ultimo;
    int tamanho;
}TLista;

//a partir daqui apenas o título, o corpo vai p o .C
void FLVazia(TLista *Lista); //função para criar uma Lista //repare que aqui há a utilização do ponteiro devido a situação ser uma passagem por referencia onde há alterações
int Vazia(TLista Lista); //Função que ira verificar se a lista esta vazia, repare que esá sem ponteiro, pois é uma passagem por valor sem alterações permanentes.  //se elas são iguais, apontam para o mesmo e está vazia, se não apontam p diferentes. 
void Inserir(TProduto x, TLista *Lista);
TCelula* Pesquisar(TLista Lista, TProduto Item);
void Excluir(TLista *Lista, TProduto *Item);// onde o item será excluido?, de onde, o que, qual?
void LerProduto(TProduto *Item);
void ImprimirProduto(TProduto Item);
void Imprimir(TLista Lista);
void LiberarLista(TLista *Lista);  

#endif
    
