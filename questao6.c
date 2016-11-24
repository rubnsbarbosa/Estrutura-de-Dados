#include <stdio.h>
#include <stdlib.h>

struct Candidatos
{
    char nome[35];
    char sexo;
    int idade;
    char experiencia;
};

void lerInformacoesCandidatos(struct Candidatos *candidato, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("\nCandidato numero %d\n", i+1);
        printf("Digite o nome: ");
        scanf("%s", candidato[i].nome);
        //gets(candidato[i].nome);
        fflush(stdin);

        printf("Sexo (M - masculino ou F - feminino): ");
        scanf("\n%c", &candidato[i].sexo);
        fflush(stdin);

        printf("Digite a idade: ");
        scanf("\n%d", &candidato[i].idade);
        fflush(stdin);

        printf("Experiencia no servico (S - sim ou N - nao): ");
        scanf("\n%c", &candidato[i].experiencia);
        fflush(stdin);
    }
}

int contadorSexoMasculino(struct Candidatos *candidato, int n)
{
    int contadorMasculino = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if(candidato[i].sexo == 'M')
        {
            contadorMasculino = contadorMasculino + 1;
        }
    }
    return contadorMasculino;
}

int contadorSexoFeminino(struct Candidatos *candidato, int n)
{
    int contadorFeminino = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if(candidato[i].sexo == 'F')
        {
            contadorFeminino = contadorFeminino + 1;
        }
    }
    return contadorFeminino;
}

void calculaMediaIdadeHomensComExperiencia(struct Candidatos *candidato, int n)
{
    float contador = 0, soma = 0, media = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if((candidato[i].sexo == 'M') && (candidato[i].experiencia == 'S'))
        {
            contador = contador + 1;
            soma = soma + candidato[i].idade;
            media = soma/contador;
    }
        }
    printf("\nA idade media dos homens que ja' tem experiencia no servico e' = %.2f \n", media);
}

void calculaPorcentagemDosHomensComMaisDeQuarentaCincoAnos(struct Candidatos *candidato, int n)
{
    float porcentagem = 0, totalHomens = 0, homensComMaisDeQuarentaCinco = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if((candidato[i].sexo == 'M') && (candidato[i].idade > 45))
        {
            totalHomens = contadorSexoMasculino(candidato, n);
            homensComMaisDeQuarentaCinco++;
            porcentagem = (homensComMaisDeQuarentaCinco/totalHomens) * 100;
        }
    }
    printf("\nA porcentagem dos homens com mais de 45 anos entre o total de homens e' = %.2f \n", porcentagem);
}

void calculaNumeroMulheresIdadeMenorTrintaCincoComExperiencia(struct Candidatos *candidato, int n)
{
    int i, mulheresIdadeMenorTrintaCincoComExperiencia = 0;
    for(i = 0; i < n; i++)
    {
        if((candidato[i].sexo == 'F') && (candidato[i].idade < 35))
        {
            mulheresIdadeMenorTrintaCincoComExperiencia++;
        }
    }
    printf("\n%d mulheres com idade menor que 35 anos e com experiencia \n\n", mulheresIdadeMenorTrintaCincoComExperiencia);
}

int main()
{
    int tamanhoVetorCandidatos = 0;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanhoVetorCandidatos);
    struct Candidatos *candidato = malloc(tamanhoVetorCandidatos * sizeof(struct Candidatos));

    lerInformacoesCandidatos(candidato, tamanhoVetorCandidatos);

    int quantidadeMulheres = 0;
    quantidadeMulheres = contadorSexoFeminino(candidato, tamanhoVetorCandidatos);
    printf("\n%d do sexo feminino\n", quantidadeMulheres);

    int quantidadeHomens = 0;
    quantidadeHomens = contadorSexoMasculino(candidato, tamanhoVetorCandidatos);
    printf("\n%d do sexo masculino\n", quantidadeHomens);

    calculaMediaIdadeHomensComExperiencia(candidato, tamanhoVetorCandidatos);
    calculaPorcentagemDosHomensComMaisDeQuarentaCincoAnos(candidato, tamanhoVetorCandidatos);
    calculaNumeroMulheresIdadeMenorTrintaCincoComExperiencia(candidato, tamanhoVetorCandidatos);

    free(candidato);

    return 0;
}
