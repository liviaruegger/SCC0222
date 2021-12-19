#include <stdio.h>
#include <math.h>

/* Implemente um programa em C que leia da entrada padrão dois números a e b.
Em seguida, imprima na saída padrão o valor de a elevado à potência b.
Escreva o resultado dessa operação com 4 casas decimais. */

int main()
{
    float a, b;

    scanf("%f %f", &a, &b);
    printf("%.4f", pow(a, b));

    return 0;
}