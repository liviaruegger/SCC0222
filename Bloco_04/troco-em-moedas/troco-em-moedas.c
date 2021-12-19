#include <stdio.h>

void calcular_troco(
    int resto, 
    int *real1, 
    int *cent50, 
    int *cent25, 
    int *cent10, 
    int *cent5, 
    int *cent1
)
{
    *real1 = resto / 100;
    resto %= 100;

    *cent50 = resto / 50;
    resto %= 50;

    *cent25 = resto / 25;
    resto %= 25;

    *cent10 = resto / 10;
    resto %= 10;

    *cent5 = resto / 5;
    resto %= 5;

    *cent1 = resto;
}

int main()
{
    int total_centavos;
    scanf("%d", &total_centavos);

    int real1, cent50, cent25, cent10, cent5, cent1;
    calcular_troco(total_centavos, &real1, &cent50, &cent25, &cent10, &cent5, &cent1);

    printf("O valor consiste em %d moedas de 1 real\n", real1);
    printf("O valor consiste em %d moedas de 50 centavos\n", cent50);
    printf("O valor consiste em %d moedas de 25 centavos\n", cent25);
    printf("O valor consiste em %d moedas de 10 centavos\n", cent10);
    printf("O valor consiste em %d moedas de 5 centavos\n", cent5);
    printf("O valor consiste em %d moedas de 1 centavo\n", cent1);

    return 0;
}