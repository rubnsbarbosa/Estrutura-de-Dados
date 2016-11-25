#include <stdio.h>
#include <stdlib.h>

struct Questionario
{
    char sexo;
    int estadoCivil;
    int idade;
    float rendaAnual;
};

void lerDadosMoradoresPatoBranco(struct Questionario *renda, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("\nMorador %d\n", i+1);
        printf("Sexo (M - Masculino ou F - Feminino): ");
        scanf("\n%c", &renda[i].sexo);
        fflush(stdin);

        printf("0 - Solteiro\n1 - Casado\n2 - Viuvo\n3 - Divorciado\nEstado Civil: ");
        scanf("%d", &renda[i].estadoCivil);
        fflush(stdin);

        printf("Idade em anos: ");
        scanf("%d", &renda[i].idade);
        fflush(stdin);

        printf("Renda anual: ");
        scanf("%f", &renda[i].rendaAnual);
        fflush(stdin);
    }
}

int quantidadeHomens(struct Questionario *renda, int n)
{
    int contHomens = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if(renda[i].sexo == 'M')
        {
            contHomens++;
        }
    }
    return contHomens;
}

int quantidadeMulheres(struct Questionario *renda, int n)
{
    int contMulheres = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if(renda[i].sexo == 'F')
        {
            contMulheres++;
        }
    }
    return contMulheres;
}

//Calcula a quantidade de mulheres solteiras
void quantidadeEntrevistadasSolteiras(struct Questionario *renda, int n)
{
    int mulheresSolteiras = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if((renda[i].sexo == 'F') && (renda[i].estadoCivil == 0))
        {
            mulheresSolteiras += 1;
        }
    }
    printf("\n%d entrevistadas solteiras\n", mulheresSolteiras);
}

void porcentagemHomensDivorciados(struct Questionario *renda, int n)
{
    float porcentagem = 0, totalHomens = 0, homensDivorciados = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if((renda[i].estadoCivil == 3) && (renda[i].sexo == 'M'))
        {
            totalHomens = quantidadeHomens(renda, n);
            homensDivorciados = homensDivorciados + 1;
            porcentagem = (homensDivorciados/totalHomens) * 100;
        }
    }
    printf("\n%.2f porcento dos homens divorciados em relacao ao total de homens\n", porcentagem);
}

void rendaAnualMediaMulheresCasadas(struct Questionario *renda, int n)
{
    float media = 0, soma = 0, qtdeMulheresCasadasComIdadeEntreVinteQuarenta = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if((renda[i].sexo == 'F') && (renda[i].estadoCivil == 1) && ((renda[i].idade >=20) && (renda[i].idade <= 40)))
        {
            qtdeMulheresCasadasComIdadeEntreVinteQuarenta++;
            soma = soma + renda[i].rendaAnual;
            media = (soma / qtdeMulheresCasadasComIdadeEntreVinteQuarenta);
        }
    }
    printf("\n%.2f reais e' a renda anual media das mulheres casadas entre 20 e 40 anos\n\n", media);
}

int main()
{
    int qtdePessoas;
    printf("Digite quantas pessoas responderam o questionario: ");
    scanf("%d", &qtdePessoas);
    struct Questionario *renda = malloc(qtdePessoas * sizeof(struct Questionario));

    lerDadosMoradoresPatoBranco(renda, qtdePessoas);

    int soma = 0, homens = 0, mulheres = 0;
    homens = quantidadeHomens(renda, qtdePessoas);
    mulheres = quantidadeMulheres(renda, qtdePessoas);
    soma = (homens + mulheres);
    printf("\n%d homens entrevistados\n%d mulheres entrevistadas\n", homens, mulheres);
    printf("A quantidade de homens e mulheres entrevistados: %d\n", soma);

    quantidadeEntrevistadasSolteiras(renda, qtdePessoas);
    porcentagemHomensDivorciados(renda, qtdePessoas);
    rendaAnualMediaMulheresCasadas(renda, qtdePessoas);

    free(renda);

    return 0;
}
