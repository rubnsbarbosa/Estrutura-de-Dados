#include <stdio.h>
#include <stdlib.h>

struct no
{
	int valor;
	struct no *esquerda;
	struct no *direita;
};

struct no *inicializa(void)
{
	/* Cria uma arvore vazia */
	return NULL;	
}

struct no *criaRaiz(struct no *subArvoreEsquerda, struct no *subArvoreDireita, int elemento)
{
	/* Retorna o no raiz da árvore que foi criado em árvore */
	struct no *noRaiz = malloc(sizeof(struct no));

	if(noRaiz == NULL)
	{
		exit(1);
	}
	noRaiz->valor = elemento;
	noRaiz->esquerda = subArvoreEsquerda;
	noRaiz->direita = subArvoreDireita;

	return noRaiz;
}

int vazia(struct no **arvore)
{
	/* Função verifica se a árvore está vazia */ 
	return *arvore == NULL;
}

void inserirNo(struct no **raiz, int elemento)
{
	if(*raiz == NULL)
	{
		struct no *aux = malloc(sizeof(struct no));
		aux->valor = elemento;
		aux->direita = NULL;
		aux->esquerda = NULL;
		*raiz = aux;
		printf("O elemento %d inserido\n", elemento);
		return;
	}

	if(elemento < (*raiz)->valor)
	{
		inserirNo(&(*raiz)->esquerda, elemento);
		return;
	}

	if(elemento > (*raiz)->valor)
	{
		inserirNo(&(*raiz)->direita, elemento);
		return;
	}
	printf("Elemento %d ja existe na arvore\n", elemento);
}

int consultaItem(struct no **raiz, int elemento)
{
	if(*raiz == NULL)
	{
		return 1;
	}
	else
	{
		if(elemento < (*raiz)->valor)
		{
			// Pesquisa na sub-árvore esquerda
			consultaItem(&(*raiz)->esquerda, elemento);
		}
		else if(elemento > (*raiz)->valor)
		{
			// Pesquisa na sub-árvore direita
			consultaItem(&(*raiz)->direita, elemento);
		}
		else
		{
			return 0;
		}
	}
}

void consultaEmOrdem(struct no **raiz)
{
	/* ERD - Caminha na sub-árvore esquerda, visita a Raiz e caminha na sub-árvore direita */
	if(*raiz == NULL)
		return;
	consultaEmOrdem(&(*raiz)->esquerda);
	printf("%d ", (*raiz)->valor);
	consultaEmOrdem(&(*raiz)->direita);
}

void consultaPreOrdem(struct no **raiz)
{
	/* RED - Visita a Raiz, caminha na sub-árvore esquerda e caminha na sub-árvore direita */
	if(*raiz == NULL)
		return;
	printf("%d ", (*raiz)->valor);
	consultaPreOrdem(&(*raiz)->esquerda);
	consultaPreOrdem(&(*raiz)->direita);
}

void consultaPosOrdem(struct no **raiz)
{
	/* EDR - Caminha na sub-árvore esquerda, caminha na sub-árvore direita e visita a Raiz */
	if(*raiz == NULL)
		return;
	consultaPosOrdem(&(*raiz)->esquerda);
	consultaPosOrdem(&(*raiz)->direita);
	printf("%d ", (*raiz)->valor);
}

void imprimeArvore(struct no **arvore)
{
	if(*arvore != NULL)
	{
		printf("%d ", (*arvore)->valor); /* imprime raiz */
		imprimeArvore(&(*arvore)->esquerda); /* imprime sub arvore esquerda */
		imprimeArvore(&(*arvore)->direita); /* imprime sub arvore direita */
	}
}

struct no *doisFilhos(struct no *raiz)
{
	if(raiz == NULL)
		return NULL;
	else if(raiz->esquerda == NULL)
		return raiz;
	else
		return doisFilhos(raiz->esquerda);
}

void removerNo(struct no ** raiz, int elemento)
{
	/* Obs: Vamos supor que a árvore já têm elementos, mas se quiser pode veririficar se (*raiz) != NULL
	se a raíz for diferente de NULL é porque existe elementos na nossa árvore
	Vou procurar o elemento que quero remover através desses ifs */
	if(elemento < (*raiz)->valor)
	{
		removerNo(&(*raiz)->esquerda, elemento);
	}
	else if(elemento > (*raiz)->valor)
	{
		removerNo(&(*raiz)->direita, elemento);
	}

	/* Aqui irá remover o nó raiz, pois, o valor da esquerda e da direita são diferentes de NULL
	logo irá entrar nessa condição. Criamos um aux para armazenar o elemento mais próximo do valor da raíz
	encontrado e passado pela função auxiliar: dois filhos que retorna o valor que será a próxima raíz da árvore
	em seguida chamamos recursivamente a função removerNo onde passamos o valor da direita que é o maior e mais próximo 
	valor da raíz, senão entra no else */
	else if((*raiz)->esquerda != NULL && (*raiz)->direita != NULL)
	{
		struct no *aux = NULL;
		aux = doisFilhos((*raiz)->direita);
		(*raiz)->valor = aux->valor;
		removerNo(&(*raiz)->direita, (*raiz)->valor);
	}

	/* Criamos um nó auxiliar que recebe o nó que iremos excluir. 
	Em seguida iremos verificar: o esquerdo do nó é igual a NULL?
	se for igual a NULL iremos subir o direito e desalocamos o auxiliar que é o nó */
	else
	{
		struct no *auxiliar = (*raiz);
		if((*raiz)->esquerda == NULL)
			(*raiz) = (*raiz)->direita;
		else
			(*raiz) = (*raiz)->esquerda;
		free(auxiliar);
	}
}

void esvaziar(struct no **arvore)
{
	/* Funcao que esvazia a árvore */
	esvaziar(&(*arvore)->esquerda);
	esvaziar(&(*arvore)->direita);
	free(*arvore);
}

int main()
{
	struct no *raiz = NULL;

	int opcao;
    do
    {
        printf("\nEntre com a opcao desejada\n 1 - Inicializa arvore");
        printf("\n 2 - Verifica se a arvore esta' vazia\n 3 - Inserir elemento na arvore");
		printf("\n 4 - Imprime arvore\n 5 - Consulta item\n 6 - Consulta o elemento EM ORDEM");
		printf("\n 7 - Consulta o elemento PRE-ORDEM\n 8 - Consulta o elemento POS-ORDEM");
		printf("\n 9 - Exclui elemento\n10 - Sair\n\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            {
                inicializa();
                break;
            }
        case 2:
            {
				int resp; 
				resp = vazia(&raiz);
				if(resp == 1)
					printf("TRUE");
				if(resp == 0)
					printf("FALSE");
                break;
            }
        case 3:
            {
				/*  int elemento;
                printf("Digite o elemento: ");
                scanf("%d", &elemento);
                fflush(stdin);

                inserirNo(&raiz, elemento);  */
				inserirNo(&raiz, 6);
				inserirNo(&raiz, 6);
				inserirNo(&raiz, 8);
				inserirNo(&raiz, 9);
				inserirNo(&raiz, 1);
				inserirNo(&raiz, 2);
                break;
            }
        case 4:
            {
              	imprimeArvore(&raiz);
                break;
            }
        case 5:
            {
				int aux, elemento;

				printf("Digite o elemento a ser consultado: ");
                scanf("%d", &elemento);
                fflush(stdin);

				aux = consultaItem(&raiz, elemento);
				
				if(aux == 0)
					printf("Elemento encontrado!\n");
				else
					printf("Elemento nao encontrado!\n");
                break;
            }
		case 6:
            {
				consultaEmOrdem(&raiz);
                break;
            }
		case 7:
            {
				consultaPreOrdem(&raiz);
                break;
            }
		case 8:
            {
				consultaPosOrdem(&raiz);
                break;
            }
		case 9:
            {	
				int elemento;

				printf("Digite o elemento a ser removido: ");
                scanf("%d", &elemento);
                fflush(stdin);

				removerNo(&raiz, elemento);
                break;
            }
		case 10:
            {
                break;
            }
        default:
            {
                printf("Opcao invalida!\n\n");
            }
        }

    } while(opcao != 10);

	return 0;
}
