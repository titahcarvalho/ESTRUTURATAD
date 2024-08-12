#include "Produto.h"
#include <string.h>  

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
    TCelula* Aux = Lista.primeiro->prox;
    while(Aux->prox != NULL) {
        if(strcmp(Aux->item.nome, Item.nome) == 0)//isso estava errado
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
    printf("\n----------------------------------" ); 
    printf("\nInserir Produto selecionado:\n" );      
    printf("\nDigite o codigo do produto:" );
    fflush(stdin);
    scanf("%d",&Item->codigo);
    getchar();
    printf("\nDigite a descricao do produto:");
    //fflush(stdin);
    fgets(Item->descricao,100,stdin);
    //getchar();
    printf("\nDigite o nome do produto:");
    //fflush(stdin);
    fgets(Item->nome,100,stdin);
    //getchar();
    printf("\nDigite a quantidade do produto em estoque:");
    fflush(stdin);
    scanf("%d",&Item->quantidade);
   // getchar();
    printf("\nDigite o valor do produto:");
    fflush(stdin);
    scanf("%f",&Item->preco);
   // getchar();
    
}
void ImprimirProduto(TProduto Item){
    printf("\nCodigo:%d",Item.codigo);
    printf("\nDescricao:%s",Item.descricao);
    printf("\nNome do produto:%s",Item.nome);
    printf("\nQuantidade em estoque:%d",Item.quantidade);
    printf("\nPreco: $%.2f",Item.preco);
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
void Atualizar(TLista *Lista, TProduto Item){
    TCelula *Aux1;
    Aux1 = PesquisarNome(*Lista, Item);
    if(Aux1 != NULL){
        printf("\nDigite os seguintes dados do produto a ser atualizado:");
        LerProduto (&Aux1->item);//(&Aux1->prox->item);
    } else {
        printf("Produto nao encontrado.");
    }
    
}
void OrdemCrescente(TProduto x, TLista *Lista){
    TCelula *celulaNova = (TCelula*)malloc(sizeof(TCelula));
    celulaNova->item = x;                 //criação da celula nova a ser inserida em ordem crescnte de nome
    celulaNova->prox = NULL;
    
    if(Lista->primeiro == NULL){ //caso questão A.
       /* Lista->primeiro = celulaNova;
        Lista->ultimo = celulaNova;         //NO CASO AQUI DEVE SER INSERIDO A FUNÇÃO INSERIR KKK
        Lista->tamanho++;
        return;*/
        Inserir(x, Lista);
        
    } else if(strcmp(x.nome, Lista->ultimo->item.nome)> 0 ){ //caso questão B 
    //if(strmp(S1,S2) == 0){
        //printf("São Iguais")
        Inserir(x, Lista);
        return;
    }
     
    TCelula *anterior = NULL;
    TCelula *atual = Lista->primeiro;
    
    while(atual != NULL && strcmp(x.nome, atual->item.nome) > 0){
        anterior = atual;
        atual = atual->prox;
        
        if(anterior == NULL){ //inserir no inicio
            celulaNova->prox = Lista->primeiro;
            Lista->primeiro = celulaNova;
        }else //inserir no meio
            celulaNova->prox = anterior->prox;
            anterior->prox = celulaNova;
    }
        if(celulaNova->prox == NULL){ //atualiza o último se necessário
             Lista->ultimo = celulaNova;
        
        }
        Lista->tamanho++;
    
}