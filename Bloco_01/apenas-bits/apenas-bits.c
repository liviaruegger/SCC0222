#include <stdio.h>

/* Implemente um programa em C que leia da entrada padrão um número inteiro. 
Em seguida, imprima na saída padrão quatro caracteres adjacentes que sejam 
correspondentes aos 4 bytes contidos no int. Ou seja, o programa deve reinterpretar
os primeiros (mais significativos) 8 bits do número como o primeiro caractere, os 
próximos 8 como o segundo e assim por diante. */

/*  
    o char tem 1 byte                  >                            XXXXXXXX
    o int tem 4 bytes                  > XXXXXXXX XXXXXXXX XXXXXXXX XXXXXXXX
    máscara byte menos significativo   > 00000000 00000000 00000000 11111111   = 255
*/

/*
    Na transformação de int -> char, pegamos sempre o byte menos significativo;
    nesse caso, poderia transformar o char apenas com shift (sem utilizar máscara).
    
    OBS.: optei por utilizar a máscara porque ela é mencionada no enunciado, mas
    o programa funciona exatamente da mesma forma sem a máscara.
*/ 

int main ()
{
    int n, c1, c2, c3, c4;

    scanf("%i", &n);

    c1 = (n >> 24) & 255;    
    c2 = (n >> 16) & 255;
    c3 = (n >> 8)  & 255;
    c4 =  n        & 255; 

    printf("%c%c%c%c", c1, c2, c3, c4);

    return 0;
}