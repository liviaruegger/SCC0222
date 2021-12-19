#include <stdio.h>

#define AR ' '
#define AGUA '~'
#define AREIA '#'
#define CIMENTO '@'

char particulas[32][64];

void inicializar_matriz();
void imprimir_frame();
void aplicar_fisica();
void trocar(char[32][64], int, int, int, int);

//  A função main deve consistir essencialmente de um loop que imprime a matriz
//  de estado e em seguida chama a função de aplicar a física. Esse loop deve
//  rodar por um determinado número de iterações fornecido na entrada padrão.

int main()
{
    inicializar_matriz();

    int total_frames;
    scanf("%d", &total_frames);

    int frame_atual = 0;
    while (frame_atual < total_frames)
    {
        // leitura das instruções de criação de partícula
        int frame, x, y;
        char nova_particula;
        int leitura = scanf(" %d: %d %d %c", &frame, &x, &y, &nova_particula);

        // se não há novas partículas (EOF), a simulação continua até o frame final
        if (leitura == EOF)
            frame = total_frames;

        // imprime e calcula todos os frames até o frame de nova partícula / frame final
        while (frame_atual < frame)
        {
            printf("frame: %d\n", ++frame_atual);
            imprimir_frame();
            aplicar_fisica();
        }

        // quando há uma nova particula a ser adicionada, cria essa partícula
        if (leitura != EOF)
            particulas[y][x] = nova_particula;
    }

    return 0;
}

void inicializar_matriz()
{
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 64; j++)
            particulas[i][j] = AR;
    }
}

void imprimir_frame()
{
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 64; j++)
            printf("%c", particulas[i][j]);

        printf("\n");
    }
}

void aplicar_fisica()
{
    // copia a matriz de partículas para calcular o próximo frame
    char copia_particulas[32][64];
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 64; j++)
            copia_particulas[i][j] = particulas[i][j];
    }

    // executa a mudança para cada partícula
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            // verifica se a partícula é areia ou água; trata o caso
            if (particulas[i][j] == AREIA)
            {
                // 1. compara abaixo (i + 1, j)
                // 2. compara abaixo, à esquerda (i + 1, j - 1)
                // 3. compara abaixo, à direita (i + 1, j + 1)
                if (i + 1 < 32 && (particulas[i + 1][j] == AR || particulas[i + 1][j] == AGUA))
                    trocar(copia_particulas, i, j, i + 1, j);
                else if (i + 1 < 32 && j - 1 >= 0 && (particulas[i + 1][j - 1] == AR || particulas[i + 1][j - 1] == AGUA))
                    trocar(copia_particulas, i, j, i + 1, j - 1);
                else if (i + 1 < 32 && j + 1 < 64 && (particulas[i + 1][j + 1] == AR || particulas[i + 1][j + 1] == AGUA))
                    trocar(copia_particulas, i, j, i + 1, j + 1);
            }
            else if (particulas[i][j] == AGUA)
            {
                // 1. compara abaixo (i + 1, j)
                // 2. compara abaixo, à esquerda (i + 1, j - 1)
                // 3. compara abaixo, à direita (i + 1, j + 1)
                // 4. compara à esquerda (i, j - 1)
                // 5. compara à direita (i, j + 1)
                if (i + 1 < 32 && particulas[i + 1][j] == AR)
                    trocar(copia_particulas, i, j, i + 1, j);
                else if (i + 1 < 32 && j - 1 >= 0 && particulas[i + 1][j - 1] == AR)
                    trocar(copia_particulas, i, j, i + 1, j - 1);
                else if (i + 1 < 32 && j + 1 < 64 && particulas[i + 1][j + 1] == AR)
                    trocar(copia_particulas, i, j, i + 1, j + 1);
                else if (j - 1 >= 0 && particulas[i][j - 1] == AR)
                    trocar(copia_particulas, i, j, i, j - 1);
                else if (j + 1 < 64 && particulas[i][j + 1] == AR)
                    trocar(copia_particulas, i, j, i, j + 1);
            }
        }
    }

    // atualiza o estado da simulação (substitui pela cópia)
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 64; j++)
            particulas[i][j] = copia_particulas[i][j];
    }
}

void trocar(char copia[32][64], int i, int j, int i_troca, int j_troca)
{
    char temp = copia[i][j];
    copia[i][j] = copia[i_troca][j_troca];
    copia[i_troca][j_troca] = temp;
}