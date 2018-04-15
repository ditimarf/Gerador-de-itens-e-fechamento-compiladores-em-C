#ifndef fila
#define fila

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fila{
	char num[10];
	struct Fila *prox;
};
typedef struct Fila node;

void inicia(node *LISTA);
node *criaNo();
void insereFim(node *LISTA, char cadeia[]);
void insereInicio(node *LISTA, char cadeia[]);
int qtdNodes(node *LISTA);
int exibe(node *LISTA);
int exibe1(node *LISTA);
void libera(node *LISTA);
int contido(node *LISTA, char item[]);
int posicao(node *LISTA, char item[]);
void unir(node *fim, node *nTerminais, node *Terminais);

void inicia(node *LISTA)
{
	LISTA->prox = NULL;
}

int vazia(node *LISTA)
{
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}

void insereFim(node *LISTA, char cadeia[])
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	strcpy(novo->num, cadeia);
	novo->prox = NULL;

	if(vazia(LISTA))
		LISTA->prox=novo;
	else{
		node *tmp = LISTA->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
}

void insereInicio(node *LISTA, char cadeia[])
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	strcpy(novo->num, cadeia);

	node *oldHead = LISTA->prox;

	LISTA->prox = novo;
	novo->prox = oldHead;
}

int qtdNodes(node *LISTA)
{
	int qtd = 0;

	if(vazia(LISTA))
        return 0;

	node *tmp;
	tmp = LISTA->prox;

	while( tmp != NULL){
		tmp = tmp->prox;
		qtd++;
	}

	return qtd;
}

int exibe(node *LISTA)
{
	int qtd = 0;

	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return qtd;
	}

	node *tmp;
	tmp = LISTA->prox;
    int i = 1;
	while( tmp != NULL){
		printf("%5s\n",tmp->num);
		tmp = tmp->prox;
		qtd++;
	}
	printf("\n\n");

	return qtd;
}

int exibe1(node *LISTA)
{
	int qtd = 0;

	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return qtd;
	}

	node *tmp;
	tmp = LISTA->prox;
    int i = 1;
	while( tmp != NULL){
		printf("%s\t ",tmp->num);
		tmp = tmp->prox;
		qtd++;
	}
	printf("\n\n");

	return qtd;
}


void libera(node *LISTA)
{
	if(!vazia(LISTA)){
		node *proxNode,
			  *atual;

		atual = LISTA->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}

int contido(node *LISTA, char item[]){
    node *temp = LISTA->prox;

    while(temp->num != NULL){
        if(!strcmp(temp->num, item))
            return 1;
        else
            temp = temp->prox;
    }
    return 0;
}

int posicao(node *LISTA, char item[]){
    int i = 0;
    node *temp = LISTA->prox;

    while(temp->num != NULL){
        if(!strcmp(temp->num, item))
            return i;
        else{
            i++;
            temp = temp->prox;

        }
    }
    return -1;
}

void unir(node *fim, node *nTerminais, node *Terminais){
    node *temp = nTerminais->prox;

    while(temp->num != NULL){
        insereFim(fim, temp->num);
        temp = temp->prox;
    }
    temp = Terminais->prox;
    while(temp->num != NULL){
        insereFim(fim, temp->num);
        temp = temp->prox;
    }
}


#endif
