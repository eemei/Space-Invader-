#ifndef AddElement_H
#define AddElement_H
#include "linkList.h"
#include <malloc.h>
#include "BlockDiagram.h"

typedef struct Enemy Enemy;
struct Enemy{
  char *diagram;
  int width;
  int height;
  int coorX;
  int coorY; 
};

typedef struct enemyElement enemyElement;
  struct enemyElement{
    int indexNum;
    enemyElement *next;
    char *diagram;
    int width;
    int height;
    int coorX;
    int coorY; 
  };



enemyElement *createEnemy(char *image, int width, int height, int coorX, int coorY);
linkList *createEnemyList(char *image, int width, int height, int coorX, int coorY);

#endif // AddElement_H

