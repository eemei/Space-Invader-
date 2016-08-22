#ifndef FSM_H
#define FSM_H

#include <time.h>
#include <windows.h>
#include <stdint.h>
#include "linkList.h"
#include "AddElement.h"
#include "BlockDiagram.h"
#include "keyboard.h"

#define BUTTON_PRESSED   1
#define BUTTON_RELEASED  0

#define KEY_LEFT  75
#define KEY_UP    72
#define KEY_RIGHT 77
#define KEY_DOWN  80
#define KEY_SPACEBAR 32

#define BULLETTIMEINTERVAL 25

#define SHIPCOORX 44
#define SHIPCOORY 47

#define BULLETCOORX 45
#define BULLETCOORY 46

#define BORDERLIMITLEFTX   0
#define BORDERLIMITRIGHTX  77

#define BORDERLIMITTOPY    0   
#define BORDERLIMITBOTTOMY 47   

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
  EXPLODE1,
  EXPLODE2,
  EXPLODE3
}explode;

typedef enum{
  INITLIFE,
  WAITLIFE,
  MINUSLIFE
}life;

typedef enum{
  MISSSHOT,
  EXPLODEALIEN,
  TARGETSHOT
}mark;


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
  int life;
  int shot;
};

typedef struct Explosion Explosion;
struct Explosion{
  Image *explodePicture;
  int coorX;
  int coorY;
};

typedef struct {
  moveShip moveShipState;
  moveAmmo moveAmmoState;
  explode explodeState;
  keyboardPressed *keyboard;
  moveAlien moveAlienState;
  life lifeState;
  mark markState;
  SpaceShip *ship;
  Ammo *bullet;
  Explosion *alien;
}movementShip;

keyboardPressed *initiateKeyboardState();
Image *initiateImage();
Ammo *initiateAmmo();
SpaceShip *initiateSpaceShip();
Explosion *initiateExplosion();
movementShip *initiateMovementState();
int getKbCode();
char relativeMoveImage(SpaceShip *pShip, int deltaXImage, int deltaYImage);
char relativeMoveBullet(Ammo *pBullet, int deltaXBullet, int deltaYBullet);
void keyboardFSM(keyboardPressed *thisKey);
void movementShipFSM(movementShip *thisMove);
uint32_t getSystemTime();
void movementAmmoFSM(movementShip *thisState);
void alienFSM(movementShip *enemy);
int explodeSequenceFSM(movementShip *thisEnemy, enemyElement *element);
void lifeFSM(movementShip *thisLife);
void scoreSystem(char grade);
void getHitFSM(movementShip * thisHit, linkList *thisLink);

#endif // FSM_H


