#include "Produto.h"

void FLVazia(TLista *Lista) {
    Lista->primeiro = (TCelula*) malloc(sizeof(TCelula));
    Lista->ultimo = Lista->primeiro;
    Lista->primeiro->prox = NULL;
    Lista->tamanho = 0;
}

int Vazia(TLista Lista) { 
    return (Lista.primeiro == Lista.ultimo); 
}

void Inserir(TProduto x, TLista *Lista) {
    Lista->ultimo->prox = (TCelula*) malloc(sizeof(TCelula)); 
    Lista->ultimo = Lista->ultimo->prox;
    Lista->ultimo->item = x;
    Lista->ultimo->prox = NULL;
    Lista->tamanho++;
}

TCelula* Pesquisar(TLista Lista, TProduto Item) {
    TCelula* Aux = Lista.primeiro;
    while(Aux->prox != NULL) {
        if(Aux->prox->item.codigo == Item.codigo)
            return Aux;
        Aux = Aux->prox;
    }
    return NULL;
}
TCelula* PesquisarNome(TLista Lista, TProduto Item) {
    TCelula* Aux = Lista.primeiro;
    while(Aux->prox != NULL) {
        if(Aux->prox->item.nome == Item.nome)
            return Aux;
        Aux = Aux->prox;
    }
    return NULL;
}

void Excluir(TLista *Lista, TProduto *Item) {
    TCelula *Aux1, *Aux2;
    Aux1 = Pesquisar(*Lista, *Item);
    if(Aux1 != NULL) {
        Aux2 = Aux1->prox;
        Aux1->prox = Aux2->prox;
        *Item = Aux2->item;
        if(Aux1->prox == NULL) {
            Lista->ultimo = Aux1;
        }
        free(Aux2);
        Lista->tamanho--;
    } else {
        Item->codigo = -1; // Indicador de falha na exclusão
    }
} 

void LerProduto(TProduto *Item){
    int numeroDeProdutos = 0;
    printf("\nDigite a quantidade de produtos a serem inseridos: ");
    scanf("%d", &numeroDeProdutos);
    
    for( int f = 0; f<numeroDeProdutos; f++){
    printf("Digite o código do produto %d:", f+1);
    fflush(stdin);
    scanf("%d",&Item->codigo);
    getchar();
    printf("Digite a descrição do produto %d:",f+1);
    fflush(stdin);
    fgets(Item->descricao,100,stdin);
    getchar();
    printf("Digite o nome do produto %d:",f+1);
    fflush(stdin);
    fgets(Item->nome,50,stdin);
    getchar();
    printf("Digite a quantidade do produto %d em estoque:", f+1);
    fflush(stdin);
    scanf("%d",&Item->quantidade);
    getchar();
    printf("Digite o valor do produto %d:", f+1);
    fflush(stdin);
    scanf("%f",&Item->preco);
    getchar();
    }
}
void ImprimirProduto(TProduto Item){
    printf("------------------------------------");
    printf("\nCódigo:%d",Item.codigo);
    printf("\nDescrição:%s",Item.descricao);
    printf("\nNome do produto:%s",Item.nome);
    printf("\nQuantidade em estoque:%d",Item.quantidade);
    printf("\nPreço: $%.2f",Item.preco);
}


void Imprimir(TLista Lista) {
    TCelula* Aux = Lista.primeiro->prox;
    while(Aux != NULL) {
        ImprimirProduto(Aux->item); 
        Aux = Aux->prox;
    }
}

void LiberarLista(TLista *Lista) {
    TCelula *Aux1, *Aux2;
    Aux1 = Lista->primeiro;
   
    while(Aux1 != NULL) {
        Aux2 = Aux1->prox;
        free(Aux1);
        Aux1 = Aux2;
    }

    Lista->primeiro = Lista->ultimo = NULL;
    Lista->tamanho = 0;
}

void LiberarLista2(TLista *Lista){
    while( !Vazia(*Lista)){
        Excluir(Lista, &Lista->primeiro->prox->item);
    }
    free (Lista->primeiro);
    Lista->primeiro = NULL;
    
}
void AtualizarLista(TLista *Lista, TProduto Item){
    TCelula *Aux1;
    Aux1 = PesquisarNome(*Lista, Item);
    if(Aux1 != NULL){
        LerProduto(&Item);
    }
    
}