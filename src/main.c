#include <stdio.h>
#include <stdlib.h>
#include "FSM.h"
#include "BlockDiagram.h"
#include "linkList.h"
#include "main.h"

int main(void){
  movementShip *pShip = initiateMovementState();
  pShip->moveShipState = START;
  while (1){
    movementAmmoFSM(pShip);
    movementShipFSM(pShip);
    transferImageToConsole();
    // refresh(6400);
  }
  return 1;
}