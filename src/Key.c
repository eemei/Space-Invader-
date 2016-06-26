#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
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



//  kbhit()
//  If a key has been pressed then it returns a non zero value otherwise returns zero.


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

static int get_code(){
  //while (!kbhit()){
 //   Printf("please Press arrow keys, escape key + enter to exit:\n ")
    //do cool processing here in this loop, which has to continue happening till user presses a key
//}

  int ik;
  ik = kbhit();
  printf ("%d\n", ik);
  //Now the user has pressed a key
  //To know which key we do following
  int ch; 
  ch = getch();
  //now we have the user input in the variable ch
  //we can decide further course of action based upon value in ch
  //like as follows

  if (ch == 0 || ch == 224)
        ch = 256 + getch();

    return ch;
}