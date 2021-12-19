#include <stdio.h>

/* Implemente um programa em C que imprima o tamanho dos tipos de dados primitivos
da linguagem. Seu programa deve utilizar do operador sizeof para obter o tamanho
dos tipos e então imprimir esses tamanhos em linhas separadas.
*/

int main()
{
    printf("%lu\n", sizeof(unsigned char));
    printf("%lu\n", sizeof(char));
    printf("%lu\n", sizeof(unsigned int));
    printf("%lu\n", sizeof(short int));
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(long int));
    printf("%lu\n", sizeof(unsigned long int));
    printf("%lu\n", sizeof(long long int));
    printf("%lu\n", sizeof(float));
    printf("%lu\n", sizeof(double)); 
    printf("%lu\n", sizeof(long double));

    return 0;
}