#include <stdio.h>
#include <stdlib.h>
#include "FSM.h"
#include "BlockDiagram.h"
#include "linkList.h"
#include "main.h"

// This is the real main program for Space Invaders.
int main(void){
  movementShip *pShip = initiateMovementState();
  movementShip *pAmmo = initiateMovementState();
  
  pShip->moveShipState = START;
  pAmmo->moveAmmoState = STARTBULLET;
  while (1){
    pAmmo->ship->coordinateX = pShip->ship->coordinateX;
    pAmmo->ship->coordinateY = pShip->ship->coordinateY;
    movementShipFSM(pShip);
    movementAmmoFSM(pAmmo);
    transferImageToConsole();
    refreshCursor(6400);
  }
  return 1;
}