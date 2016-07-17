#ifndef FSM_H
#define FSM_H
#include <time.h>
#include "Action.h"

#define BUTTON_PRESSED   1
#define BUTTON_RELEASED  0

#define KEY_LEFT  75
#define KEY_UP    72
#define KEY_RIGHT 77
#define KEY_DOWN  80
#define KEY_SPACE 32


typedef enum {
  START,
  RELEASE,
  PRESSED
}moveShip;

typedef enum {
  STARTBullet,
  RELEASEBullet,
  PRESSEDBullet,
  MOVEBULLETONESTEP
}moveAmmo;

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
  double recordedTime;
};

typedef struct SpaceShip SpaceShip;
struct SpaceShip{
  Image *image;
  int coordinateX;
  int coordinateY;
};

typedef struct {
  moveShip moveShipState;
  moveAmmo moveAmmoState;
  keyboardPressed *keyboard;
  SpaceShip *ship;
  Ammo *bullet;
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
// void moveAmmo(Ammo *moveAmmo);
//int getTIME ();
void movementAmmoFSM(movementShip *thisState);
#endif // FSM_H


