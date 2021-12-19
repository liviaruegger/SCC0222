#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, p; // nº rodadas, nº jogadores, posicao pingu
    scanf("%i %i %i", &n, &m, &p);

    int rodada = 0;
    int vez = 0;
    int n_pinguins = 0;
    
    while (rodada <= n)
    {   
        n_pinguins += 1;

        for (int j = 0; j < n_pinguins; j++) // falar "x pinguins"
        {
            rodada++;
            vez++;
                
            if (vez == p)
            {
                if (rodada == 1)
                        printf("1 pinguim\n");
                else
                        printf("%i pinguins\n", n_pinguins);
            }
            
            if (rodada == n)
                exit(0);

            if (vez == m)
                vez = 0;
        }
        
        for (int j = 0; j < n_pinguins; j++) // falar "no gelo"
        {
            rodada++;
            vez++;

            if (vez == p)
                printf("no gelo\n");

            if (rodada == n)
                exit(0);
                
            if (vez == m)
                vez = 0;
        }

        for (int j = 0; j < n_pinguins; j++) // falar "uhuu!"
        {
            rodada++;
            vez++;

            if (vez == p)
                printf("uhuu!\n");

            if (rodada == n)
                exit(0);
            
            if (vez == m)
                vez = 0;
        }        
    }

    return 0;
}