#include "FSM.h"
#include "Key.h"
#include "BlockDiagram.h"

void movementShipFSM(movementShipState *this){
  int ch;
  switch (this->state) {
    case START:
      this->coordinateX = 24;
      this->coordinateY = 47;
      this->state = RELEASE;
      break;
    case RELEASE:
      if (this->kbPressed = kbhit()) {
        ch = getch();
        if (ch == 0 || ch == 224 ) {
          this->whichDirection = getch();
        }
      }
      this->state = PRESSED;
      break;
    case PRESSED:
      if (this->whichDirection == KEY_LEFT){
        this->coordinateX = this->coordinateX - 1;
        this->coordinateY = this->coordinateY;
      }
      else if (this->whichDirection == KEY_RIGHT){
        this->coordinateX = this->coordinateX + 1;
        this->coordinateY = this->coordinateY;
      }
      this->state = RELEASE;
      break;
  }
}