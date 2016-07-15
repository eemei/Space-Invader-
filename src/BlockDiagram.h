#ifndef BlockDiagram_H
#define BlockDiagram_H

char displayAlien1();
void displayAlien2();
void displayAlien3();
void displayAlien4();
void displayPlanet();
void displayShip();
void displayShelter();
void bufferFiller(int row, int col, char symbol);
void bufferFillerWithSpace(int row, int col, char symbol);
int jumper(int bufferRange, int coor, int range);
void draw (char *image, int width, int length, int coorX, int coorY);
void transferImageToConsole();
void maskOutImage(int x, int y, int height, int width);
#endif // BlockDiagram_H
