#include <stdio.h>
#include <stdbool.h>

double calcular();

int main()
{
    char leitura;
    do
    {
        double resultado;

        leitura = getc(stdin);
        if (leitura >= '0' && leitura <= '9')
        {
            ungetc(leitura, stdin);
            scanf("%lf", &resultado);
            printf("%.6lf\n", resultado);
        }
        else if (leitura == '(')
        {
            resultado = calcular();
            printf("%.6lf\n", resultado);
            scanf("\n");
        }

    } while (leitura != EOF);

    return 0;
}

// Função recursiva que calcula uma operação da forma (operador valor1 valor2)
// recebida da entrada padrão. Quando a função é chamada, o primeiro parêntese
// já foi consumido, portanto o primeiro caractere lido é sempre o operador.
// Caso um dos valores não seja um número e sim uma nova operação entre parên-
// ses, a função chama a si mesma a fim de calcular este valor.
// Retorna sempre o resultado daquela operação.
double calcular()
{
    double valor1, valor2, resultado;

    bool leu_valor1 = false;
    bool leu_valor2 = false;

    char operador = getc(stdin);

    char leitura;
    do
    {
        leitura = getc(stdin);

        if (leu_valor1 == true && leu_valor2 == true)
        {
            switch (operador)
            {
            case '+':
                resultado = valor1 + valor2;
                break;
            case '-':
                resultado = valor1 - valor2;
                break;
            case '*':
                resultado = valor1 * valor2;
                break;
            case '/':
                resultado = valor1 / valor2;
                break;
            }
        }
        else if (leitura >= '0' && leitura <= '9')
        {
            ungetc(leitura, stdin);
            if (leu_valor1 == false)
            {
                scanf("%lf", &valor1);
                leu_valor1 = true;
            }
            else if (leu_valor2 == false)
            {
                scanf("%lf", &valor2);
                leu_valor2 = true;
            }
        }
        else if (leitura == '(')
        {
            if (leu_valor1 == false)
            {
                valor1 = calcular();
                leu_valor1 = true;
            }
            else if (leu_valor2 == false)
            {
                valor2 = calcular();
                leu_valor2 = true;
            }
        }

    } while (leitura != ')');

    return resultado;
}