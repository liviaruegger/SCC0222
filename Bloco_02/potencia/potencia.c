#include <stdio.h>

/* Implemente um programa em C que leia duas entradas (dois números inteiros).
Calcule o primeiro número elevado ao segundo utilizando estruturas de repetição.
Nota: não se deve utilizar funções prontas, como a pow(). */

int main()
{
    int a, b;
    int pot = 1;
    
    scanf(" %i %i", &a, &b);

    for(; b >= 1; b--)
        pot = pot*a;
        
    printf("%i", pot);

    return 0;
}