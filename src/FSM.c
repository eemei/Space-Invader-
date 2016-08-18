#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "FSM.h"
#include "BlockDiagram.h"
#include "keyboard.h"
#include "AddElement.h"
#include "linkList.h"

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

const char spaceShip[][3] = {{" T "},
                             {"[+]"}};
                         
const char shelter[][5] = {{"-----"},
                           {"|[+]|"},
                           {"-----"}};

const char explode1[][4] = {{" {} "},
                            {"{  }"}};
                          
const char explode2[][5] = {{" ( ) "},
                            {"(   )"}};
                           
const char explode3[][6] = {{" <  > "},
                            {"<    >"}};
                           
const char bullet[] = {"|"};

keyboardPressed *initiateKeyboardState(){
  keyboardPressed *thisKey = malloc(sizeof(keyboardPressed));
  thisKey->buttonState = BUTTONNOHIT;
  thisKey->kbPressed = 0;
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
  pShip->life = 0;
  pShip->shot = 0;
  return pShip;
}

Explosion *initiateExplosion(){
  Explosion *pEnemy = malloc(sizeof(Explosion));
  pEnemy->explodePicture = initiateImage();
  pEnemy->coorX = 0;
  pEnemy->coorY = 0;
  return pEnemy;
}

movementShip *initiateMovementState(){
  movementShip *pThis = malloc(sizeof(movementShip));
  pThis->moveShipState = START;
  pThis->moveAmmoState = STARTBULLET;
  pThis->explodeState = EXPLODE1;
  pThis->alien = initiateExplosion();
  pThis->keyboard = initiateKeyboardState();
  pThis->moveAlienState = MOVELEFT;
  pThis->ship = initiateSpaceShip();
  pThis->bullet = initiateAmmo();
  return pThis;
}

int getKbCode(movementShip *thisCode){
  return thisCode->keyboard->escCode;
}

char relativeMoveImage(SpaceShip *pShip, int deltaXImage, int deltaYImage){
  int newCoorX, newCoorY;
  
  newCoorX = pShip->coordinateX + deltaXImage;
  newCoorY = pShip->coordinateY + deltaYImage;
  
  if (newCoorX > BORDERLIMITRIGHTX){
    newCoorX = BORDERLIMITRIGHTX;
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
    // pBullet->coorX = newCoorX;
    // pBullet->coorY = newCoorY;
    // maskOutImage(pBullet->coorX, pBullet->coorY, pBullet->image->width, pBullet->image->height);
  }
  else{
    newCoorX = newCoorX;
    newCoorY = newCoorY;
    // maskOutImage(pBullet->coorX, pBullet->coorY, pBullet->image->width, pBullet->image->height);
    // pBullet->coorX = newCoorX;
    // pBullet->coorY = newCoorY;
    // draw(pBullet->image->picture, pBullet->image->width, pBullet->image->height, pBullet->coorX, pBullet->coorY);
  }
  
  maskOutImage(pBullet->coorX, pBullet->coorY, pBullet->image->width, pBullet->image->height);
  pBullet->coorX = newCoorX;
  pBullet->coorY = newCoorY;
  draw(pBullet->image->picture, pBullet->image->width, pBullet->image->height, pBullet->coorX, pBullet->coorY);
}

 
uint32_t getSystemTime(){
  SYSTEMTIME st;
  
  GetSystemTime(&st);
  // printf("time :%d/%d/%d  %d:%d:%d %d\n",st.wDay,st.wMonth,st.wYear, st.wHour, st.wMinute, st.wSecond , st.wMilliseconds);
 
  return (st.wSecond * 1000) + st.wMilliseconds;
}

/*
 *    @brief This is the FSM of keyboard
 *           that reacts with specific key pressed.
 *    @aug   keyboardPressed *thisKey
 *
 */

void keyboardFSM(keyboardPressed *thisKey){
  int ch;
  
  switch(thisKey->buttonState){
    case BUTTONNOHIT:
      thisKey->escCode = thisKey->escCode;
      thisKey->kbPressed = 0;
      thisKey->buttonState = BUTTONHIT;
      break;
    case BUTTONHIT:
      ch = _getch();
      if (ch == 0 || ch == 224 ) {
        ch = _getch();
      }
      thisKey->escCode = ch;
      thisKey->kbPressed = 1;
      break;
    default: thisKey->buttonState = BUTTONNOHIT;
  }
}

void movementShipFSM(movementShip *thisMove){
  volatile int keyCode;
  switch (thisMove->moveShipState) {
    case START:
      thisMove->ship->image->picture = (char *)spaceShip;
      thisMove->ship->image->width = 3;
      thisMove->ship->image->height = 2;
      thisMove->ship->coordinateX = SHIPCOORX;
      thisMove->ship->coordinateY = SHIPCOORY;
      thisMove->ship->life = 3;
      draw(thisMove->ship->image->picture, thisMove->ship->image->width, thisMove->ship->image->height, thisMove->ship->coordinateX, thisMove->ship->coordinateY);
      thisMove->moveShipState = RELEASE;
      break;
    case RELEASE:
      if ((thisMove->keyboard->kbPressed = _kbhit()) == BUTTON_PRESSED) {
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
      if (getKbCode(thisMove) == KEY_LEFT){
        relativeMoveImage(thisMove->ship, -1, 0);
      }
      else if (getKbCode(thisMove) == KEY_RIGHT){
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

void movementAmmoFSM(movementShip *thisAmmo){
  switch (thisAmmo->moveAmmoState) {
    case STARTBULLET:
      thisAmmo->bullet->image->picture = (char *)bullet;
      thisAmmo->bullet->image->width = 1;
      thisAmmo->bullet->image->height = 1;
      thisAmmo->bullet->coorX = thisAmmo->ship->coordinateX+1;
      thisAmmo->bullet->coorY = thisAmmo->ship->coordinateY-1;
      thisAmmo->bullet->timeInterval = 250; // 250ms 
      thisAmmo->bullet->recordedTime = 0;
      thisAmmo->moveAmmoState = RELEASEBULLET;
      break;
    case RELEASEBULLET:
      if ((thisAmmo->keyboard->kbPressed = _kbhit()) == BUTTON_PRESSED) {
        thisAmmo->keyboard->buttonState = BUTTONHIT;
        keyboardFSM(thisAmmo->keyboard);
        thisAmmo->moveAmmoState = PRESSEDBULLET;
      }
      else {
        thisAmmo->keyboard->buttonState = BUTTONNOHIT;
        keyboardFSM(thisAmmo->keyboard);
        thisAmmo->moveShipState = RELEASEBULLET;
      }
      break;
    case PRESSEDBULLET:
      if (getKbCode(thisAmmo) == KEY_SPACEBAR){
        thisAmmo->bullet->recordedTime = getSystemTime();
        thisAmmo->moveAmmoState = MOVEBULLETONESTEP;
      }
      else{
        thisAmmo->bullet->recordedTime = 0;
        thisAmmo->moveAmmoState = RELEASEBULLET;
      }
      break;
    case MOVEBULLETONESTEP:
      if (getSystemTime() - (thisAmmo->bullet->recordedTime) >= thisAmmo->bullet->timeInterval){
        thisAmmo->bullet->recordedTime = getSystemTime();
        relativeMoveBullet(thisAmmo->bullet, 0, -1);
        thisAmmo->moveAmmoState = MOVEBULLETONESTEP;
      }
      else {
        relativeMoveBullet(thisAmmo->bullet, 0, 0);
        thisAmmo->moveAmmoState = MOVEBULLETONESTEP;
      }
      break;
    default: thisAmmo->moveShipState = STARTBULLET;
  }
}

void alienFSM(movementShip *enemy){
  switch (enemy->moveAlienState){
    case MOVERIGHT:
      if (enemy->ship->coordinateX<=BORDERLIMITRIGHTX){
        relativeMoveImage(enemy->ship, 1, 0);
        enemy->moveAlienState = MOVERIGHT;
      }
      else
        enemy->moveAlienState = MOVEDOWN;
      break;
    case MOVEDOWN:
      relativeMoveImage(enemy->ship, 0, 1);
      if (enemy->ship->coordinateX>=BORDERLIMITRIGHTX)
        enemy->moveAlienState = MOVELEFT;
      else
        enemy->moveAlienState = MOVERIGHT;
      break;
    case MOVELEFT:
      if (enemy->ship->coordinateX>=0){
        relativeMoveImage(enemy->ship, -1, 0);
        enemy->moveAlienState = MOVELEFT;
      }
      else
        enemy->moveAlienState = MOVEDOWN;
      break;
    default: relativeMoveImage(enemy->ship, 0, 0);
  }
}

int explodeSequenceFSM(movementShip *thisEnemy, enemyElement *element){
  switch (thisEnemy->explodeState) {
    case EXPLODE1:
      thisEnemy->alien->coorX = element->coorX;
      thisEnemy->alien->coorY = element->coorY;
      draw(thisEnemy->alien->explodePicture->picture, thisEnemy->alien->explodePicture->width, thisEnemy->alien->explodePicture->height, thisEnemy->alien->coorX, thisEnemy->alien->coorY);
      thisEnemy->explodeState = EXPLODE2;
      break;
    case EXPLODE2:
      thisEnemy->alien->coorX = element->coorX;
      thisEnemy->alien->coorY = element->coorY;
      draw(thisEnemy->alien->explodePicture->picture, thisEnemy->alien->explodePicture->width, thisEnemy->alien->explodePicture->height, thisEnemy->alien->coorX, thisEnemy->alien->coorY);
      thisEnemy->explodeState = EXPLODE3;   
      break;
    case EXPLODE3:
      thisEnemy->alien->coorX = element->coorX;
      thisEnemy->alien->coorY = element->coorY;
      draw(thisEnemy->alien->explodePicture->picture, thisEnemy->alien->explodePicture->width, thisEnemy->alien->explodePicture->height, thisEnemy->alien->coorX, thisEnemy->alien->coorY);
      return 1;
      break;
    default: thisEnemy->explodeState = EXPLODE1;
  }
}


void lifeFSM(movementShip *thisLife){
  switch(thisLife->lifeState){
    case INITLIFE:
      thisLife->ship->life = 3;
      thisLife->lifeState = WAITLIFE;
      break;
    case WAITLIFE: 
      if (thisLife->keyboard->kbPressed)
        thisLife->lifeState = MINUSLIFE;
      else 
        thisLife->lifeState = WAITLIFE;
      break;
    case MINUSLIFE:
      if (thisLife->ship->shot){
        (thisLife->ship->life)--;
      }
      thisLife->lifeState = WAITLIFE;
      break;
    default: thisLife->lifeState = INITLIFE;
  }
}

void getHitFSM(movementShip * thisHit, linkList *thisLink){
  enemyElement *pKill;
  enemyElement* thisEnemy = (enemyElement*)thisLink->head;
  switch(thisHit->markState){
    case TARGETSHOT:
      pKill = search(thisLink, thisHit->bullet->coorX, thisHit->bullet->coorY);
       if (pKill != 0)
        thisHit->markState = EXPLODEALIEN;
       else 
         thisHit->markState = MISSSHOT;
      break;
     
    case EXPLODEALIEN:
      if (explodeSequenceFSM(thisHit, pKill) == 1)
        deleteOneNode((listElement *)pKill, thisLink);
      else
        thisHit->markState = TARGETSHOT;
      break;
    
    case MISSSHOT:
      printf ("miss\n");
      break;
    default: thisHit->markState = MISSSHOT;
  }
}
 
