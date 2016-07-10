#ifndef FSM_H
#define FSM_H

#include "Action.h"

#define BUTTON_PRESSED   1
#define BUTTON_RELEASED  0

#define KEY_LEFT  75
#define KEY_UP    72
#define KEY_RIGHT 77
#define KEY_DOWN  80

typedef enum {
  START,
  RELEASE,
  PRESSED
}StateMachine;

typedef struct {
  StateMachine state;
  int direction;
  int coordinateX;
  int coordinateY;
  int kbPressed;
}movementShip;

void movementShipFSM(movementShip *this);
movementShip *initiateState();

#endif // FSM_H


