#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include "Produto.h"

int main(){
    int escolha = 0;
    TProduto x, y;
    TLista L1;
    FLVazia(&L1);

    while(escolha != 6){
        printf("\n|| MENU ||\n");
        printf("Escolha uma das acoes:\n");
        printf("|1| Inserir produtos.\n");
        printf("|2| Buscar um produto.\n");
        printf("|3| Imprimir produtos em estoque.\n");
        printf("|4| Excluir produto.\n");
        printf("|5| Atualizar produtos em estoque.\n");
        printf("|6| Sair.\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                
                    LerProduto(&x);
                    Inserir(x, &L1);
                
                break;

            case 2:
                printf("\n------------------------------------------------------\n");
                printf("|Digite o código para pesquisar um produto específico:|"); 
                scanf("%d", &y.codigo);
                TCelula* p = Pesquisar(L1, y);

                if (p != NULL) {
                    printf("------------------------------------------------------\n");
                    printf("|Produto %d encontrado!|\n", p->prox->item.codigo);
                    printf("|Nome: %s\n|", p->prox->item.nome);
                    printf("|Descrição: %s\n|", p->prox->item.descricao);
                    printf("|Quantidade: %d\n|", p->prox->item.quantidade);
                    printf("|Valor: $%.2f\n|", p->prox->item.preco);
                } else {
                    printf("\n------------------------------------------------------\n");
                    printf("|Produto %d não encontrado.|", y.codigo);
                }
                break;

            case 3:
                Imprimir(L1);
                break;

            case 4:
                printf("\n------------------------------------------------------\n");
                printf("|Digite o código para excluir um produto específico:|"); 
                scanf("%d", &y.codigo);
                
                TProduto t;
                t.codigo = y.codigo;
                Excluir(&L1, &t);
            
                if(t.codigo != -1) {
                    printf("|Produto excluído:|");
                    ImprimirProduto(t);
                } else {
                    printf("|Não foi possível excluir o produto.|");
                }
                break;
            case 5:
            
                 break;
            case 6:
                LiberarLista(&L1);
                printf("|Encerrando...|");
                break;

            default:
                printf("|Opção inválida. Tente novamente.|");
                break;
        }
    }

    return 0;
}
