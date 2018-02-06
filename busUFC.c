#include <stdio.h>
#include <stdlib.h>

struct Cadastro
{
	unsigned char *nomeLinha;
	unsigned char *numeroLinha;
	unsigned char *pontoPartida;
	unsigned char *pontoFinal;
	unsigned char *horario;
};

int main()
{
	FILE *file;
	file = fopen("bus.txt", "w");

	if (file == NULL)
	{
		printf("Erro!\n");
		exit(1);
	}
	else
	{
		int option;
		do
		{
			printf("\nSEJA BEM-VINDO!\n1 - Cadastrar linha de onibus");
			printf("\n2 - Sair\n\n");
			scanf("%d", &option);

			switch(option)
			{
				case 1:
				{
					struct Cadastro *cadastro = malloc(sizeof(struct Cadastro));

					unsigned char *nome = malloc(sizeof(unsigned char));
					unsigned char *num = malloc(sizeof(unsigned char));
					unsigned char *partida = malloc(sizeof(unsigned char));
					unsigned char *fim = malloc(sizeof(unsigned char));
					unsigned char *hora = malloc(sizeof(unsigned char));

               printf("Digite o nome da linha de onibus de interesse: ");
               scanf(" \n%s ", nome);
					fflush(stdin);
           			
					printf("Digite o numero da linha: ");
               scanf(" \n%s ", num);
               fflush(stdin);

					printf("Digite o ponto de partida do onibus: ");
               scanf(" \n%s ", partida);
               fflush(stdin);

					printf("Digite o ponto final do onibus: ");
               scanf(" \n%s ", fim);
               fflush(stdin);

					printf("Digite o horario do onibus: ");
               scanf("\n%s", hora);
               fflush(stdin);

					cadastro->nomeLinha = nome;
					cadastro->numeroLinha = num;
					cadastro->pontoPartida = partida;
					cadastro->pontoFinal = fim;
					cadastro->horario = hora;	
		
					fprintf (file, "ONIBUS QUE PASSAM NA ENTRADA DO CAMPUS DO PICI - UFC, PELA AVENIDA ENG. HUMBERTO MONTE.");

					fprintf (file,"\n\n%s", cadastro->nomeLinha);
					fprintf (file,"\n%s", cadastro->numeroLinha);
					fprintf (file,"\n%s", cadastro->pontoPartida);
					fprintf (file,"\n%s", cadastro->pontoFinal);
					fprintf (file,"\n%s", cadastro->horario);	

					free(cadastro);
					free(nome);
					free(num);
					free(partida);
					free(fim);
					free(hora);
					break;
				}
				case 2:
				{
					break;
				}
				default:
				{
					printf("Opcao invalida");
				}
			}

		} while (option != 2);

	}

	fclose(file);

	return 0;
}

