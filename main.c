#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include "Produto.h"

int main(){
    int escolha = 0;
    TProduto x, y;
    TLista L1, L2;
    FLVazia(&L1);
    FLVazia(&L2);
    int tst;

    while(escolha != 8){
        printf("\n|| MENU ||\n");
        printf("|1| Inserir produtos.\n");
        printf("|2| Buscar um produto.\n");
        printf("|3| Imprimir produtos em estoque.\n");
        printf("|4| Excluir produto.\n");
        printf("|5| Atualizar produtos em estoque.\n");
        printf("|6| Ordem crescente de produtos.\n");
        printf("|7| Concatenar Listas.\n");
        printf("|8| Sair.\n");
        printf("Escolha uma das acoes:");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                    LerProduto(&x);
                    Inserir(x, &L1);
                    Inserir(x,&L2);//segunda lista
                    tst = CompararLista(L1,L2); //SEm o & pois não ha p ponteiro na função
                    printf("%i - se for 0 as listas estão com tamanhos diferentes, se for 1 as listas estão iguais em tamanho.",tst);
                break;

            case 2:
                printf("\nDigite o codigo para pesquisar um produto especifico:");
                scanf("%d", &y.codigo);
                TCelula* p = Pesquisar(L1, y);

                if (p != NULL) {
                    printf("\nProduto %d encontrado!", p->prox->item.codigo);
                    printf("\nNome: %s", p->prox->item.nome);
                    printf("\nDescricao: %s", p->prox->item.descricao);
                    printf("\nQuantidade: %d", p->prox->item.quantidade);
                    printf("\nValor: $%.2f", p->prox->item.preco);
                } else {
                    printf("Produto %d nao encontrado.", y.codigo);
                }
                break;

            case 3:
                printf("\n----------------------- Produtos em estoque Lista L1:-----------------------");
                Imprimir(L1);
                printf("\n----------------------------------------------------------------------------");
                printf("\nTotal de produtos no estoque: %i",L1.tamanho );
                printf("\n----------------------------------------------------------------------------");
                break;

            case 4:
                printf("\nDigite o codigo para excluir um produto especifico:");
                scanf("%d", &y.codigo);

                TProduto t;
                t.codigo = y.codigo;
                Excluir(&L1, &t);

                if(t.codigo != -1) {
                    printf("\nProduto excluido:");
                    ImprimirProduto(t);
                } else {
                    printf("\nNao foi possivel excluir o produto.");
                }
                break;
            case 5:
                printf("\nDigite o nome do produto que deseja atualizar:");
                fflush(stdin);
                fgets(y.nome, 100, stdin);
                //scanf("%s",y.nome);
                Atualizar(&L1, y);
                break;
            case 6:
                    printf("Digite o nome do produto a INSERIR na lista:");
                    fflush(stdin);
                    fgets(x.nome,100,stdin);
                    //Inserir(x,&L1); não é necessário aqui
                    OrdemCrescente(x,&L1); //verificar a implementação e a chamada da função OrdemCrescente, no caso a função Inserir não esta sendo chamada corretamente para adicionar uma célula na lista conforme a ordem.
                    break;
            case 7:
                printf("Unindo as listas...");
                ConcatenarListas(&L1,&L2, x);
                printf("Listas concatenadas:");
                Imprimir(L1);
                break;
            case 8:
                LiberarLista(&L1);
                printf("\nEncerrando...aperta no enter para fechar a Tela");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.");
                break;
        }
    }

    return 0;
}