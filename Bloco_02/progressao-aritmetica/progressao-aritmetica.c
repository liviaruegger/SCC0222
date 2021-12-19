#include <stdio.h>

int main()
{
    long int a1, r, n, an, soma;

    scanf(" %li %li %li", &a1, &r, &n);
    
    an = a1;
    soma = a1;

    for(; n > 1; n--)
    {
        an += r;
        soma += an;
    }

    printf("%li\n%li", an, soma);

    return 0;
}