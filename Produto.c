#include "Produto.h"

void FLVazia(TLista *Lista) {//função para criar uma Lista //repare que aqui há a utilização do ponteiro devido a situação ser uma passagem por referencia onde há alterações
    Lista->primeiro = (TCelula*) malloc(sizeof(TCelula));
    Lista->ultimo = Lista->primeiro;
    Lista->primeiro->prox = NULL;
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

void LerProduto(TProduto *Item){
    printf("\n Digite o código do produto:");
    fflush(stdin);
    scanf("%d",&Item->codigo);
    printf("\n Digite a descrição do produto:");
    fflush(stdin);
    fgets(Item->descricao,100,stdin);
    printf("\n Digite o nome do produto:");
    fflush(stdin);
    fgets(Item->nome,50,stdin);
    printf("\n Digite a quantidade do produto:");
    fflush(stdin);
    scanf("%d",&Item->quantidade);
    printf("\n Digite o valor do produto:");
    fflush(stdin);
    scanf("%f",&Item->preco);

}
void ImprimirProduto(TProduto Item){
        printf("------------------------------------\n");
        printf("Código:%d\n",Item.codigo);
        printf("Descrição:%s\n",Item.descricao);
        printf("Nome do produto:%s\n",Item.nome);
        printf("Quantidade em estoque:%d\n",Item.quantidade);
        printf("Preço: $%.2f\n",Item.preco);
}

void Imprimir(TLista Lista){
    TCelula* Aux = Lista.primeiro->prox;
    while(Aux != NULL){
        ImprimirProduto(Aux->item); // Chama ImprimirProduto para cada item da lista
        Aux = Aux -> prox;
    }
}
 //operação para realizar uma busca/pesquisa
    TCelula* Pesquisar(TLista Lista, TProduto Item){
        TCelula* Aux = Lista.primeiro;
        while(Aux->prox != NULL){
            if(Aux->prox->item.codigo ==Item.codigo)
            return Aux;
            Aux = Aux->prox;
        }
        return NULL;
    }
void Excluir(TLista *Lista, TProduto *Item){
    TCelula *Aux1, *Aux2;
    Aux1 = Pesquisar(*Lista, *Item);
    if(Aux1 != NULL){
        Aux2 = Aux1 -> prox;
        Aux1->prox = Aux2-> prox;
        *Item = Aux2-> item;
        if(Aux1->prox == NULL){
            Lista-> ultimo = Aux1;
            free(Aux2);
            Lista-> tamanho--;
        }
    }
}    