#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 0

char *read_line(char end_char);

int main()
{
    char *taboo_word = read_line('\n');
    char *phrase = read_line('$');

    int taboo_word_size = strlen(taboo_word);
    int phrase_size = strlen(phrase);
    
    // Ponteiro para comparação:
    // vai avançar de 1 em 1 e checar se há ocorrência da palavra tabu.
    char *compare_ptr = phrase;

    int taboo_word_counter = 0;

    for (int i = 0; i <= phrase_size - taboo_word_size; i++)
    {
        // A função strncmp retornará 0 (definido TRUE) quando encontrar a palavra tabu.
        int found_taboo_word = strncmp(taboo_word, compare_ptr, taboo_word_size);

        // Se houver ocorrência da palavra tabu, trata o caso.
        // Se não houver, apenas avança o ponteiro.
        if (found_taboo_word == TRUE)
        {
            taboo_word_counter++;

            // Identifica o trecho de frase após a palavra tabu (que será movido):
            char *move_string_ptr = compare_ptr + taboo_word_size;
            int move_string_size = strlen(move_string_ptr);

            // A função memmove move um bloco de memória para um novo endereço.
            // Esse processo é feito utilizando uma cópia temporária,
            // portanto não há problema na sobreposição dos blocos.
            memmove(compare_ptr, move_string_ptr, move_string_size + 1);

            // Realoca a frase com seu novo tamanho (sem a palavra tabu).
            phrase = (char *) realloc(phrase, (phrase_size - taboo_word_size + 1));
        }
        else
        {
            compare_ptr++;
        }
    }

    printf("A palavra tabu foi encontrada %d vezes\n",taboo_word_counter);
    printf("Frase: %s\n", phrase);

    free(taboo_word);
    free(phrase);

    return 0;
}

// Lê uma string da entrada padrão até encontrar o caractere passado como parâmetro (end_char).
// Retorna o ponteiro para essa string.
char *read_line(char end_char)
{
    char *string = (char *) malloc(sizeof(char));
    int string_size = 0;

    do
    {
        string[string_size] = fgetc(stdin);
        string_size++;

        if (string[string_size - 1] != end_char)
            string = (char *)realloc(string, string_size + 1);

    } while (string[string_size - 1] != end_char);

    string[string_size - 1] = '\0';

    return string;
}