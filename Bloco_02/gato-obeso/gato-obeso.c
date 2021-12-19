#include <stdio.h>

int main()
{
    int bola, racao, perda;

    scanf(" %i %i", &bola, &racao);
    
    // 1 bolinha = perde 5g
    // 1 mordida = ganha 3g
    // meta = 30g

    perda = (bola*5) - (racao*3);

    if (perda >= 30)
        printf("P");
    else if (perda >= 0)
        printf("B");
    else
        printf("R");

    return 0;
}