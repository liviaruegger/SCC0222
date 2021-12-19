#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int x1, y1, l1, h1;
    scanf("%li %li %li %li\n", &x1, &y1, &l1, &h1);

    long int x2, y2, l2, h2;
    scanf("%li %li %li %li", &x2, &y2, &l2, &h2);

    if ((x1 + l1) < x2 || (x2 + l2) < x1 || (y1 + h1) < y2 || (y2 + h2) < y1)
    {
        printf("MISS\n");
        exit(0);
    }
    else
    {
        long int xiV1 = x1;
        long int yiV1 = y1;
        long int xiV2 = x1 + l1;
        long int yiV2 = y1 + h1;

        if (x1 <= x2 && x2 <= x1 + l1)
            xiV1 = x2;

        if (y1 + h1 >= y2 && y2 >= y1)
            yiV1 = y2;

        if (x1 <= x2 + l2 && x2 + l2 <= x1 + l1)
            xiV2 = x2 + l2;

        if (y1 + h1 >= y2 + h2 && y2 + h2 >= y1)
            yiV2 = y2 + h2;

        long int li = xiV2 - xiV1;
        long int hi = yiV2 - yiV1;

        printf("HIT: %li %li %li %li\n", xiV1, yiV1, li, hi);
    }
    
    return 0;
}