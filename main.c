#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Inclua string.h para usar strcpy
#include "Produto.h"

int main(){
    TProduto x;
    TLista L1;
    FLVazia(&L1);
    
   
    x.codigo = 7;
    strcpy(x.descricao, "Geladeira 800L"); //aqui foi usada a virgula
    strcpy(x.nome, "Geladeira Friii");
    x.quantidade = 4;
    x.preco = 234;
    Inserir(x, &L1);
    
    
    x.codigo = 13;
    strcpy(x.descricao, "Geladeira 900L");
    strcpy(x.nome, "Geladeira Fria");
    x.quantidade = 5;
    x.preco = 504;
    Inserir(x, &L1);
    
 
    x.codigo = 9;
    strcpy(x.descricao,"Geladeira 1000L");
    strcpy(x.nome,"Geladeira Esfriou");
    x.quantidade = 14;
    x.preco = 2304;
    Inserir(x, &L1);
    
    Imprimir(L1);
    
    return 0;
}