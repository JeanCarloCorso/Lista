#include <stdio.h>
#include <stdlib.h>

struct lista
{
	char dado;
	struct lista *prox;
	struct lista *ant;
};

lista *guarda;

lista *aux = NULL;
lista *anterior = NULL;
lista *primeiro = NULL;
lista *ultimo = primeiro;

void inicializa()
{
	aux = (struct lista *)malloc(sizeof(struct lista));
	primeiro = aux;
	aux->prox = NULL;
	aux->ant = NULL;
	aux->dado = 0;
	guarda = primeiro;

	ultimo = aux;
	anterior = ultimo;
}

int main()
{
	
	int i = 0;
	int controla = i;
	int fim = 0;
	int ops;
	lista *posicaoAtual = NULL;
	while (fim == 0){
		printf("\n1--> Incluir elemento na lista");
		printf("\n2--> Remover elemento da lista");
		printf("\n3--> Ver a lista");
		printf("\n4--> Procimo");
		printf("\n5--> Anterior");
		printf("\n6--> Sair\n\n");
		scanf_s("%d", &ops);
		fflush(stdin);

		if (ops == 6){
			fim = 1;
		}
		else if ((ops == 1)){
			system("cls");
			if (i == 0){
				inicializa();
			}
			aux = (struct lista *)malloc(sizeof(struct lista));
			if ((i > 0) && (posicaoAtual != ultimo->ant)){
				printf("\nInserir na:\n\n");
				printf("1--> Posicao Atual\n");
				printf("2--> Final da Lista\n");
				scanf_s("%d", &ops);
				fflush(stdin);
			}
			else
			{
				ops = 2;
			}
			if (ops == 2){
				printf("\n\n\nInforme a letra a ser guardada na posição %d da da lista\n", i);
				scanf_s("%c", &aux[0].dado);
				fflush(stdin);
				

				aux->prox = primeiro;
				aux->ant = anterior;

				primeiro->ant = aux;
				ultimo->prox = aux;
			
				ultimo = aux;
				anterior = ultimo;
				i++;
				if (i == 1){
					guarda = guarda->prox;
				}
				system("cls");
			}

			else if (ops == 1){
				if (guarda != primeiro){
					printf("\n\n\nInforme a letra a ser guardada na posição %d da da lista\n", i);
					scanf_s("%c", &aux[0].dado);
					fflush(stdin);
					posicaoAtual = guarda;
					posicaoAtual = posicaoAtual->ant;
					aux->ant = posicaoAtual;
					aux->prox = posicaoAtual->prox;
					posicaoAtual->prox = aux;
					if (posicaoAtual != NULL){
						posicaoAtual->ant = aux;
					}
					controla++;
				}
				else {
					printf("\n\n\nInforme a letra a ser guardada na posição %d da da lista\n", i);
					scanf_s("%c", &aux[0].dado);
					fflush(stdin);
					posicaoAtual->ant = aux;
					ultimo->prox = aux;
					aux->prox = primeiro;
					aux->ant = ultimo;
					primeiro = aux;
					posicaoAtual = aux;
					controla++;
				}
				i++;
				system("cls");
			}
			else{
				system("cls");
				printf("\n\nComando Nao Reconhecido!!!\n\n");
			}
		}
		else if (ops == 3){
			if (i == 0){
				printf("\n\n\n\nA Lista esta vazia!!!\n\n\n\n");
			}
			else
			{
				system("cls");
				posicaoAtual = primeiro->prox;
				for (int b = 0; b < i; b++){
					printf("\nPosicao[%d]= %c", b, posicaoAtual->dado);
					if (posicaoAtual == guarda){
						printf(" *");
					}
					posicaoAtual = posicaoAtual->prox;
				}
				printf("\n\n\n");
			}
		}
		else if (ops == 4){
			controla++;
			system("cls");
			if (i == 0){
				printf("\n\n\n\nA Lista esta vazia!!!\n\n\n\n");
			}
			else
			{
				if (controla >= i){
					controla = 0;
				}
				posicaoAtual = guarda;
				if (posicaoAtual == primeiro){
					posicaoAtual = posicaoAtual->prox;
				}
				posicaoAtual = posicaoAtual->prox;
				printf("\nPosicao[%d]= %c", controla, posicaoAtual->dado);
				guarda = posicaoAtual;
			}
			printf("\n\n\n");
		}
		else if (ops == 5){
			controla--;
			system("cls");
			if (i == 0){
				printf("\n\n\n\nA Lista esta vazia!!!\n\n\n\n");
			}
			else
			{
				posicaoAtual = guarda;
				posicaoAtual = posicaoAtual->ant;
				if (posicaoAtual == primeiro){
					posicaoAtual = ultimo;
				}
				if (controla < 0){
					controla = i - 1;
				}
				printf("\nPosicao[%d]= %c", controla, posicaoAtual->dado);
				guarda = posicaoAtual;
			}
			printf("\n\n\n");
		}
		else if (ops == 2){
			system("cls");
			lista *anterior, *posterior, *nova;
			if (i == 0){
				printf("\n\n\nA lista esta vazia!!!\n\n\n");
			}
			else{
				posicaoAtual = guarda;
				if ((posicaoAtual == primeiro) && (i == 1)){
					aux = primeiro;
					primeiro = NULL;
					ultimo = NULL;
					free(aux);
				}
				else{
					aux = primeiro;
					while (aux->prox != posicaoAtual)
					{
						aux = aux->prox;
					}
					if (posicaoAtual != primeiro){
						aux = aux->prox;
						posicaoAtual = aux->prox;
						aux->ant->prox = aux->prox;
						aux->prox->ant = aux->ant;

					}
				}
				free(aux);
				guarda = posicaoAtual;
				printf("\n\nElemento removido!!!\n\n");
				i--;
			}
		}
		else
		{
			printf("\n\nComando nao reconhecido!!!\n\n");
		}
	}
}
