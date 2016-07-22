#ifndef FSM_H
#define FSM_H
#include <time.h>
#include <windows.h>
#include <stdint.h>
#include "Action.h"

#define BUTTON_PRESSED   1
#define BUTTON_RELEASED  0

#define KEY_LEFT  75
#define KEY_UP    72
#define KEY_RIGHT 77
#define KEY_DOWN  80
#define KEY_SPACEBAR 32


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
  Image *image;
  int coorX;
  int coorY;
  double timeInterval;
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
char relativeMoveImage(SpaceShip *pShip, int deltaXImage, int deltaYImage);
char relativeMoveBullet(Ammo *pBullet, int deltaXBullet, int deltaYBullet);
void keyboardFSM(keyboardPressed *thisKey);
void movementShipFSM(movementShip *thisMove);
uint32_t getSystemTime();
void movementAmmoFSM(movementShip *thisState);

#endif // FSM_H


