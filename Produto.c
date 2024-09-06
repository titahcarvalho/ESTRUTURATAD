#include "Produto.h"
#include <string.h>
#include <stdbool.h>

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
    while(Aux != NULL) {//retirar prox
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
    printf("\nOpcao 'Inserir Produto' selecionado.\n" );
    printf("\nDigite o codigo do produto:" );
    scanf("%d",&Item->codigo);
    getchar();
    printf("\nDigite a descricao do produto:");
    fgets(Item->descricao,100,stdin);
    printf("\nDigite o nome do produto:");
    fgets(Item->nome,100,stdin);
    printf("\nDigite a quantidade do produto em estoque:");
    scanf("%d",&Item->quantidade);
    getchar();
    printf("\nDigite o valor do produto:");
    scanf("%f",&Item->preco);
    getchar();

}
void ImprimirProduto(TProduto Item){
    printf("\nNome do produto:%s",Item.nome);
    printf("Codigo:%d",Item.codigo);
    printf("\nDescricao:%s",Item.descricao);
    printf("Quantidade em estoque:%d",Item.quantidade);
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
//QUESTÃO 1-----------------------------------------------------------------
void Atualizar(TLista *Lista, TProduto Item){
    TCelula *Aux1;
    Aux1 = PesquisarNome(*Lista, Item);
    if(Aux1 != NULL){
        printf("Produto encontrado %s", Aux1->item.nome);
        printf("\nDigite os seguintes dados do produto a ser atualizado:");
        LerProduto (&Aux1->item);//(&Aux1->prox->item);
    } else {
        printf("Produto nao encontrado.");
    }

}
//QUESTÃO 2----------------------------------------------------------------
void OrdemCrescente(TProduto x, TLista *Lista){
    TCelula *celulaNova = (TCelula*)malloc(sizeof(TCelula));
    celulaNova->item = x;                 //criação da celula nova a ser inserida em ordem crescnte de nome
    celulaNova->prox = NULL;             //parte do enxerto

    if(Vazia(*Lista) || strcmp(Lista->ultimo->item.nome, x.nome) < 0 ){ //caso questão A e caso B - inserimos a função de conferir se está vazia e a comparação
        Inserir(x, Lista);
        return;
    }
    TCelula *Aux;
    Aux = Lista->primeiro;
    while( Aux != NULL) {
        if(strcmp(Aux->prox->item.nome, x.nome) > 0) {
            celulaNova = Aux->prox;
            Aux->prox = celulaNova;
           // Inserir(x,Lista); verificar se aqui deve usar essa chamada de função
            return;
        }
        Aux = Aux->prox;
    }
}
//QUESTÃO 3 ----------------------------------------------------------------
int CompararLista(TLista x, TLista y) {
    int flag;
    flag = 1;
    TCelula *Aux1, *Aux2;
    Aux1 = x.primeiro->prox; //x no caso não é ponteiro
    Aux2 = y.primeiro->prox;//y no caso não é ponteiro
    if((x.tamanho - y.tamanho)!= 0){
        return 0;
    }
    while(Aux1 != NULL){
        if(strcmp(Aux1->item.nome, Aux2->item.nome) == 0) {
            Aux1 = Aux1->prox;
            Aux2 = Aux2->prox;
        } else {
            Aux1 = Aux1->prox;
            Aux2 = Aux2->prox;
            flag = 0;
        }
    }
     return flag;
}
//QUESTÃO 4----------------------------------------------------------------
void InverterLista(TLista *Lista) {
    TCelula *Aux1, *Aux2, *Aux3;
    Aux1 = Lista->primeiro;
    Aux2 = NULL;
    Aux3 = NULL;

    Lista->ultimo = Aux1;
    while(Aux1 != NULL) {
        Aux2 = Aux1->prox;
        Aux1->prox = Aux3;
        Aux3 = Aux1;
        Aux1 = Aux2;
    }
    Lista->primeiro = Aux3;
    Lista->ultimo->prox = NULL;
}
void ConcatenarListas(TLista *L1, TLista *L2, TProduto x) {
    while(Vazia(*L2) != true) { // enquanto a lista 2 não estiver vazia, //função liberarlista e a chamada de Excluir
        x = L2->primeiro->prox->item;
        Excluir(L2, &x);
        Inserir(x,L1); //OrdemCrescente(x, L1);
    }
}
//QUESTÃO 5----------------------------------------------------------------
void ImprimirIEsima(TLista *Lista, int n){
    TCelula *Aux1;
    Aux1 = Lista->primeiro;
    int contador = 1;

    while(!Vazia(*Lista)) {
        while(Aux1 != NULL && contador < n) {
            Aux1 = Aux1->prox;
            contador++;
            if(Aux1 != NULL && contador == n) {
                Imprimir(Aux1->Item.nome); // algo assim ->tá errado
            } else {
                printf("Dados incompativeis.");
            }
        }
//QUESTÃO 6----------------------------------------------------------------

void BuscarDados(TLista Lista, TProduto Item) {
    //Verificação de Validade de i: Precisamos garantir que i é válido, ou seja, i deve ser maior ou igual a 1 e menor ou igual ao tamanho da lista.
    int contador = 1;
    TCelula* Aux;
    Aux = Lista.primeiro->prox;
    while(Aux != NULL) {
        if(contador == Lista.tamanho){
            printf("Dados da %d célula:", Aux->item);
            ImprimirProduto(Aux->prox);
            Aux = Aux->prox;
            contador++;
        }else {
            printf("Dados não encontrados.");
        }
    }
        return;

//QUESTÃO 7----------------------------------------------------------------
void ImprimirRecursiva(TLista *Lista) {
    if(Lista != NULL) {
        ImprimirProduto(Lista->primeiro->prox->item);
        printf("\nInfo: %s", Lista->primeiro->prox->item.nome);
        ImprimirRecursiva(Lista->primeiro->prox);
       // Lista->primeiro->prox = NULL;

    }
}







