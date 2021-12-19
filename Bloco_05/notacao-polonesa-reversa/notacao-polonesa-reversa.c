#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
    double *valores;
    int     topo;
} pilha_t;

void guardar_valor(pilha_t *pilha);
void calcular(char operacao, pilha_t *pilha);

int main()
{
    // Cria a pilha.
    pilha_t *pilha = (pilha_t *) malloc(sizeof(pilha_t));
    pilha->valores = NULL;
    pilha->topo = 0;

    // Faz a leitura das entradas até EOF; executa operações.
    char leitura;
    do
    {
        leitura = getc(stdin);

        // Trata cada um dos casos (dígito ou operação; se for espaço, apenas descarta).
        if (leitura >= '0' && leitura <= '9')
        {
            // "Devolve" o char, de forma que ele pode ser lido novamente como um valor.
            // A função realiza nova leitura da entrada, desta vez como um double.
            ungetc(leitura, stdin); 
            guardar_valor(pilha);
        }
        else if (leitura == '+' || leitura == '-' || leitura == '*' || leitura == '/')
        {
            calcular(leitura, pilha);
        }
            
    } while (leitura != EOF);

    // Saída: imprime o resultado da operação.
    printf("Resultado: %.6lf\n", pilha->valores[pilha->topo - 1]);

    // Libera a memória utilizada na heap.
    free(pilha->valores);
    free(pilha);

    return 0;
}

// Lê o número da entrada padrão e armazena na pilha (push), alocando memória dinamicamente.
void guardar_valor(pilha_t *pilha)
{
    pilha->valores = (double *) realloc(pilha->valores, (pilha->topo + 1) * sizeof(double));
    scanf("%lf", &pilha->valores[pilha->topo]);
    pilha->topo++;
}

// Realiza a operação dada, retirando os dois valores do topo da pilha (pop).
// Armazena o resultado da operação no topo da pilha.
void calcular(char operacao, pilha_t *pilha)
{
    // Pegar o valor b do topo da pilha (pop).
    double b = pilha->valores[pilha->topo - 1];
    pilha->topo--;
    pilha->valores = (double *) realloc(pilha->valores, (pilha->topo) * sizeof(double));

    // Pegar o valor a do topo da pilha (pop).
    double a = pilha->valores[pilha->topo - 1];
    pilha->topo--;
    pilha->valores = (double *) realloc(pilha->valores, (pilha->topo) * sizeof(double));

    // Realiza a operação passada como parâmetro.
    double resultado;
    switch (operacao)
    {
    case '+':
        resultado = a + b;
        break;

    case '-':
        resultado = a - b;
        break;

    case '*':
        resultado = a * b;
        break;

    case '/':
        resultado = a / b;
        break;
    }

    // Armarzena o resultado da operação no topo da pilha; incrementa a variável topo.
    pilha->valores = (double *) realloc(pilha->valores, (pilha->topo + 1) * sizeof(double));
    pilha->valores[pilha->topo] = resultado;
    pilha->topo++;
}