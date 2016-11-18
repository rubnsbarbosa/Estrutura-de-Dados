#include <stdio.h>
#include <stdlib.h>

void ordemCrescente(int vetor[], int n);
void exibeVetor(int vetor[], int n);
int pesquisaBinaria(int numeroBusca, int* vetor, int tamanho);

int main()
{
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    fflush(stdin);

    int vetor[tamanho], valor = 0;
    int i;
    for(i = 0; i < tamanho; i++)
    {
        printf("Digite o valor do vetor[%d]: ", i);
        scanf("%d", &valor);
        vetor[i] = valor;
        fflush(stdin);
    }

    int *vetorSemRepeticao;
    int tamanhoVetorSemRepeticao = 1;
    vetorSemRepeticao = malloc(tamanhoVetorSemRepeticao * sizeof(int)); //Alocando endereco de memoria para o vetorSemRepeticao
    vetorSemRepeticao[0] = vetor[0]; //*p -> pra um vetor logo ele vai apontar para o endereco de memoria do 1 elemento do vetor

    //Pesquisa elemento repetido
    int quantidadeElementosRepetidos = 0;
    int j;
    for(i = 1; i < tamanho; i++)
    {
        int repetido = 1; //Var repetido = true pq aqui nao há elementos repetidos
        for(j = 0; j < tamanhoVetorSemRepeticao; j++)
        {
            if(vetor[i] == vetorSemRepeticao[j])
            {
                repetido = 0; //Var repetido = false pq aqui há elementos repetidos
                quantidadeElementosRepetidos += 1;
                break;
            }
        }
        if(repetido == 1)
        {
            tamanhoVetorSemRepeticao++;
            vetorSemRepeticao = realloc(vetorSemRepeticao, tamanhoVetorSemRepeticao * sizeof(int));
            vetorSemRepeticao[tamanhoVetorSemRepeticao - 1] = vetor[i];
        }
    }

    if(quantidadeElementosRepetidos == 0)
    {
        printf("\nOk\n");
    }
    else
    {
        printf("\n%d elemento(s) repetido(s) removido(s)\n", quantidadeElementosRepetidos);
    }

    ordemCrescente(vetorSemRepeticao, tamanhoVetorSemRepeticao - 1);
    printf("\nVetor ordenado: "); exibeVetor(vetorSemRepeticao, tamanhoVetorSemRepeticao);
    printf("\n\n");

    //Pesquisa Binaria
    int numeroBusca;
    printf("Digite o numero para busca: ");
    scanf("%d", &numeroBusca);
    fflush(stdin);

    int resultado = pesquisaBinaria(numeroBusca, vetorSemRepeticao, tamanhoVetorSemRepeticao);
    if(resultado == -1)
    {
        printf("Numero nao encontrado\n");
    }
    else
    {
        printf("\nNumero encontrado na posicao %d\n", resultado);
    }

    return 0;
}

void ordemCrescente(int *vetor, int n)
{
    int i, j, aux = 0;
    for(i=0; i<n; ++i)
    {
        for(j=i+1; j<n; ++j)
        {
            if(vetor[i] > vetor[j])
            {
                aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;
            }
        }
    }
}

void exibeVetor(int *vetor, int n)
{
    int i;
    for(i=0; i<n; ++i)
    {
        printf(" %d", vetor[i]);
    }
}

int pesquisaBinaria(int numeroBusca, int* vetor, int tamanho)
{
    int indiceEsquerda = 0;
    int indiceDireita = tamanho - 1;
    int indiceMeio;

    while(indiceEsquerda <= indiceDireita)
    {
        indiceMeio = (indiceEsquerda + indiceDireita) / 2;
        if(numeroBusca == vetor[indiceMeio])
        {
            return indiceMeio;
        }
        else if(numeroBusca < vetor[indiceMeio])
        {
            indiceDireita = indiceMeio - 1;
        }
        else
        {
            indiceEsquerda = indiceMeio + 1;
        }
    }
    return -1;
}
