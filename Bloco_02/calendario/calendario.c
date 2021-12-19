#include <stdio.h>

#define TRUE 0

int main()
{
    int dia;
    scanf("%i", &dia);

    printf("         Abril 2021         \n");
    printf(" Do  Se  Te  Qu  Qu  Se  Sa \n");
    printf("                ");
    
    for (int i = 1; i <= 30; i++)
    {   
        int sabado = (i - 3) % 7;
        if (sabado == TRUE)
        {
            if (i == dia)
                printf("(%2d)\n", i);
            else
                printf(" %2d \n", i);
        }
        else
        {
            if (i == dia)
                printf("(%2d)", i);
            else
                printf(" %2d ", i);            
        }
    }

    return 0;    
}