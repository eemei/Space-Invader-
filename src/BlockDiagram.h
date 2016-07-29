#ifndef BlockDiagram_H
#define BlockDiagram_H
#include <stdio.h>
#include <time.h>

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
double waitStage(double sec);
void exploreSequence(char *image1, char *image2, char *image3, int width, int length, int coorX, int coorY);
// int qwe();
void sequenceExplode(char *image1, int width, int length, int coorX, int coorY);
#endif // BlockDiagram_H
