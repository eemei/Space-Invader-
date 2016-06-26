#include <stdlib.h>
#include <stdio.h>
#include "Key.h"

// System dependent key codes
enum
{
    KEY_ESC     = 27,
    ARROW_UP    = 256 + 72,
    ARROW_DOWN  = 256 + 80,
    ARROW_LEFT  = 256 + 75,
    ARROW_RIGHT = 256 + 77
};
/* 
int EscKey(){
int ch;

   ch = kbhit(); 
   // while ((ch = getch()) != 27) // 27 = Esc key 
   // {
        printf("%d", ch);
        if (ch == 0 || ch == 224)
            printf (", %d,", getch()); 
        printf("\n");
   // }

    //printf("ESC %d\n", ch); 
    return ch;
}  */



// attempt  to trap arrow keys
// tested with Code::Blocks 8.02


void arrow()
{
  
    int ch;
    //EscKey();
    printf("Press arrow keys, escape key + enter to exit:\n");
    while (( ch = get_code()) != KEY_ESC )
    {
        switch (ch)
        {
        case ARROW_UP:
            printf("UP\n");
            break;
        case ARROW_DOWN:
            printf("DOWN\n");
            break;
        case ARROW_LEFT:
            printf("LEFT\n");
            break;
        case ARROW_RIGHT:
            printf("RIGHT\n");
            break;
        }
    }
    ch = getchar();   // wait
    printf("getchar = %d\n",getchar());
    //return 0;
}

static int get_code()
{
    int ch = getch();

    if (ch == 0 || ch == 224)
        ch = 256 + getch();

    return ch;
}