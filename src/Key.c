#include <stdlib.h>
#include <stdio.h>
#include "Key.h"
#include "BlockDiagram.h"

int escKey(){
  int ch;
  while ((ch = getch()) != 27){
    printf("%d", ch);
    if (ch == 0 || ch == 224)
      printf (", %d,", getch()); 
    printf("\n");
  }
  printf("ESC %d\n", ch);
  
  return ch;
}

int fireBullet(){
  int fire, kbPressed;
  
  while ((kbPressed = kbhit()) != 1);
  printf("%d\n", kbPressed);
  if (kbPressed){
    fire = getch();
    printf("%d\n", fire);
    return fire;
  } 
}

int arrow(){
  int x = 5, y = 5; // initial value for ship at coordinate x & y
  //int x1= gotoXY(5,5);
  //printf("x1= %d\n",x1);
  int ch = _getch ();
  if (ch == 0 || ch == 224){
    switch (ch= _getch ())
    {
      case KEY_LEFT:
        printf("left\n");
        x = x - 1;
        y = y;
        gotoXY(x,y);
        printf("x~= %d\n",x);
        
        return x;
      break;
      
      case KEY_RIGHT:
        printf("right\n");
        x = x + 1;
        y = 0;
        gotoXY(x,y);
        printf("x~~= %d\n",x);
        return x;
        break;
    }
    

}
}

int gotoXY(int x, int y) // used to place things anywhere in the window
{  

char ship[][3] = {{" T "},
                  {"[+]"}};
                  

  if (x <=  0)
    x = 0;
  //printf("x inside gotoXY func = %d\n", x);
  
  else if (x >= 47)
    x = 47;
  //printf("x inside gotoXY func = %d\n", x);
  else 
    x = x; 
  
   printf("x inside gotoXY func~~ = %d\n", x); 
 draw ((char *)ship, 3, 2, x, y);
   transferImageToConsole();
//return x;
}

int continuPress() {
  int ch;
  int x = 42;
  int y =40;
  int filler;
 while ((ch = getch()) != ESC){
    printf("%d", ch);
    if (ch == 0 || ch == 224){
      ch = getch();
        if( ch = KEY_RIGHT){
        printf("right\n");
        x = x + 1;
        y = y;
        gotoXY(x,y);
        filler = y +1;
        bufferFillerwithSpace(filler, x, 32);
        printf("x~~= %d\n",x);
        }
  }
  printf("ESC %d\n", ch);
  

}
return 0;
}

