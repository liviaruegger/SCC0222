#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main()
{
    char jogo[3][3];
    int jogoCompleto = TRUE;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf(" %c", &jogo[i][j]);
            
            if (jogo[i][j] == '-')
                jogoCompleto = FALSE;
        }
    }

    for (int i = 0; i < 3; i++) // testar linhas
    {
        if (jogo[i][0] != '-' && jogo[i][0] == jogo[i][1] && jogo[i][0] == jogo[i][2])
        {
            printf("%c ganhou", jogo[i][0]);
            exit(0);
        }
    }

    for (int j = 0; j < 3; j++) // testar colunas
    {
        if (jogo[0][j] != '-' && jogo[0][j] == jogo[1][j] && jogo[0][j] == jogo[2][j])
        {
            printf("%c ganhou", jogo[0][j]);
            exit(0);
        }
    }

    if (jogo[0][0] != '-' && jogo[0][0] == jogo[1][1] && jogo[0][0] == jogo[2][2]) //testar diagonal 1
    {
        printf("%c ganhou", jogo[0][0]);
        exit(0);
    }

    if (jogo[0][2] != '-' && jogo[0][2] == jogo[1][1] && jogo[0][2] == jogo[2][0]) //testar diagonal 2
    {
        printf("%c ganhou", jogo[0][2]);
        exit(0);
    }

    if (jogoCompleto == TRUE)
        printf("empate");

    else if (jogoCompleto == FALSE)
        printf("em jogo");

    return 0;
}