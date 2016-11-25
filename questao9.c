#include <stdio.h>
#include <stdlib.h>

struct Lancamento
{
    int dia;
    int mes;
    int ano;
};

struct Caixa
{
    char situacao;
    struct Lancamento data;
    char tipo;
    char historico[31];
    float valor;
};

void lerDadosLivros(struct Caixa *caixa, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("\nLancamento %d\n", i+1);
        printf("Situacao do registro (x - ocupado e * - apagado): ");
        scanf("\n%c", &caixa[i].situacao);
        fflush(stdin);

        printf("Data do lancamento\n");
        printf("Dia: ");
        scanf("%d", &caixa[i].data.dia);
        fflush(stdin);

        printf("Mes: ");
        scanf("%d", &caixa[i].data.mes);
        fflush(stdin);

        printf("Ano: ");
        scanf("%d", &caixa[i].data.ano);
        fflush(stdin);

        printf("Tipo do lancamento (D - despesa e R - Receita): ");
        scanf("\n%c", &caixa[i].tipo);
        fflush(stdin);

        printf("Historico do lancamento: ");
        scanf("\n%s", caixa[i].historico);
        fflush(stdin);

        printf("Valor do lancamento: ");
        scanf("%f", &caixa[i].valor);
        fflush(stdin);
    }
}

void quantidadeLancamentoTipoDespesa(struct Caixa *caixa, int n)
{
    int contLancamentoDespesaJaneiro = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if((caixa[i].tipo == 'D') && ((caixa[i].data.mes == 1) && (caixa[i].data.ano == 2005)))
        {
            contLancamentoDespesaJaneiro++;
        }
    }
    printf("\nQtde de lancamentos do tipo despesa realizados no mes de janeiro de 2005: %d\n", contLancamentoDespesaJaneiro);
}

void somaLancamentoDespesaReceita(struct Caixa *caixa, int n)
{
    float somaLancamentoDespesa = 0;
    float somaLancamentoReceita = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if((caixa[i].tipo == 'D') && (caixa[i].data.ano == 2005))
        {
            somaLancamentoDespesa += caixa[i].valor;
        }
        else if((caixa[i].tipo == 'R') && (caixa[i].data.ano == 2005))
        {
            somaLancamentoReceita += caixa[i].valor;
        }
    }
    printf("\nSoma dos lancamentos de despesa realizados no ano de 2005: %.2f\n", somaLancamentoDespesa);
    printf("\nSoma dos lancamentos de receita realizados no ano de 2005: %.2f\n", somaLancamentoReceita);
}

//Calcula saldo anterior a março de 2005
float calculaSaldoAnterior(struct Caixa *caixa, int n)
{
    float saldoAnterior = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if((caixa[i].tipo == 'R') && (caixa[i].data.mes < 3) && (caixa[i].data.ano <= 2005))
        {
            saldoAnterior += caixa[i].valor;
        }
    }
    return saldoAnterior;
}

//Calcula total de receitas em março de 2005
float calculaReceitas(struct Caixa *caixa, int n)
{
    float receitas = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if((caixa[i].tipo == 'R') && ((caixa[i].data.mes == 3) && (caixa[i].data.ano == 2005)))
        {
            receitas += caixa[i].valor;
        }
    }
    return receitas;
}

//Calcula total de despesas em março de 2005
float calculaDespesas(struct Caixa *caixa, int n)
{
    float despesas = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if((caixa[i].tipo == 'D') && ((caixa[i].data.mes == 3) && (caixa[i].data.ano == 2005)))
        {
            despesas += caixa[i].valor;
        }
    }
    return despesas;
}
//Calcula o saldo do livro caixa no mês de março de 2005
void calculaSaldo(struct Caixa *caixa, int n)
{
    float saldo = 0, receitas = 0, despesas = 0, saldoAnterior = 0;

    receitas = calculaReceitas(caixa, n);
    despesas = calculaDespesas(caixa, n);
    saldoAnterior = calculaSaldoAnterior(caixa, n);

    saldo = ((saldoAnterior + receitas) - despesas);

    printf("\nSaldo Mar/2005: %2.f\n\n", saldo);
}

int main()
{
    int quantidadeLancamentos = 0;
    printf("Digite a quantidade de lancamentos: ");
    scanf("%d", &quantidadeLancamentos);
    struct Caixa *caixa = malloc(quantidadeLancamentos * sizeof(struct Caixa));

    lerDadosLivros(caixa, quantidadeLancamentos);

    quantidadeLancamentoTipoDespesa(caixa, quantidadeLancamentos);
    somaLancamentoDespesaReceita(caixa, quantidadeLancamentos);
    calculaSaldo(caixa, quantidadeLancamentos);

    free(caixa);

    return 0;
}
