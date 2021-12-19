#include <stdio.h>

#define TAMANHO_IMAGEM 25
#define QUANT_DE_CORES 5

#define DEFAULT -1

int main()
{
    int imagem[TAMANHO_IMAGEM];

    for (int i = 0; i < TAMANHO_IMAGEM; i++)
    {
        scanf(" %d", &imagem[i]);
    }

    int corPredominante = DEFAULT;
    int nMaxRepeticoes = DEFAULT;

    for (int i = 0; i < QUANT_DE_CORES; i++)
    {
        printf("%d: |", i);

        int repeticoes = 0;

        for (int j = 0; j < TAMANHO_IMAGEM; j++)
        {
            if (imagem[j] == i)
            {
                printf("#");
                repeticoes++;
            }
        }

        printf("\n");

        if (repeticoes > nMaxRepeticoes)
        {
            nMaxRepeticoes = repeticoes;
            corPredominante = i;
        }
    }

    for (int i = 0; i < TAMANHO_IMAGEM; i++)
    {
        if (imagem[i] == corPredominante)
        {
            printf("%d\n", i);
        }
    }
    
    return 0;
}