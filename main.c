#include <stdio.h>
#include <stdlib.h>

void ordemDecrescente(int vetor[], int n);
void exibeVetor(int vetor[], int n);
void calculaExibeQuantidadePar(int vetor[], int n);
void calculaExibeQuantidadeImpar(int vetor[], int n);
void mediaNumerosImparesMaioresCinquenta(int vetor[], int n);

int main()
{
    int tamanhoVetor, contador=0;
    int vetor[tamanhoVetor];
    printf("Digite o tamanho da lista: ");
    scanf("%d", &tamanhoVetor);
    fflush(stdin);

    if(tamanhoVetor <= 100)
    {
        int i;
        for(i=0; i<tamanhoVetor; ++i)
        {
            printf("Digite o valor da lista[%d] ", i+1);
            scanf("%d", &vetor[i]);
            fflush(stdin);

            if(vetor[i] < 256)
            {
                contador++;
            }
            else { /*Aqui os numeros maiores ou iguais a 256 sao ignorados*/ }
        }

        ordemDecrescente(vetor, tamanhoVetor);
        exibeVetor(vetor, tamanhoVetor);
        calculaExibeQuantidadePar(vetor, tamanhoVetor);
        calculaExibeQuantidadeImpar(vetor, tamanhoVetor);
        mediaNumerosImparesMaioresCinquenta(vetor, tamanhoVetor);
    }
    else
    {
        printf("Tamanho nao permitido\nA lista tem no maximo 100 numeros inteiros\n");
    }

    return 0;
}

void ordemDecrescente(int vetor[], int n)
{
    int i, j, menor;
    for(i=0; i<n; ++i)
    {
        for(j=i+1; j<n; ++j)
        {
            if(vetor[i] < vetor[j])
            {
                menor = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = menor;
            }
        }
    }
}

void calculaExibeQuantidadePar(int vetor[], int n)
{
    int i, contadorPar=0;
    for(i=0; i<n; ++i)
    {
        if(vetor[i]%2 == 0)
        {
            contadorPar++;
        }
    }
    printf("\nA quantidade de numeros pares dessa lista e': %d\n", contadorPar);
}

void calculaExibeQuantidadeImpar(int vetor[], int n)
{
    int i, contadorImpar=0;
    for(i=0; i<n; ++i)
    {
        if(vetor[i]%2 != 0)
        {
            contadorImpar++;
        }
    }
    printf("A quantidade de numeros impares dessa lista e': %d\n", contadorImpar);
}

void mediaNumerosImparesMaioresCinquenta(int vetor[], int n)
{
    float soma=0, media=0;
    int i, contador=0;
    for(i=0; i<n; ++i)
    {
        if((vetor[i]%2 != 0) && vetor[i] > 50)
        {
            contador++;
            soma+=vetor[i];
            media=soma/contador;
        }
    }
    printf("A media dos numeros imapres maiores que cinquenta e' %.2f\n", media);
}

void exibeVetor(int vetor[], int n)
{
    int i;
    for(i=0; i<n; ++i)
    {
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }
}
