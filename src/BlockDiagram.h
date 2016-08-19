#ifndef BlockDiagram_H
#define BlockDiagram_H
#include <stdio.h>
#include <time.h>

#define BUFFERROW 80
#define BUFFERCOL 80

char displayAlien1();
void displayAlien2();
void displayAlien3();
void displayAlien4();
void displayPlanet();
void displayShip();
void displayShelter();
void bufferFiller(int row, int col, char symbol);
int jumper(int bufferRange, int coor, int range);
void draw (char *image, int width, int length, int coorX, int coorY);
void transferImageToConsole();
void maskOutImage(int coorX, int coorY, int width, int height);
void refreshCursor(int num);

#endif // BlockDiagram_H
