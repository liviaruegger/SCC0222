#include <stdio.h>
#include <stdlib.h>

void imprimir_imagem(int **imagem, int largura, int altura);
void limpar_imagem(int **imagem, int altura);

int main()
{
    // Receber os valores de largura e altura da imagem.
    int largura, altura;
    scanf("%d %d", &largura, &altura);

    // Alocar memória para receber a imagem (matriz de inteiros).
    int **imagem = (int **) malloc(altura * sizeof(int *));
    for (int i = 0; i < altura; i++)
        imagem[i] = (int *) malloc(largura * sizeof(int));

    // Receber imagem (matriz).
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
            scanf(" %d", &imagem[i][j]);
    }

    // Receber o tamanho da borda.
    int borda;
    scanf(" %d", &borda);

    // Dimensões da nova imagem:
    int nova_altura = altura + 2 * borda;
    int nova_largura = largura + 2 * borda;

    // Alocar memória para a imagem com borda (outra matriz de inteiros).
    int **nova_imagem = (int **) malloc(nova_altura * sizeof(int *));
    for (int i = 0; i < nova_altura; i++)
        nova_imagem[i] = (int *) malloc(nova_largura * sizeof(int));

    // Preencher a nova imagem.
    for (int i = 0; i < borda; i++)
    {
        for (int j = 0; j < nova_largura; j++)
            nova_imagem[i][j] = 0;
    }
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < borda; j++)
            nova_imagem[i + borda][j] = 0;

        for (int j = 0; j < largura; j++)
            nova_imagem[i + borda][j + borda] = imagem[i][j];

        for (int j = 0; j < borda; j++)
            nova_imagem[i + borda][j + borda + largura] = 0;
    }
    for (int i = 0; i < borda; i++)
    {
        for (int j = 0; j < nova_largura; j++)
            nova_imagem[i + borda + altura][j] = 0;
    }

    // Saída: imagem com borda, pula linha, imagem original.
    imprimir_imagem(nova_imagem, nova_largura, nova_altura);
    printf("\n");
    imprimir_imagem(imagem, largura, altura);

    // Limpar memória.
    limpar_imagem(nova_imagem, nova_altura);
    limpar_imagem(imagem, altura);

    return 0;
}

// Imprime a imagem passada por referência (uma matriz de inteiros).
void imprimir_imagem(int **imagem, int largura, int altura)
{
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
            printf("%d ", imagem[i][j]);
        printf("\n");
    }
}

// Limpa a memória utilizada para armazenar uma imagem (matriz de inteiros).
void limpar_imagem(int **imagem, int altura)
{
    for (int i = 0; i < altura; i++)
        free(imagem[i]);
    free(imagem);
}