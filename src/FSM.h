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

typedef enum{
  BUTTONNOHIT,
  BUTTONHIT
}keyboardButton;

typedef struct {
  keyboardButton buttonState;
  int direction;
}keyboardPressed;

typedef struct {
  StateMachine state;
  keyboardPressed *keyboard;
  int coordinateX;
  int coordinateY;
  int kbPressed;
}movementShip;

movementShip *initiateMovementState();
keyboardPressed *initiateKeyboardState();
void keyboardFSM(keyboardPressed *thisKey);
void movementShipFSM(movementShip *thisMove);

#endif // FSM_H


