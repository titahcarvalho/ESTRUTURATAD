#include "Produto.h"

void FLVazia(TLista *Lista) {//função para criar uma Lista //repare que aqui há a utilização do ponteiro devido a situação ser uma passagem por referencia onde há alterações
    Lista->primeiro = (TCelula*) malloc(sizeof(TCelula));
    Lista->ultimo = Lista->primeiro;
    Lista->primeiro -> prox = NULL;
    Lista->tamanho = 0;
}
    
int Vazia(TLista Lista){ //Função que ira verificar se a lista esta vazia, repare que esá sem ponteiro, pois é uma passagem por valor sem alterações permanentes.
    return (Lista.primeiro == Lista.ultimo); //se elas são iguais, apontam para o mesmo e está vazia, se não apontam p diferentes. 
}  

void Inserir(TProduto x, TLista *Lista){
    Lista->ultimo->prox = (TCelula*) malloc(sizeof(TCelula)); //criou aqui um quadradinhos da celula com os structs definidos para os itens dos produtos e o prox
    Lista->ultimo = Lista->ultimo->prox;
    Lista->ultimo->item = x;
    Lista->ultimo->prox = NULL;
    Lista->tamanho++;
}

void Imprimir(TLista Lista){
    TCelula* Aux = Lista.primeiro->prox;
    while(Aux != NULL){
        printf("------------------------------------\n");
        printf("Código:%d\n", Aux->item.codigo);
        printf("Descrição:%s\n", Aux->item.descricao);
        printf("Nome do produto:%s\n", Aux->item.nome);
        printf("Quantidade em estoque:%d\n", Aux->item.quantidade);
        printf("Preço: $%2.f\n", Aux->item.preco);
        Aux = Aux -> prox;
    }
}