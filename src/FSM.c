#include <stdlib.h>
#include <stdio.h>
#include "FSM.h"

keyboardPressed *initiateKeyboardState(){
  keyboardPressed *thisKey = malloc(sizeof(keyboardPressed));
  thisKey->buttonState = BUTTONNOHIT;
  thisKey->direction = 0;
  return thisKey;
}

movementShip *initiateMovementState(){
  movementShip *this = malloc(sizeof(movementShip));
  this->state = START;
  this->keyboard = initiateKeyboardState();
  this->image = NULL;
  this->coordinateX = 0;
  this->coordinateY = 0;
  this->kbPressed = 0;
  return this;
}

void keyboardFSM(keyboardPressed *thisKey){
  int ch;
  
  switch(thisKey->buttonState){
    case BUTTONNOHIT:
      thisKey->direction = thisKey->direction;
      thisKey->buttonState = BUTTONHIT;
      break;
    case BUTTONHIT:
      ch = getch();
      if (ch == 0 || ch == 224 ) {
        ch = getch();
        thisKey->direction = ch;
      }
      break;
    default: thisKey->buttonState = BUTTONNOHIT;
  }
}

int moveShipRelative(movementShip *pCoord, char *diagram, int deltaX, int deltaY){
  int newCoorX, newCoorY;
  
  //printf("new x= %d\n", pCoord->coordinateX); // strange bug
  //printf("new y= %d\n", pCoord->coordinateY);
  pCoord->image = diagram;
  newCoorX = pCoord->coordinateX + deltaX;
  newCoorY = pCoord->coordinateY + deltaY;
  if (newCoorX > 47){
    newCoorX = 47;
  }
  else if (newCoorX <= 0){
    newCoorX = 0;
  } 
  else if (newCoorY >= 47){
    newCoorY = 47;
  }
  else{
    newCoorX = newCoorX;
    newCoorY = newCoorY;
  }
    pCoord->coordinateX = newCoorX;
    pCoord->coordinateY = newCoorY;
}

void movementShipFSM(movementShip *thisMove){
  volatile int ch;
  switch (thisMove->state) {
    case START:
      thisMove->coordinateX = 24;
      thisMove->coordinateY = 47;
      thisMove->state = RELEASE;
      break;
    case RELEASE:
      // if (thisMove->kbPressed = kbhit()) {
      if (getKbPressed(thisMove->kbPressed) == BUTTON_PRESSED) {
        thisMove->keyboard->buttonState = BUTTONHIT;
        keyboardFSM(thisMove->keyboard);
        thisMove->state = PRESSED;
      }
      else {
        thisMove->keyboard->buttonState = BUTTONNOHIT;
        keyboardFSM(thisMove->keyboard);
        thisMove->state = RELEASE;
      }
      break;
    case PRESSED:
      if (getKbCodeLeft(thisMove->keyboard->direction) == KEY_LEFT){
        // moveShipRelative(thisMove->image, -1, 0);
        thisMove->coordinateX = thisMove->coordinateX - 1;
        thisMove->coordinateY = thisMove->coordinateY;
      }
      else if (getKbCodeRight(thisMove->keyboard->direction) == KEY_RIGHT){
        // moveShipRelative(thisMove->image, 1, 0);
        thisMove->coordinateX = thisMove->coordinateX + 1;
        thisMove->coordinateY = thisMove->coordinateY;
      }
      else{
        // moveShipRelative(thisMove->image, 0, 0);
        thisMove->coordinateX = thisMove->coordinateX;
        thisMove->coordinateY = thisMove->coordinateY;
      }
      thisMove->state = RELEASE;
      break;
    default: thisMove->state = START;
  }
}
 
