#include <stdio.h>
#include <stdlib.h> // Função malloc


int main()
{
    // Operadores Unários Endereço &: acessa endereço de uma variável e Ponteiro *: acessa conteúdo e declara ponteiro
 
    int x = 10; // stack

    printf("x = %d\n", x);
    // imprime o endereço físico onde a variável está
    printf("O endereco de x e' = %#x\n", &x);

    // Ponteiro - É usado para declarar uma posição de memória
    int *px = NULL;
    px = &x;
    // Imprime o endereço que ponteiro px aponta
    printf("px = %#x\n", px);
    // Imprime o conteúdo do ponteiro px
    printf("*px = %d\n", *px);
    // Imprime o endereço do ponteiro px
    printf("&px = %#x\n", &px);

    // Operações aritméticas
    x++; // x = x + 1
    printf("x = %d\n*px %d\n", x, *px);
    
    // Operação aritmética direto no conteúdo do ponteiro
    // incrementa o conteúdo que essa variável ponteiro aponta
    (*px)++;
    
    printf("x = %d\n*px = %d\n", x, *px);

    px++; // ando na memória 4 bytes
    // Quando incrementa a posição da memória ele perde a referência da variável que ele estava apontando, por isso seu conteúdo já não é mais o anterior 

    printf("x = %d\n*px = %d\npx = %#x\n", x, *px, px);

    // Ponteiro pode ser de qualquer tipo
    char c = 'a';
    char *pc = &c;

    // Ponteiros void - genérico.
    void *v = 0;
    v = pc;
    printf("v = %#x pc = %#x\n", v, pc);
    // Imprime o conteúdo do ponteiro v, mas por ser um ponteiro genérico presicamos fazer um casting nesse ponteiro    
    printf("v = %c pc = %c\n", *((char*)v), *pc);


    // Cada variável simples que eu declaro (variável que não é um ponteiro) eu guardo na pilha de memória. Essa pilha, quando você termina a execução as variáveis que lá estavam serão liberadas. Então, a memória é liberada. Tem outra parte da memória chamada heap, que é uma área da memória que as variáveis que eu aloco, preciso tomar conta de desalocar. Então ao inves de eu declarar uma variável e apontar um ponteiro direto pro endereço dessa variável posso alocar um ponteiro alocando direto espeço pro heap. vamos ver como faço isso

    // Uso do heap
    int *pxh = 0;
    pxh = malloc(sizeof(int));

    printf("Tamanho do int: %d byte(s)\n", sizeof(int));

    *(pxh) = 10;
    int xh = *(pxh);
    int xhe = pxh;
    // xh vai imprimir o conteúdo de pxh e xhe imprime o endereço de pxh
    printf("xh = %d xhe = %#x\n", xh, xhe);


    // Qualificador const
    // 1) valor do conteúdo não muda! vai dar erro. > const type* mas permite mudar o endereço. ch++;
    // 2) posição da memória constante > type* const mas permite mudar o conteúdo *(ch) = 'd';
    // 3) uso combinado. const *char const. não posso alterar nada
    char *ch = malloc(sizeof(char));
    *(ch) = 'b';
    printf("ch = %c\n", *ch);

    *(ch) = 'c';
    printf("ch = %c\n", *ch);


    // Desalocar com free()
    free(pxh);

    return 0;
}
