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
}moveShip;

typedef enum{
  BUTTONNOHIT,
  BUTTONHIT
}keyboardButton;

typedef struct keyboardPressed keyboardPressed;
struct keyboardPressed{
  keyboardButton buttonState;
  int escCode;
};

typedef struct Image Image;
struct Image{
  char *picture;
  int height;
  int width;
};

typedef struct Ammo Ammo;
struct Ammo{
  char *whichAmmo;
  int coorX;
  int coorY;
  int timeInterval;
};

typedef struct SpaceShip SpaceShip;
struct SpaceShip{
  Image *image;
  int coordinateX;
  int coordinateY;
};

typedef struct {
  moveShip moveShipState;
  keyboardPressed *keyboard;
  SpaceShip *ship;
  int kbPressed;
}movementShip;

keyboardPressed *initiateKeyboardState();
Image *initiateImage();
Ammo *initiateAmmo();
SpaceShip *initiateSpaceShip();
movementShip *initiateMovementState();
char relativeMoveImage(SpaceShip *pShip, int deltaX, int deltaY);
void keyboardFSM(keyboardPressed *thisKey);
void movementShipFSM(movementShip *thisMove);

#endif // FSM_H


