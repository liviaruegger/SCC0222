#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *jit_bf = fopen("jit_bf.c", "w");

    // Escreve no arquivo .c:
    // Cebçalho, início da main, declaração da memória com zeros, declaração do ponteiro.
    fprintf(jit_bf, "#include <stdio.h>\n");
    fprintf(jit_bf, "int main() {");
    fprintf(jit_bf, "char mem[30000] = {};");
    fprintf(jit_bf, "int i = 0;");

    // Escreve no arquivo .c:
    // Comandos brainfuck traduzidos para C.
    char comando;
    do
    {
        comando = fgetc(stdin);
        switch (comando)
        {
        case '+':
            fprintf(jit_bf, "mem[i]++;");
            break;
        case '-':
            fprintf(jit_bf, "mem[i]--;");
            break;
        case '>':
            fprintf(jit_bf, "i++;");
            break;
        case '<':
            fprintf(jit_bf, "i--;");
            break;
        case '.':
            fprintf(jit_bf, "putchar(mem[i]);");
            break;
        case '[':
            fprintf(jit_bf, "while(mem[i]) {");
            break;
        case ']':
            fprintf(jit_bf, "}");
            break;
        }
    } while (comando != EOF);
    
    // Escreve no arquivo .c:
    // Trecho que imprime valores não nulos da memória.
    fprintf(jit_bf, "printf(\"\\n\");");
    fprintf(jit_bf, "for (int j = 0; j < 30000; j++) {");
    fprintf(jit_bf, "if (mem[j] != 0) {");
    fprintf(jit_bf, "printf(\"%%d \", mem[j]);}}");
    fprintf(jit_bf, "printf(\"\\n\");");

    // Escreve no arquivo .c:
    // Fim da main.
    fprintf(jit_bf, "return 0;}");

    fclose(jit_bf);

    // Compilar e executar o programa que foi gerado em C.
    system("gcc jit_bf.c -o jit_bf");
    system("./jit_bf");

    return 0;
}