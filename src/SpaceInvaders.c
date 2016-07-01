#include <stdlib.h>
#include <stdio.h>
#include "Key.h"
#include "BlockDiagram.h"
#include "SpaceInvaders.h"

const char alien1[][3] = {{" ^ "},
                          {" @ "},
                          {"* *"}};

const char alien2[][4] =  {{" ^^ "},
                           {" @@ "},
                           {"*  *"}};

const char alien3[][6] = {{" ^^^ "},
                          {" @@@ "},
                          {"* * *"}};

const char alien4[][5] = {{" |*| "},
                          {" @@@ "},
                          {"*   *"}};
                           
const char planet[][4] = {{" -- "},
                          {"===="},
                          {" -- "}};     

const char ship[][3] = {{" T "},
                        {"[+]"}};
                         
const char shelter[][5] = {{"-----"},
                           {"|[+]|"},
                           {"-----"}};
                          
const char explode[][3] = {{"   "},
                           {"{ }"},
                           {"   "}};
                         
const char bullet[] = {"|"};

void spaceInvader(){
  int i, keyPressed, coorBullet=24;
  bufferFiller(50, 50, 0x20);
  draw((char *)ship, 3, 2, 23, 48);
  keyPressed = fireBullet();
  
  draw((char *)alien1, 3, 3, 23, 0);
  
  for (i=47; i>0; i--){
    if (keyPressed == 32){
      draw((char *)bullet, 1, 1, 24, i);
      if (i<3){
        draw((char *)explode, 3, 3, 23, 0);
      }
    }
  }
}


