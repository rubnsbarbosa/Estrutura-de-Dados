#include <stdio.h>
#include <stdlib.h>

struct Feriado
{
    int destino;
    int veiculo;
};

void lerQuestionario(struct Feriado *feriado, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("\nMotorista %d ", i+1);
        printf("\n1 - Camocim\n2 - Morro Branco\n3 - Aracati\n4 - Guaramiranga\n5 - Outros Locais\nPra onde vai: ");
        scanf("%d", &feriado[i].destino);
        fflush(stdin);

        printf("\n1 - Automovel\n2 - Caminhao\n3 - Onibus\n4 - Outros Veiculos\nQual tipo de veiculo: ");
        scanf("%d", &feriado[i].veiculo);
        fflush(stdin);
    }
}

int quantidadeAutomoveisQueForamAracati(struct Feriado *feriado, int n)
{
    int i, contCarrosAracati = 0;
    for(i = 0; i < n; i++)
    {
        if((feriado[i].destino == 3) && (feriado[i].veiculo == 1))
        {
            contCarrosAracati = contCarrosAracati + 1;
        }
    }
    return contCarrosAracati;
}

int contadorCaminhoes(struct Feriado *feriado, int n)
{
    int contCaminhoes = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if(feriado[i].veiculo == 2)
        {
            contCaminhoes = contCaminhoes + 1;
        }
    }
    return contCaminhoes;
}

void porcentagemCaminhoesComDestinoCamocim(struct Feriado *feriado, int n)
{
    float porcentagem = 0, totalCaminhoes = 0, contCaminhoesCamocim = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if((feriado[i].veiculo == 2) && (feriado[i].destino == 1))
        {
            contCaminhoesCamocim++;
            totalCaminhoes = contadorCaminhoes(feriado, n);
            porcentagem = (contCaminhoesCamocim/totalCaminhoes) * 100;
        }
    }
    if(totalCaminhoes == 0)
    {
        printf("\nNenhum caminhao foi para Camocim, logo 0 porcento\n");
    }
    else
    {
        printf("\n%.2f porcento dos caminhoes tinham destino Camocim\n", porcentagem);
    }
}

int contadorVeiculos(struct Feriado *feriado, int n)
{
    int totalVeiculosTrafegavamPelasRodoviarias = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if((feriado[i].veiculo == 1) || (feriado[i].veiculo == 2) || (feriado[i].veiculo == 3) || (feriado[i].veiculo == 4))
        {
            totalVeiculosTrafegavamPelasRodoviarias++;
        }
    }
    return totalVeiculosTrafegavamPelasRodoviarias;
}

void porcentagemOnibusTrafegamPelaRodoviaria(struct Feriado *feriado, int n)
{
    float porcentagem = 0, totalVeiculos = 0, totalOnibus = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if(feriado[i].veiculo == 3)
        {
            totalOnibus = totalOnibus + 1;
            totalVeiculos = contadorVeiculos(feriado, n);
            porcentagem = (totalOnibus/totalVeiculos) * 100;
        }
    }
    if(totalOnibus == 0)
    {
        printf("\nNenhum onibus trafegou pela rodoviaria, logo 0 porcento\n\n");
    }
    else
    {
        printf("\n%.2f porcento dos onibus trafegam pela rodoviaria\n\n", porcentagem);
    }
}

int main()
{
    int quantidadeMotoristas = 0;
    printf("Digite a quantidade de motoristas: ");
    scanf("%d", &quantidadeMotoristas);
    struct Feriado *feriado = malloc(quantidadeMotoristas * sizeof(struct Feriado));

    lerQuestionario(feriado, quantidadeMotoristas);

    int carrosAracati = 0;
    carrosAracati = quantidadeAutomoveisQueForamAracati(feriado, quantidadeMotoristas);
    printf("\n%d carro(s) tinha(m) destino Aracati\n", carrosAracati);

    porcentagemCaminhoesComDestinoCamocim(feriado, quantidadeMotoristas);
    porcentagemOnibusTrafegamPelaRodoviaria(feriado, quantidadeMotoristas);

    free(feriado);

    return 0;
}
