#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int erros, acertos_totais, acertos_jogada;
const char *banco_de_palavras[] = {"one","two","three"};

int main()
{
    char palavra_secreta [20];
    printf("\n Erros: %d ",erros);
    printf("\n Acertos da Jogada: %d ",acertos_jogada);
    printf("\n Acertos Totais: %d ",acertos_totais);    
    printf("\n Banco de palavras: \n%s \n%s \n%s",banco_de_palavras[0],banco_de_palavras[1],banco_de_palavras[2]);
}