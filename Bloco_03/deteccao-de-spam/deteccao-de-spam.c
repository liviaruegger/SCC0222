#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 77    //  77 is a valid size only when the last element of the
#define  LAST_ELEMENT 76    //  array is '\n' or '\r' (or the default value 0)

int main()
{
    int spamWordCount = 0;
    int scanReturn;

    do
    {
        char line[MAX_LINE_SIZE] = {0};
        
        for (int i = 0; i < MAX_LINE_SIZE; i++) // Scan line.
        {
            scanReturn = scanf("%c", &line[i]);
            if (line[i] == '\n' || line[i] == '\r' || scanReturn == EOF)
                break;
        }

        // Check if line is too big.
        if (line[LAST_ELEMENT] != 0 && line[LAST_ELEMENT] != '\n' && line[LAST_ELEMENT] != '\r')
        {
            printf("Spam\n");
            exit(0);
        }

        // Count spam words.
        if (strstr(line, "gratuito") != NULL) 
            spamWordCount++;
        if (strstr(line, "imediato") != NULL)
            spamWordCount++;
        if (strstr(line, "dinheiro") != NULL) 
            spamWordCount++;
        if (strstr(line, "limitado") != NULL)
            spamWordCount++;
        if (strstr(line, "atencao") != NULL) 
            spamWordCount++;
        if (strstr(line, "urgente") != NULL) 
            spamWordCount++;
        if (strstr(line, "zoombie") != NULL)
            spamWordCount++;
        if (strstr(line, "oferta") != NULL) 
            spamWordCount++;
        if (strstr(line, "renda") != NULL) 
            spamWordCount++;
        if (strstr(line, "fundo") != NULL) 
            spamWordCount++;
        if (strstr(line, "ajuda") != NULL)
            spamWordCount++;
        if (strstr(line, "SOS") != NULL)
            spamWordCount++;
    } while (scanReturn != EOF);

    if (spamWordCount < 2)
        printf("Inbox\n");
    else
        printf("Spam\n");

    return 0;
}