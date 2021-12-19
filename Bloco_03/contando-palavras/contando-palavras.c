#include <stdio.h>

#define   VALID 0
#define   SPACE 1
#define     TAB 2
#define BREAK_N 3
#define BREAK_R 4

int main()
{   
    char c;

    int lineCount =  0;
    int wordCount =  0;
    int charCount = -1; // -1 corrects the increment for EOF

    int lastChar = VALID;

    do
    {
        c = getchar();
        charCount++;

        switch (c)
        {
            case ' ':
                if (lastChar == VALID) wordCount++;
                lastChar = SPACE;
                break;
            
            case '\t':
                if (lastChar == VALID) wordCount++;
                lastChar = TAB;
                break;

            case '\n':
                if (lastChar == VALID) wordCount++;
                if (lastChar != BREAK_R) lineCount++;
                lastChar = BREAK_N;
                break;

            case '\r':
                lineCount++;
                if (lastChar == VALID) wordCount++;
                lastChar = BREAK_R;
                break;
            
            case EOF:
                if (lastChar == VALID) wordCount++;
                break;

            default:
                lastChar = VALID;
                break;
        }
    } while (c != EOF);
       
    printf("Linhas\tPalav.\tCarac.\n");
    printf("%d\t%d\t%d", lineCount, wordCount, charCount);

    return 0;
}