#include <stdio.h>
#include <stdlib.h>

int main()
{
    int estacao;
    scanf("%d", &estacao);

    if (estacao <= 5)
    {
        switch (estacao)
        {
        case 0:
            printf("* Morumbi\n|\n");
            estacao++;
        
        case 1:
            printf("* Butanta\n|\n");
            estacao++;
        
        case 2:
            printf("* Pinheiros\n|\n");
            estacao++;
        
        case 3:
            printf("* Faria Lima\n|\n");
            estacao++;
        
        case 4:
            printf("* Fradique Coutinho\n|\n");
            estacao++;
        
        case 5:
            printf("* Oscar Freire\n");
            exit(0);
        }
    }
    else
    {
        switch (estacao)
        {
        case 6:
            printf("* Paulista\n|\n");
            estacao++;
        
        case 7:
            printf("* Higienopolis-Mackenzie\n|\n");
            estacao++;
        
        case 8:
            printf("* Republica\n|\n");
            estacao++;
        
        case 9:
            printf("* Luz\n");
        }
    }

    return 0;
}