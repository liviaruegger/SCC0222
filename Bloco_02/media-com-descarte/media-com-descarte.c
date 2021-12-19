#include <stdio.h>

int main()
{
    double a, b, c, d, m;

    scanf(" %lf %lf %lf %lf", &a, &b, &c, &d); // %lf = máscara para double

    if (a <= b && a <= c && a <= d) // a é o menor valor
        m = (b + c + d)/3;
    else if (b <= a && b <= c && b <= d) // b é o menor valor
        m = (a + c + d)/3;
    else if (c <= a && c <= b && c <= d) // c é o menor valor
        m = (a + b + d)/3;
    else // d é o menor valor
        m = (a + b + c)/3;        

    printf("%.4f\n", m);

    return 0;
}