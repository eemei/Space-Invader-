#include <stdlib.h>
#include <stdio.h>
#include "FSM.h"

void movementShipFSM(movementShip *this){
  volatile int ch;
  switch (this->state) {
    case START:
      this->coordinateX = 24;
      this->coordinateY = 47;
      this->state = RELEASE;
      break;
    case RELEASE:
      // if (this->kbPressed = kbhit()) {
      if (getKbPressed(this->kbPressed) == BUTTON_PRESSED) {
        ch = getch();
        if (ch == 0 || ch == 224 ) {
          ch = getch();
          this->direction = ch;
        }
        this->state = PRESSED;
      }
      else {
        this->state = RELEASE;
      }
      break;
    case PRESSED:
      if (getKbCodeLeft(this->direction) == KEY_LEFT){
        this->coordinateX = this->coordinateX - 1;
        this->coordinateY = this->coordinateY;
      }
      else if (getKbCodeRight(this->direction) == KEY_RIGHT){
        this->coordinateX = this->coordinateX + 1;
        this->coordinateY = this->coordinateY;
      }
      else{
        this->coordinateX = this->coordinateX;
        this->coordinateY = this->coordinateY;
      }
      this->state = RELEASE;
      break;
    default: this->state = START;
  }
}

movementShip *initiateState(){
  movementShip *this = malloc(sizeof(movementShip));
  this->state = START;
  this->direction = 0;;
  this->coordinateX = 0;
  this->coordinateY = 0;
  this->kbPressed = 0;
  return this;
}