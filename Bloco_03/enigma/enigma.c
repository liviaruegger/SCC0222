#include <stdio.h>
#include <stdlib.h>

#define T 26 // Tamanho do rotor.

typedef enum {false, true} bool;

int main()
{
    int rotor1[T], rotor2[T], rotor3[T];

    scanf("%*[^\r\n]s"); // Ignora tudo até o final da linha.

    for (int i = 0; i < T; i++) scanf("%d", &rotor1[i]);
    for (int i = 0; i < T; i++) scanf("%d", &rotor2[i]);
    for (int i = 0; i < T; i++) scanf("%d", &rotor3[i]);

    scanf("%*[\r\n]s");  // Ignora o quebra linha.
    scanf("%*[^\r\n]s"); // Ignora tudo até o final da linha -> pula "Mensagem:"
    scanf("%*[\r\n]s");  // Ignora o quebra linha.

    int leitura;
    char ultimo_char_lido;
    bool esta_no_alfabeto = false;

    while (!feof(stdin))
    {
        for (int i = 0; i < T;)
        {
            for (int j = 0; j < T;)
            {
                for (int k = 0; k < T;)
                {
                    esta_no_alfabeto = false;
                    leitura = scanf("%c", &ultimo_char_lido);
                    if (leitura == EOF) exit(0);

                    int indice;
                    if (ultimo_char_lido >= 'a' && ultimo_char_lido <= 'z')
                    {
                        indice = rotor3[(rotor2[(rotor1[(ultimo_char_lido - 'a' + k) % T] + j) % T] + i) %T];
                        printf("%c", 'a' + indice);
                        esta_no_alfabeto = true;
                    }
                    else if (ultimo_char_lido >= 'A' && ultimo_char_lido <= 'Z')
                    {
                        indice = rotor3[(rotor2[(rotor1[(ultimo_char_lido - 'A' + k) % T] + j) % T] + i) %T];
                        printf("%c", 'A' + indice);
                        esta_no_alfabeto = true;
                    }
                    else
                    {
                        printf("%c", ultimo_char_lido);
                    }

                    // "Rotação" do rotor 1
                    if (esta_no_alfabeto) k++;
                }

                // "Rotação" do rotor 2
                if (esta_no_alfabeto) j++;
            }

            // "Rotação" do rotor 3
            if (esta_no_alfabeto) i++;
        }
    }
    
    return 0;
}