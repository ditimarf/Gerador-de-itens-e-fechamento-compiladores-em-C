#ifndef fech
#define fech

#include "fila.h"

int geraItens(char regra[][10], char item[][10], int qtdLinhas){
    int i, j, k, l=0, tam;
    char novoItem[12];

    for(k = 0; k < qtdLinhas; k++){
        tam = strlen(regra[k]) + 1;

        for(i = 0; i < tam - 3; i++){
            //Copiar o nao terminal
            for(j=0; j < 3; j++)
                novoItem[j] = regra[k][j];

            //copiar o que ja foi lido
            for(j; j < i + 3; j++)
                novoItem[j] = regra[k][j];

            novoItem[j] = '.';

            //copiar o que vai ser lido
            for(j; j < tam; j++)
                novoItem[j+1] = regra[k][j];

            novoItem[j] = '\0';

            strcpy(item[l++], novoItem);
        }
    }

    strcpy(item[l], "$");
    return l;
}

int pertence(char item[], node **fechamento){
    int i;

    for(i = 0; fechamento[i]->num; i++)
        if(contido(fechamento[i], item))
            return 1;

    return 0;
}

void padrao(char primario[], char item[][10], node *fechamento, int qtdItens, int i){
    char itemGerador[3];
    char itemGerado[8];
    char primarioGerado[8];

    for(; i < qtdItens; i++){
        //Se o Primario == Item, ele passa pro proximo item
        if(!strcmp(primario, item[i]))
            continue;

        //Copia para primarioGerado a partir do "."
        strcpy(primarioGerado, strstr(primario, "."));
        primarioGerado[2] = '\0';

        //Se o ponto seja do lado direito do nao terminal, ele copia o NT e o "."
        if(!('A' <= primarioGerado[1] && primarioGerado[1] <'N'|| 'N' < primarioGerado[1] && primarioGerado[1] <='Z')){
            strcpy(primarioGerado, strstr(primario, ".") - 1);
            primarioGerado[2] = '\0';
        }

        //Copia para itemGerador o primeiro char do item
        strcpy(itemGerador, item[i]);
        itemGerador[1] = '\0';

        //copia para itemGerado tudo que é gerado
        strcpy(itemGerado, item[i] + 3);

        //Adiciona ao fechamento In se S->E && E->E&
        if(1 && strstr(itemGerado, primarioGerado) - itemGerado == 0)
            if(primarioGerado[1] == itemGerador[0] || primarioGerado[0] == itemGerador[0])
                insereFim(fechamento, item[i]);

        //Adiciona ao fechamento In se S->E && E->T && ja nao esta no fechamento, depois, procura os que sao verdade a busca de padrao de E->T
        if(1 && primarioGerado[0] == '.' && !strcmp(primarioGerado + 1, itemGerador) && itemGerado[0] == '.' && !contido(fechamento, item[i])){
            insereFim(fechamento, item[i]);
            padrao(item[i], item, fechamento, qtdItens, i + 1);
        }
    }
}

void geraFechamento(char itens[][10], node **fechamento, int qtdItens){
    int i, j, nGrupo = 0;

    //verifica todos os itens, caso ele nao tenha sido usado ainda, um novo grupoFechamento é criado
    for(i = 0; i < qtdItens; i++)
        if(!pertence(itens[i], fechamento)){
            insereInicio(fechamento[nGrupo], itens[i]);

            padrao(itens[i], itens, fechamento[nGrupo], qtdItens, 0);

            nGrupo++;
        }
}

#endif // fech
