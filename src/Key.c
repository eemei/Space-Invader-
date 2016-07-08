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

int moveShipLeftRight() {
  int coor_X = 5, coor_Y = 5;     // initialise value for ship at coordinate coor_X & coor_Y
  int ch = _getch ();
  if (ch == 0 || ch == 224){
    switch (ch= _getch ())
    {
      case KEY_LEFT:
        printf("left\n");
        coor_X = coor_X - 1;
        coor_Y = coor_Y;
        gotoXY(coor_X,coor_Y);
        printf("now value coordX when pressed left = %d\n",coor_X);
        //return ch;
        return coor_X;
      break;
      
      case KEY_RIGHT:
        printf("right\n");
        coor_X = coor_X + 1;
        coor_Y = coor_Y;
        gotoXY(coor_X,coor_Y);
        printf("now value coordX when pressed right = %d\n",coor_X);
        //return ch;
        return coor_X;
        break;
    }
  }
}

// used to place things anywhere in the window
int gotoXY(int coor_X, int coor_Y) {  
int filler;
filler= coor_Y+1;
char ship[][3] = {{" T "},
                  {"[+]"}};
                  

  if (coor_X <=  0)        // minimum range
    coor_X = 0;
  
  else if (coor_X >= 47)   // maximum range
    coor_X = 47;

  else                    // in the range 
  coor_X = coor_X;   
  
  bufferFillerWithSpace(filler, coor_X-1, 32);
  bufferFillerWithSpace(filler, coor_X+3, 32);
  draw ((char *)ship, 3, 2, coor_X, coor_Y);
  transferImageToConsole();
  return coor_X;
}

int continuPress(){
  int ch;
  int coor_X = 42;
  int coor_Y = 40;
  
 while ((ch = getch()) != ESC){
    printf("%d", ch);
    if (ch == 0 || ch == 224){
      ch = getch();
        if( ch == KEY_RIGHT){
          printf("right\n");
          coor_X = coor_X + 1;
          coor_Y = coor_Y;
          gotoXY(coor_X,coor_Y);
          printf("\nx~~= %d\n",coor_X);
          return ch;
        }
          else {
            printf("left\n");
            coor_X = coor_X - 1;
            coor_Y = coor_Y;
            gotoXY(coor_X,coor_Y);
            printf("\nx~~= %d\n",coor_X);
            return ch;
          }
        }
 }
    
  printf("ESC %d\n", ch);
  return 0;
}

