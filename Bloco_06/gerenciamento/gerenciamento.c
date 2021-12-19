#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONSULTAR_NUSP   1
#define CONSULTAR_CURSO  2
#define CONSULTAR_TODOS  3
#define ENCERRAR        -1

typedef struct estudante
{
    int   identificador;
    char *nome;
    char *curso;
    int   idade;
}   estudante_t;

char         *ler_string();
estudante_t  *receber_registro();
estudante_t **registrar_estudantes();

void imprimir_registro(estudante_t *estudante);
void consultar_nusp(estudante_t **cadastro, int n_registros);
void consultar_curso(estudante_t **cadastro, int n_registros);
void consultar_todos(estudante_t **cadastro, int n_registros);

void limpar_cadastro(estudante_t **cadastro, int n_registros);

int main()
{
    int n_registros;
    estudante_t **cadastro_geral = registrar_estudantes(&n_registros);

    int comando;
    do
    {
        scanf("%d ", &comando);

        switch (comando)
        {
        case CONSULTAR_NUSP:
            consultar_nusp(cadastro_geral, n_registros);
            break;
        case CONSULTAR_CURSO:
            consultar_curso(cadastro_geral, n_registros);
            break;
        case CONSULTAR_TODOS:
            consultar_todos(cadastro_geral, n_registros);
            break;
        }

    } while (comando != ENCERRAR);

    limpar_cadastro(cadastro_geral, n_registros);

    return 0;
}

// Lê e armazena uma string da entrada padrão.
// Retorna um ponteiro para essa string.
char *ler_string()
{
    char *string = (char *) malloc(sizeof(char));
    int tamanho = 0;

    do
    {
        string[tamanho] = fgetc(stdin);
        tamanho++;

        if (string[tamanho - 1] != '\n')
            string = (char *) realloc(string, tamanho + 1);

    } while (string[tamanho - 1] != '\n');

    string[tamanho - 1] = '\0';

    return string;
}

// Lê e armazena um registo de estudante (estudante_t) da entrada padrão.
// Retorna um ponteiro para o registro salvo (uma struct estudante)
// ou um ponteiro nulo quando encontra o valor de fim da lista.
estudante_t *receber_registro()
{
    estudante_t *estudante = (estudante_t *) malloc(sizeof(estudante_t));

    scanf("%d\n", &estudante->identificador);

    if (estudante->identificador == ENCERRAR)
    {
        free(estudante);
        return NULL;
    }
    
    estudante->nome  = ler_string();
    estudante->curso = ler_string();
    scanf("%d\n", &estudante->idade);

    return estudante;
}

// Lê da entrada padrão uma série de registros até receber um vetor nulo.
// Retorna um ponteiro duplo para o vetor de registros e a quantidade de registros.
estudante_t **registrar_estudantes(int *n_registros)
{
    estudante_t **cadastro = NULL;
    estudante_t *estudante = NULL;

    int indice_registro = 0;

    do
    {
        estudante = receber_registro();

        if (estudante != NULL)
        {
            cadastro = (estudante_t **) realloc(cadastro, (indice_registro + 1) * sizeof(estudante_t *));
            cadastro[indice_registro] = estudante;
            indice_registro++;
        }

    } while (estudante != NULL);

    *n_registros = indice_registro;
    
    return cadastro;
}

// Recebe como parâmetro o ponteiro para um registro de estudante (estudante_t *)
// e imprime na saída as informações contidas no registro.
void imprimir_registro(estudante_t *estudante)
{
    printf("Nome: %s\n", estudante->nome);
    printf("Curso: %s\n", estudante->curso);
    printf("N USP: %d\n", estudante->identificador);
    printf("IDADE: %d\n\n", estudante->idade);
}

// Recebe um inteiro da entrada padrão e compara com os identificadores cadastrados.
// Caso o identificador apareça no cadastro geral, imprime as informações daquele estudante.
void consultar_nusp(estudante_t **cadastro, int n_registros)
{
    int nusp;
    scanf("%d\n", &nusp);

    for (int i = 0; i < n_registros; i++)
    {
        if (nusp == cadastro[i]->identificador)
        {
            imprimir_registro(cadastro[i]);
            return;
        }
    }

    printf("Aluno nao cadastrado\n");
}

// Recebe um nome de curso da entrada padrão e imprime as informações
// de todos os estudantes daquele curso encontrados no cadastro.
void consultar_curso(estudante_t **cadastro, int n_registros)
{
    char *curso = ler_string();

    for (int i = 0; i < n_registros; i++)
    {
        if (strcmp(cadastro[i]->curso, curso) == 0)
            imprimir_registro(cadastro[i]);
    }

    free(curso);
}

// Imprime as informações de todos os estudantes no cadastro.
void consultar_todos(estudante_t **cadastro, int n_registros)
{
    for (int i = 0; i < n_registros; i++)
        imprimir_registro(cadastro[i]);
}

// Recebe um ponteiro duplo para o cadastro geral e desaloca toda a memória utilizada.
void limpar_cadastro(estudante_t **cadastro, int n_registros)
{
    for (int i = 0; i < n_registros; i++)
    {
        free(cadastro[i]->nome);
        free(cadastro[i]->curso);
        free(cadastro[i]);
    }

    free(cadastro);
}