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
}moveStateMachine;

typedef enum{
  BUTTONNOHIT,
  BUTTONHIT
}keyboardButton;

typedef struct {
  keyboardButton buttonState;
  int direction;
}keyboardPressed;

typedef struct Image Image;
struct Image{
  char *picture;
  int height;
  int width;
};

typedef struct SpaceShip SpaceShip;
struct SpaceShip{
  Image *image;
  int coordinateX;
  int coordinateY;
};

typedef struct {
  moveStateMachine state;
  keyboardPressed *keyboard;
  SpaceShip *ship;
  int kbPressed;
}movementShip;

movementShip *initiateMovementState();
keyboardPressed *initiateKeyboardState();
void keyboardFSM(keyboardPressed *thisKey);
void movementShipFSM(movementShip *thisMove);
char relativeMoveImage(SpaceShip *pShip, int deltaX, int deltaY);

#endif // FSM_H


