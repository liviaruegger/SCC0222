#include <stdio.h>

int main()
{
    double a1, q, an, soma;
    long int n;

    scanf(" %lf %lf %li", &a1, &q, &n);
    
    an = a1;
    soma = a1;

    for(; n > 1; n--)
    {
        an = an*q;
        soma += an;
    }

    printf("%.2f\n%.2f", an, soma);

    return 0;
}