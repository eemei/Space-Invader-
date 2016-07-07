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

int moveShipLeftRifht() {
  int x = 5, y = 5;     // initial value for ship at coordinate x & y
  int filler;
  int ch = _getch ();
  if (ch == 0 || ch == 224){
    switch (ch= _getch ())
    {
      case KEY_LEFT:
        printf("left\n");
        x = x - 1;
        y = y;
        gotoXY(x,y);
        filler = y + 1;
        bufferFillerwithSpace(filler, x, 32);
        printf("now value coordX when pressed left = %d\n",x);
        return ch;
      break;
      
      case KEY_RIGHT:
        printf("right\n");
        x = x + 1;
        y = 0;
        gotoXY(x,y);
        filler = y + 1;
        bufferFillerwithSpace(filler, x, 32);
        printf("now value coordX when pressed right = %d\n",x);
        return ch;
        break;
    }
  }
}

// used to place things anywhere in the window
int gotoXY(int x, int y) {  
int filler;
filler= y+1;
char ship[][3] = {{" T "},
                  {"[+]"}};
                  

  if (x <=  0)          // minimum range
    x = 0;
  
  else if (x >= 47)   // maximum range
    x = 47;

  else               // in the range 
  x = x;   
  
  bufferFillerwithSpace(filler, x-1, 32);
  bufferFillerwithSpace(filler, x+3, 32);
  draw ((char *)ship, 3, 2, x, y);
  transferImageToConsole();
  return x;
}

int continuPress(){
  int ch;
  int x = 42;
  int y = 40;
  
 while ((ch = getch()) != ESC){
    printf("%d", ch);
    if (ch == 0 || ch == 224){
      ch = getch();
        if( ch == KEY_RIGHT){
          printf("right\n");
          x = x + 1;
          y = y;
          gotoXY(x,y);
          printf("\nx~~= %d\n",x);
        }
          else {
            printf("left\n");
            x = x - 1;
            y = y;
            gotoXY(x,y);
            printf("\nx~~= %d\n",x);
          }
        }
 }
    
  printf("ESC %d\n", ch);
  return 0;
}

