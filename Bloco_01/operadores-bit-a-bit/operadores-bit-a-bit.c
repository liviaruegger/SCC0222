#include <stdio.h>

/* Implemente um programa em C que leia da entrada padrão dois números inteiros
positivos a e b. Realize e imprima na saída padrão em linhas separadas o resultado
das seguintes operações bit a bit (ver abaixo). Imprima o resultado como um inteiro.
*/

int main()
{
    int a, b;
    scanf("%i %i", &a, &b);

    // a AND b (&)
    printf("%i\n", a & b);

    // a OR b (|)
    printf("%i\n", a | b);

    // a Exclusive OR b (^)
    printf("%i\n", a ^ b);
    
    // Complement a
    printf("%i\n", ~a);
    
    // Complement b
    printf("%i\n", ~b);

    // a Right shift 2
    printf("%i\n", a >> 2);  
    
    // b Left shift 2
    printf("%i\n", b << 2); 

    return 0;
}