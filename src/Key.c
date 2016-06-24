#include <stdlib.h>
#include <stdio.h>
#include "Key.h"

void EscKey(){
int ch;

    while ((ch = getch()) != 27) /* 27 = Esc key */
    {
        printf("%d", ch);
        if (ch == 0 || ch == 224)
            printf (", %d,", getch()); 
        printf("\n");
    }

    printf("ESC %d\n", ch);
}
