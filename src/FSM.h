#ifndef FSM_H
#define FSM_H
#include <time.h>
#include <windows.h>
#include <stdint.h>

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
  STARTBULLET,
  RELEASEBULLET,
  PRESSEDBULLET,
  MOVEBULLETONESTEP
}moveAmmo;

typedef enum{
  BUTTONNOHIT,
  BUTTONHIT
}keyboardButton;

typedef enum{
  MOVELEFT,
  MOVERIGHT,
  MOVEDOWN
}moveAlien;

typedef enum{
  INITIALIZE,
  EXPLODE1,
  EXPLODE2,
  EXPLODE3,
  RETURNTOAMMO
}explode;

typedef struct keyboardPressed keyboardPressed;
struct keyboardPressed{
  keyboardButton buttonState;
  int kbPressed;
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

typedef struct IntTime IntTime;
struct IntTime{
  double timeInt;
  double recordTime;
};

typedef struct {
  moveShip moveShipState;
  moveAmmo moveAmmoState;
  explode explodeState;
  keyboardPressed *keyboard;
  moveAlien moveAlienState;
  SpaceShip *ship;
  Ammo *bullet;
  Image *image;
  IntTime *timeData;
}movementShip;

keyboardPressed *initiateKeyboardState();
Image *initiateImage();
Ammo *initiateAmmo();
SpaceShip *initiateSpaceShip();
movementShip *initiateMovementState();
int getKbPressed();
int getKbCode();
char relativeMoveImage(SpaceShip *pShip, int deltaXImage, int deltaYImage);
char relativeMoveBullet(Ammo *pBullet, int deltaXBullet, int deltaYBullet);
void keyboardFSM(keyboardPressed *thisKey);
void movementShipFSM(movementShip *thisMove);
uint32_t getSystemTime();
void movementAmmoFSM(movementShip *thisState);
void alienFSM(movementShip *enemy);
int explodeSequenceFSM(movementShip *thisEnemy, listElement *list);
IntTime *initialTime();

#endif // FSM_H


