#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIM_DA_LINHA '\n'
#define FIM_DA_LISTA '$'

char *ler_nome(char *ultimo_caractere);
void adicionar_sobrenomes(char **lista_nomes, int tamanho_lista);

int main()
{
    char **lista_nomes = (char **) malloc(sizeof(char *));
    
    char ultimo_caractere;
    int tamanho_lista = 0;

    do
    {
        lista_nomes[tamanho_lista] = ler_nome(&ultimo_caractere);
        tamanho_lista++;

        if (ultimo_caractere != FIM_DA_LISTA)
        {
            char **temp = (char **) realloc(lista_nomes, (tamanho_lista + 1) * sizeof(char *));
            lista_nomes = temp;
        }

    } while (ultimo_caractere != FIM_DA_LISTA);
    
    adicionar_sobrenomes(lista_nomes, tamanho_lista);

    for (int i = 0; i < tamanho_lista; i++)
    {
        printf("%s\n", lista_nomes[i]);
        free(lista_nomes[i]);
    }

    free(lista_nomes);
    
    return 0;
}

// A função faz a leitura de uma linha (nome) e retorna o ponteiro para essa string.
// Também armazena, no endereço dado, o último caractere lido (FIM_DA_LINHA ou FIM_DA_LISTA).
char *ler_nome(char *ultimo_caractere)
{
    char *nome = (char *) malloc(sizeof(char));
    int tamanho = 0;

    do
    {
        nome[tamanho] = fgetc(stdin);
        tamanho++;

        if (nome[tamanho - 1] != FIM_DA_LINHA && nome[tamanho - 1] != FIM_DA_LISTA)
        {
            char *temp = (char *) realloc(nome, tamanho + 1);
            nome = temp;
        }

    } while (nome[tamanho - 1] != FIM_DA_LINHA && nome[tamanho - 1] != FIM_DA_LISTA);

    *ultimo_caractere = nome[tamanho - 1];
    nome[tamanho - 1] = '\0';

    return nome;
}

// Acrescenta o último sobrenome de cada linha de índice par ao fim da linha seguinte (ímpar).
void adicionar_sobrenomes(char **lista_nomes, int tamanho_lista)
{
    for (int i = 0; i < tamanho_lista - 1; i += 2)
    {   
        // Nome que fornece o sobrenome (chamando "par"):
        int tamanho_nome_par = strlen(lista_nomes[i]);
        int posicao = tamanho_nome_par - 1;

        // Buscar a posição em que começa o último sobrenome do nome par.
        do
        {
            posicao--;
        
        } while (lista_nomes[i][posicao] != ' ');

        int tamanho_sobrenome = tamanho_nome_par - posicao;

        // Nome que recebe o sobrenome (chamado "ímpar"): 
        int indice_impar = i + 1;
        int tamanho_original_impar = strlen(lista_nomes[indice_impar]);
        int novo_tamanho_impar = tamanho_original_impar + tamanho_sobrenome + 1;
        
        // Realocar o nome ímpar para que caiba o novo sobrenome.
        char *temp = (char *) realloc(lista_nomes[indice_impar], novo_tamanho_impar);
        lista_nomes[indice_impar] = temp;

        // Adicionar o sobrenome.
        for (int j = tamanho_original_impar; j < novo_tamanho_impar; j++)
        {
            lista_nomes[indice_impar][j] = lista_nomes[i][posicao];
            posicao++;
        }

        lista_nomes[indice_impar][novo_tamanho_impar - 1] = '\0';
    }
}