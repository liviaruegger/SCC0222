#include <stdio.h>
#include <string.h>

#define DIA_TERRA 24 * 60 * 60
#define DIA_VENUS 243 * 24 * 60 * 60
#define DIA_MERCURIO (58 * 24 + 16) * 60 * 60
#define DIA_JUPITER 9 * 60 * 60 + 56 * 60

void calcular_dhms(
    char planeta[8],
    unsigned long long int total_segundos,
    unsigned long long int *dias,
    unsigned long long int *horas,
    unsigned long long int *minutos,
    unsigned long long int *segundos
)
{
    int dia_planeta;
    if (strcmp(planeta, "Terra") == 0)
        dia_planeta = DIA_TERRA;
    else if (strcmp(planeta, "Venus") == 0)
        dia_planeta = DIA_VENUS;
    else if (strcmp(planeta, "Mercurio") == 0)
        dia_planeta = DIA_MERCURIO;
    else if (strcmp(planeta, "Jupiter") == 0)
        dia_planeta = DIA_JUPITER;

    *dias = total_segundos / dia_planeta;
    total_segundos %= dia_planeta;

    *horas = total_segundos / (60 * 60);
    total_segundos %= (60 * 60);

    *minutos = total_segundos / 60;
    total_segundos %= 60;

    *segundos = total_segundos;
}

int main()
{
    unsigned long long int total_segundos;
    char planeta[8];

    scanf("%llu ", &total_segundos);
    for (int i = 0; i < 8; i++)
    {
        int temp = fgetc(stdin);
        if (temp != EOF)
            planeta[i] = temp;
        else
            planeta[i] = '\0';
    }

    unsigned long long int dias, horas, minutos, segundos;
    calcular_dhms(planeta, total_segundos, &dias, &horas, &minutos, &segundos);

    printf("%llu segundos no planeta %s equivalem a:\n", total_segundos, planeta);
    printf("%llu dias, %llu horas, %llu minutos e %llu segundos\n", dias, horas, minutos, segundos);

    return 0;
}