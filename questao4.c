#include <stdio.h>
#include <stdlib.h>

int encontraPrimo(int elemento);
int recAntecessor(int n);
int recSucessor(int n);

int main()
{
    int primo = 0;
    printf("Digite um numero: ");
    scanf("%d", &primo);
    fflush(stdin);

    int continuar = 0;
    if(encontraPrimo(primo) == 1)
    {
        printf("O numero digitado e' primo\n");
    }
    else
    {
        continuar = 1;
        while(continuar == 1)
        {
            printf("Digite um numero: ");
            scanf("%d", &primo);
            fflush(stdin);
            //chama a funcao encontra primo retorna 1 se e' primo e 0 senao e' primo

            if(encontraPrimo(primo) == 1)
            {
                printf("O numero digitado e' primo\n");
                continuar = 0;
            }
        }
    }
    int auxAntecessor;
    if(primo >= 5)
    {
        auxAntecessor = recAntecessor(primo - 1);
        recAntecessor(auxAntecessor - 1);
    }
    if(primo == 3)
    {
        recAntecessor(primo - 1);
    }
    if(primo == 2)
    {
        printf("Nao tem antecessor\n");
    }

    int auxSucessor;
    auxSucessor = recSucessor(primo + 1);
    recSucessor(auxSucessor + 1);

    return 0;
}

int encontraPrimo(int elemento)
{
    int i, cont = 0;
    for(i = 1; i <= elemento; i++)
    {
        if(elemento % i == 0)
        {
            cont = cont + 1;
        }
    }

    if(cont == 2)
    {
        return 1;
    }
    return 0;
}

int recAntecessor(int n)
{
    int contador = 0;
    int i;
    for(i = 1; i <= n; i++)
    {
        if(n % i == 0)
        {
            contador = contador + 1;
        }
    }

    if(contador == 2)
    {
        printf("Antecessor: %d\n", n);
        return n;
    }
    else
    {
        return recAntecessor(n - 1);
    }
}

int recSucessor(int n)
{
    int contador = 0;
    int i;
    for(i = 1; i <= n; i++)
    {
        if(n % i == 0)
        {
            contador = contador + 1;
        }
    }

    if(contador == 2)
    {
        printf("Sucessor: %d\n", n);
        return n;
    }
    else
    {
        return recSucessor(n + 1);
    }
}
