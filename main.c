#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Inclua string.h para usar strcpy
#include "Produto.h"

int main(){
    int escolha;
    TProduto x,y;//y usado para pesquisar
    TLista L1;
    FLVazia(&L1);

    while(1){
        printf("\n***MENU***\n");
        printf("\nEscolha uma das ações:");
        printf("\n1 - Inserir um produto.");
        printf("\n2 - Buscar um produto.");
        printf("\n3 - Imprimir produtos em estoque.");
        printf("\n4 - Excluir produto.");
        printf("\n5 - Sair.\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
               
             LerProduto(&x);
             Inserir(x, &L1);

            break;

            case 2:
            
            printf("\n------------------------------------------------------\n");
            printf("Digite o código para pesquisar um produto específico:"); //adicionamos essa parte para implementar a função de pesquisa.
            scanf("%d", &y.codigo);
            TCelula* p; //aqui o ponteiro de TCelula é criado para P armazenar os itens de pesquisa
            p = Pesquisar(L1,y);   //Pesquisar(L1, y): Chama a função Pesquisar, passando a lista L1 e o item y (que contém o código do produto que queremos encontrar) como argumentos.
                                //p =: Armazena o resultado da função Pesquisar no ponteiro p. Se o item for encontrado, p apontará para a célula anterior à célula que contém o item. Se não for encontrado, p será NULL.
            if (p != NULL){
            printf("------------------------------------------------------\n");
            printf("Produto %d encontrado! =] \n", p->prox->item.codigo);
            printf("Nome do produto %d encontrado: %s \n", p->prox->item.codigo, p->prox->item.nome);
            printf("Descricao do produto %d encontrado: %s \n", p->prox->item.codigo, p->prox->item.descricao);
            printf("Quantidade do produto %d encontrado: %d \n", p->prox->item.codigo, p->prox->item.quantidade);
            printf("Valor do produto %d encontrado: $%2.f \n", p->prox->item.codigo, p->prox->item.preco);
         } else {
            printf("\n------------------------------------------------------\n");
            printf("Produto %d não encontrado. =[", y.codigo);
         }
            break;

            case 3:
            Imprimir(L1);
            printf("\n------------------------------------------------------\n");
            printf("Digite o código para pesquisar um produto específico:"); //adicionamos essa parte para implementar a função de pesquisa.
            scanf("%d", &y.codigo);
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
            break;

            case 4:
            
            printf("\n------------------------------------------------------\n");
            printf("Digite o código para excluir um produto específico:"); //adicionamos essa parte para implementar a função de pesquisa.
            scanf("%d", &y.codigo);
            
            TProduto t;
            t.codigo = 3;
            Excluir(&L1, &t);
           
            if(t.codigo != -1){
                ImprimirProduto(t);
                }else{
                    printf("Não foi possível excluir o produto.");
                }
            break;
            
            case5:
            LiberarLista(&L1);
            printf("Encerrando...");
            break;
            
            default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    }
       
    return 0;
}