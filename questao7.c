#include <stdio.h>
#include <stdlib.h>

struct Funcionarios
{
    char nome[35];
    char sexo;
    int numeroPecasProduzidas;
};

int cont = 0;

void lerDadosFuncionario(struct Funcionarios *funcionario, int n)
{
    int i, continuar = 1, qtde = 0;
    for(i = 0; i < n; i++)
    {
        continuar = 1;
        printf("\nFuncionario %d\n", i+1);
        printf("Digite o nome: ");
        scanf("%s", funcionario[i].nome);
        fflush(stdin);

        printf("Sexo (M - masculino ou F - feminino): ");
        scanf("\n%c", &funcionario[i].sexo);
        fflush(stdin);

        //Na primeira vez digita a quantidade de pecas sem fazer nenhuma comparacao
        if(i == 0)
        {
            printf("Quantidade de pecas produzidas: ");
            scanf("\n%d", &funcionario[i].numeroPecasProduzidas);
            fflush(stdin);
            cont += 1;
        }
        else
        {
            //A partir da posicao 1 toda vez vai entrar no laço enquanto
            while(continuar == 1)
            {
                printf("Quantidade de pecas produzidas: ");
                scanf("\n%d", &funcionario[i].numeroPecasProduzidas);
                fflush(stdin);
                cont += 1;
                qtde = funcionario[i].numeroPecasProduzidas;

                //Chama a funcao verificaEmpate e passa como paramentro a qtde de peças produzidas
                if(verificaEmpate(funcionario, qtde) == 1)
                {
                    continuar = 1;
                }
                else
                {
                    continuar = 0;
                }
            }
        }
    }
}

int verificaEmpate(struct Funcionarios *funcionario, int quantidade)
{
    int achou = 0;
    int j;
    for(j = 0; j < cont; j++)
    {
        /*  Faz a verificação das peças produzidas
            como a quantidade foi passada por paramentro
            toda vida ele vai comparar com ele mesmo e garente que o achou e' 1
            ou seja para saber que um elemento e' repetido basta o achou ser maior que 1
        */
        if(funcionario[j].numeroPecasProduzidas == quantidade)
        {
            achou++;
        }
    }
    if(achou > 1)
    {
        return 1;
        achou = 0;
    }
    else
    {
        return 0;
    }
}

int qtdePecasProduzidasPeloSexoMasculino(struct Funcionarios *funcionario, int n)
{
    int contadorMasculino = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if(funcionario[i].sexo == 'M')
        {
            contadorMasculino = contadorMasculino + funcionario[i].numeroPecasProduzidas;
        }
    }
    return contadorMasculino;
}

int qtdePecasProduzidasPeloSexoFeminino(struct Funcionarios *funcionario, int n)
{
    int contadorFeminino = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if(funcionario[i].sexo == 'F')
        {
            contadorFeminino = contadorFeminino + funcionario[i].numeroPecasProduzidas;
        }
    }
    return contadorFeminino;
}

void funcionarioComMaiorProducao(struct Funcionarios *funcionario, int n)
{
    int maior = 0, indiceMaior = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if(funcionario[i].numeroPecasProduzidas > maior)
        {
            maior = funcionario[i].numeroPecasProduzidas;
            indiceMaior = i;
        }
    }
    printf("\nFuncionario com maior producao: %s\n\n", funcionario[indiceMaior].nome);
}

int main()
{
    int qtdeFuncionarios = 0;
    printf("Digite a quantidade de funcionarios: ");
    scanf("%d", &qtdeFuncionarios);
    struct Funcionarios *funcionario = malloc(qtdeFuncionarios * sizeof(struct Funcionarios));

    lerDadosFuncionario(funcionario, qtdeFuncionarios);

    int qtdePecasMasculino = 0;
    qtdePecasMasculino = qtdePecasProduzidasPeloSexoMasculino(funcionario, qtdeFuncionarios);
    printf("\nA quantidade de pecas produzidas pelos funcionarios do sexo masculino e' = %d\n", qtdePecasMasculino);

    int qtdePecasFeminino = 0;
    qtdePecasFeminino = qtdePecasProduzidasPeloSexoFeminino(funcionario, qtdeFuncionarios);
    printf("\nA quantidade de pecas produzidas pelos funcionarios do sexo feminino e' = %d\n", qtdePecasFeminino);

    funcionarioComMaiorProducao(funcionario, qtdeFuncionarios);

    free(funcionario);

    return 0;
}
