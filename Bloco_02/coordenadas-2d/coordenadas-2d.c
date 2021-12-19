#include <stdio.h>

int main()
{
    int x = 0;
    int y = 0;
    char comando;

    for (int i = 0; i < 6; i++)
    {
        scanf("%c", &comando);

        switch(comando)
        {
            case 'W':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'A':
                x--;
                break;
            case 'D':
                x++;
                break;
        }
    }

    printf("%d %d\n", x, y);
    
    return 0;
}