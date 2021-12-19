#include <stdio.h>

int maior(int dados[10])
{
    int maior = dados[0];
    for (int i = 1; i < 10; i++)
        if (dados[i] > maior) maior = dados[i]; 
    
    return maior;
}

int menor(int dados[10])
{
    int menor = dados[0];
    for (int i = 1; i < 10; i++)
        if (dados[i] < menor) menor = dados[i];

    return menor;
}

float media(int dados[10])
{
    float soma = 0;
    for (int i = 0; i < 10; i++)
        soma += dados[i];

    return soma / 10;   
}

int moda(int dados[10])
{
    int moda;
    int contador_moda = 0;
    for (int i = 0; i < 10; i++)
    {
        int contador = 1;
        for (int j = i + 1; j < 10; j++)
        {
            if (dados[i] == dados[j])
                contador++;
        }

        if (contador > contador_moda)
        {
            moda = dados[i];
            contador_moda = contador;
        }
    }

    return moda;
}

int main()
{
    int dados[10];
    for (int i = 0; i < 10; i++)
        scanf(" %d", &dados[i]);

    printf("%d %d %.2f %d\n", maior(dados), menor(dados), media(dados), moda(dados));

    return 0;
}