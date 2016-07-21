#include <stdlib.h>
#include <stdio.h>
#include <time.h>
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
  pAmmo->image = initiateImage();
  pAmmo->coorX = 0;
  pAmmo->coorY = 0;
  pAmmo->timeInterval = 0;
  pAmmo->recordedTime = 0;
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
  pThis->bullet = initiateAmmo();
  pThis->kbPressed = 0;
  return pThis;
}

char relativeMoveImage(SpaceShip *pShip, int deltaXImage, int deltaYImage){
  int newCoorX, newCoorY;
  
  newCoorX = pShip->coordinateX + deltaXImage;
  newCoorY = pShip->coordinateY + deltaYImage;
  
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

char relativeMoveBullet(Ammo *pBullet, int deltaXBullet, int deltaYBullet){
  int newCoorX, newCoorY;
  
  newCoorX = pBullet->coorX + deltaXBullet;
  newCoorY = pBullet->coorY + deltaYBullet;
  
  if (newCoorY <= 0){
    newCoorY = 0;
  }
  else{
    newCoorX = newCoorX;
    newCoorY = newCoorY;
  }
  /*hit enemy explosion*/
  
  maskOutImage(pBullet->coorX, pBullet->coorY, pBullet->image->width, pBullet->image->height);
  pBullet->coorX = newCoorX;
  pBullet->coorY = newCoorY;
  draw(pBullet->image->picture, pBullet->image->width, pBullet->image->height, pBullet->coorX, pBullet->coorY);
}


// int getTIME (){
  // time_t time1;
  
  // time1 = time(NULL);
  // printf("time = %6.3f\n ", time1);
  
  // return time1;
// }

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

void movementAmmoFSM(movementShip *thisState){
  volatile int ch;
  switch (thisState->moveAmmoState) {
    case STARTBullet:
      thisState->bullet->coorX = thisState->ship->coordinateX;
      thisState->bullet->coorY = thisState->ship->coordinateY;
      thisState->bullet->timeInterval = 250;
      thisState->bullet->recordedTime = 0;
      thisState->moveAmmoState = RELEASEBullet;
      break;
    case RELEASEBullet:
      if (getKbPressed(thisState->kbPressed) == BUTTON_PRESSED) {
        thisState->keyboard->buttonState = BUTTONHIT;
        keyboardFSM(thisState->keyboard);
        thisState->moveAmmoState = PRESSEDBullet;
      }
      else {
        thisState->keyboard->buttonState = BUTTONNOHIT;
        keyboardFSM(thisState->keyboard);
        thisState->moveShipState = RELEASEBullet;
      }
      break;
    case PRESSEDBullet:
      if (getKbCodeSpace(thisState->keyboard->escCode) == KEY_SPACEBAR){
        thisState->bullet->recordedTime = getTIME();
        thisState->moveAmmoState = MOVEBULLETONESTEP;
      }
      else{
        thisState->bullet->recordedTime = 0;
        thisState->moveAmmoState = RELEASEBullet;
      }
      break;
    case MOVEBULLETONESTEP:
      if (getTIME() - (thisState->bullet->recordedTime) == thisState->bullet->timeInterval){
        thisState->bullet->recordedTime = getTIME();
        // thisState->bullet->coorY = thisState->bullet->coorY - 1;
        // thisState->bullet->coorX = thisState->bullet->coorX;
        relativeMoveBullet(thisState->bullet, 0, -1);
        thisState->moveAmmoState = MOVEBULLETONESTEP;
      }
      else {
        // thisState->bullet->coorY = thisState->bullet->coorY;
        // thisState->bullet->coorX = thisState->bullet->coorX;
        relativeMoveBullet(thisState->bullet, 0, 0);
        thisState->moveAmmoState = MOVEBULLETONESTEP;
      }
      break;
    default: thisState->moveShipState = STARTBullet;
  }
}
