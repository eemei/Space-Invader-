#include <stdlib.h>
#include <stdio.h>
#include "FSM.h"
#include "BlockDiagram.h"

keyboardPressed *initiateKeyboardState(){
  keyboardPressed *thisKey = malloc(sizeof(keyboardPressed));
  thisKey->buttonState = BUTTONNOHIT;
  thisKey->escCode = 0;
  return thisKey;
}

Image *initiateImage(){
  Image *pImage = malloc(sizeof(Image));
  pImage->picture = NULL;
  pImage->height = 0;
  pImage->width = 0;
  return pImage;
}

Ammo *initiateAmmo(){
  Ammo *pAmmo = malloc(sizeof(Ammo));
  pAmmo->whichAmmo = NULL;
  pAmmo->coorX = 0;
  pAmmo->coorY = 0;
  pAmmo->timeInterval = 0;
  return pAmmo;
}

SpaceShip *initiateSpaceShip(){
  SpaceShip *pShip = malloc(sizeof(SpaceShip));
  pShip->image = initiateImage();
  pShip->coordinateX = 0;
  pShip->coordinateY = 0;
  return pShip;
}

movementShip *initiateMovementState(){
  movementShip *pThis = malloc(sizeof(movementShip));
  pThis->moveShipState = START;
  pThis->keyboard = initiateKeyboardState();
  pThis->ship = initiateSpaceShip();
  pThis->kbPressed = 0;
  return pThis;
}

char relativeMoveImage(SpaceShip *pShip, int deltaX, int deltaY){
  int newCoorX, newCoorY;
  
  newCoorX = pShip->coordinateX + deltaX;
  newCoorY = pShip->coordinateY + deltaY;
  
  if (newCoorX > 47){
    newCoorX = 47;
  }
  else if (newCoorX <= 0){
    newCoorX = 0;
  }
  else{
    newCoorX = newCoorX;
    newCoorY = newCoorY;
  }
  
  maskOutImage(pShip->coordinateX, pShip->coordinateY, pShip->image->width, pShip->image->height);
  pShip->coordinateX = newCoorX;
  pShip->coordinateY = newCoorY;
  draw(pShip->image->picture, pShip->image->width, pShip->image->height, pShip->coordinateX, pShip->coordinateY);
}

void keyboardFSM(keyboardPressed *thisKey){
  int ch;
  
  switch(thisKey->buttonState){
    case BUTTONNOHIT:
      thisKey->escCode = thisKey->escCode;
      thisKey->buttonState = BUTTONHIT;
      break;
    case BUTTONHIT:
      ch = getch();
      if (ch == 0 || ch == 224 ) {
        ch = getch();
      }
      thisKey->escCode = ch;
      break;
    default: thisKey->buttonState = BUTTONNOHIT;
  }
}

void movementShipFSM(movementShip *thisMove){
  volatile int ch;
  switch (thisMove->moveShipState) {
    case START:
      thisMove->ship->coordinateX = 24;
      thisMove->ship->coordinateY = 47;
      thisMove->moveShipState = RELEASE;
      break;
    case RELEASE:
      if (getKbPressed(thisMove->kbPressed) == BUTTON_PRESSED) {
        thisMove->keyboard->buttonState = BUTTONHIT;
        keyboardFSM(thisMove->keyboard);
        thisMove->moveShipState = PRESSED;
      }
      else {
        thisMove->keyboard->buttonState = BUTTONNOHIT;
        keyboardFSM(thisMove->keyboard);
        thisMove->moveShipState = RELEASE;
      }
      break;
    case PRESSED:
      if (getKbCodeLeft(thisMove->keyboard->escCode) == KEY_LEFT){
        relativeMoveImage(thisMove->ship, -1, 0);
      }
      else if (getKbCodeRight(thisMove->keyboard->escCode) == KEY_RIGHT){
        relativeMoveImage(thisMove->ship, 1, 0);
      }
      else{
        relativeMoveImage(thisMove->ship, 0, 0);
      }
      thisMove->moveShipState = RELEASE;
      break;
    default: thisMove->moveShipState = START;
  }
}
 
