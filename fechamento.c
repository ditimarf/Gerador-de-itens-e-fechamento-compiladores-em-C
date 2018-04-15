#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fechamento.h"
#include "fila.h"

int main(){

    int i, linha = 0, qtdItens;
    char gramatica[10][10], itens[100][10];

    node **fechamento = (node **) malloc(sizeof(node*) * 20);
    for(i = 0; i < 20; i++){
        fechamento[i] = (node *) malloc(sizeof(node));
        inicia(fechamento[i]);
    }
    //Gramatica passada a "mão"
    strcpy(gramatica[linha++], "S->E");
    strcpy(gramatica[linha++], "E->E+T");
    strcpy(gramatica[linha++], "E->T");
    strcpy(gramatica[linha++], "T->T*F");
    strcpy(gramatica[linha++], "T->F");
    strcpy(gramatica[linha++], "F->(E)");
    strcpy(gramatica[linha++], "F->N");

    qtdItens = geraItens(gramatica, itens, linha);
    geraFechamento(itens, fechamento, qtdItens);

    //Imprime o fechamento
    for(i = 0; 0 && !vazia(fechamento[i]); i++){
        printf("I%d\n",i);
        exibe(fechamento[i]);
        printf("\n\n");
    }

    //Imprime os Itens
    for(i = 0; 0 && i < qtdItens; i++)
        printf("%s\n", itens[i]);

    return 0;
}
