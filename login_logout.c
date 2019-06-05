#include <stdio.h>
#include <stdlib.h>

struct dados
{
    int login;
    char dataLogin[10];
    char horaLogin[10];
    char dataLogout[10];
    char horaLogout[10];
};

struct no
{
    struct no *prox;
    struct dados valor;
};

void inserir(struct no **noInicial, struct dados login)
{
    struct no *novoNo = malloc(sizeof(struct no));
    novoNo->valor=login;
    novoNo = *noInicial;
    *noInicial = novoNo;
}

struct dados mostrar(struct no **noInicial)
{
    if(*noInicial == NULL)
        printf("Lista vazia!\n");
    else
    {
        struct no *aux = *noInicial;
        while(aux != NULL)
        {
            printf("Login: %d\n", aux->valor.login);
            printf("Data de Login: %s\n" ,aux->valor.dataLogin);
            printf("Hora de Login: %s\n" ,aux->valor.horaLogin);
            printf("Data de Logout: %s\n" ,aux->valor.dataLogout);
            printf("Hora de Logout: %s\n" ,aux->valor.horaLogout);
            aux = aux->prox;
        }
    }
}

int main()
{
    struct no *no = NULL;

    int opcao;
    do
    {
        printf("Entre com a opcao desejada!\n1-Inserir dados\n2-Mostrar dados\n3-Sair");
        scanf("%d", &opcao);
        fflush(stdin);

        switch(opcao)
        {
        case 1:
            {
                struct dados login;
                printf("login: ");
                scanf("%d", &login.login);
                fflush(stdin);

                printf("Data de Login: ");
                scanf("%s", &login.dataLogin);
                fflush(stdin);

                printf("Hora de Login: ");
                scanf("%s", &login.horaLogin);
                fflush(stdin);

                printf("Data de Logout: ");
                scanf("%s", &login.dataLogout);
                fflush(stdin);

                printf("Hora de Logout: ");
                scanf("%s", &login.horaLogout);
                fflush(stdin);
                system("cls");

                inserir(&no,login);
                break;
            }
            case 2:
            {
              mostrar(&no);
              break;
            }
           case 3:
            {
              break;
            }
        }
    }while(opcao != 3);
  return 0;
}
