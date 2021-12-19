#include <stdio.h>

/* Implemente um programa em C que leia na entrada padrão de texto um número real a,
um operador (char) op e um número real b. Em seguida, imprima na tela o resultado da
operação matemática a op b. O operador op pode ser um de quatro caracteres que
representam as funções básicas +, −, ∗ e /, ou o símbolo %. Neste caso, você
deve imprimir a porcentagem que a representa de b (Exemplo: 8 % 50 = 16%).

    > Utilize um switch para determinar qual operação realizar.
    > Atenção: o operador % nesse exercício não indica o módulo da divisão.
    > Imprima a saída com 6 casas decimais de precisão.
    > Adicione um '\n' após o resultado.
*/

int main()
{
    float a, b, x;
    char op;

    scanf(" %f %c %f", &a, &op, &b);

    switch(op)
    {
        case '+':
            x = a + b;
            break;
        case '-':
            x = a - b;
            break;
        case '*':
            x = a*b;
            break;
        case '/':
            x = a/b;
            break;
        case '%':
            x = (a/b)*100;
            break;
    }

    printf("%.6f\n", x);

    return 0;
}