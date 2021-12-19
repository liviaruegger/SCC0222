#include <stdio.h>

/* Implemente um programa em C que leia na entrada padrão de texto um número inteiro,
representando um ano do calendário. Verifique se este ano é um ano bissexto. Em caso
positivo, escreva na tela a palavra “SIM”, em caso negativo escreva a palavra “NAO”.

Um ano bissexto é, para os propósitos deste exercício, um ano divisível por 4.
Atenção: Inclua um '\n' ao final da resposta. */

int main()
{
    int ano;
    scanf("%d", &ano);

    if (ano % 4 == 0)
        printf("SIM\n");
    else
        printf("NAO\n");

    return 0;
}