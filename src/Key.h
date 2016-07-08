#ifndef Key_H
#define Key_H

#define KEY_LEFT  75
#define KEY_UP    72
#define KEY_RIGHT 77
#define KEY_DOWN  80
#define FIRE      32
#define ESC       27

int escKey();
int fireBullet();

int moveShipLeftRight();
int gotoXY(int x, int y);

int continuPress();

#endif // Key_H
