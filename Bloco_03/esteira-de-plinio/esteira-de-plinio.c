#include <stdio.h>

#define N_LINHAS 32
#define N_COLUNAS 65

#define PLINIO_ON 1
#define PLINIO_OFF 0

int main()
{
    // ENTRADA
    char esteira[N_LINHAS][N_COLUNAS];

    for (int i = 0; i < N_LINHAS; i++)
    {
        for (int j = 0; j < N_COLUNAS; j++)
        {
            scanf("%c", &esteira[i][j]);
        }
    }
    
    // Procurar início da esteira.
    int i_plinio, j_plinio;
    for (int i = 0; i < N_LINHAS; i++)
    {
        for (int j = 0; j < N_COLUNAS; j += 2)
        {
            if (esteira[i][j] == '[')
            {
                i_plinio = i;
                j_plinio = j + 2;

                i = N_LINHAS;
                j = N_COLUNAS;  //encerra este loop
            } 
        }
    }

    // EXECUÇÃO
    int plinio = PLINIO_ON;
    while (plinio == PLINIO_ON)
    {
        char ultimoMov;

        switch (esteira[i_plinio][j_plinio])
        {
            case '>':
                esteira[i_plinio][j_plinio] = '.';
                j_plinio += 2;
                ultimoMov = '>';
                break;
            
            case '<':
                esteira[i_plinio][j_plinio] = '.';
                j_plinio -= 2;
                ultimoMov = '<';
                break;

            case '^':
                esteira[i_plinio][j_plinio] = '.';
                i_plinio--;
                ultimoMov = '^';
                break;

            case 'v':
                esteira[i_plinio][j_plinio] = '.';
                i_plinio++;
                ultimoMov = 'v';
                break;

            case '#':
                switch (ultimoMov)
                {
                    case '>':
                        j_plinio += 2;
                        break;
                    
                    case '<':
                        j_plinio -= 2;
                        break;

                    case '^':
                        i_plinio--;
                        break;

                    case 'v':
                        i_plinio++;
                        break;
                }
                break;

            case ']':
                printf("Ok.\n");
                plinio = PLINIO_OFF;
                break;

            case '.':
                printf("Loop infinito.\n");
                plinio = PLINIO_OFF;
                break;

            default: //o robô se encontra num lugar que não é esteira, não é # e também não é ] 
                printf("Falha na esteira.\n");
                plinio = PLINIO_OFF;
                break;
        }   
    }
    
    // SAÍDA (impressão da matriz)
    for (int i = 0; i < N_LINHAS; i++)
    {
        for (int j = 0; j < N_COLUNAS; j++)
        {
            printf("%c", esteira[i][j]);
        }
    }

    return 0;
}