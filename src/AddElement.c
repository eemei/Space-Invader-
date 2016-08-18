#include <stdlib.h>
#include <stdio.h>
#include "AddElement.h"
#include "linkList.h"

enemyElement *createEnemy(char *image, int width, int height, int coorX, int coorY){
  enemyElement *thisEnemy = malloc(sizeof(enemyElement));
  thisEnemy->diagram = image;
  thisEnemy->width = width;
  thisEnemy->height = height;
  thisEnemy->coorX = coorX;
  thisEnemy->coorY = coorY;
  thisEnemy->indexNum = 0;
  thisEnemy->next = NULL;
  return thisEnemy;
}

linkList *createEnemyList(char *image, int width, int height, int coorX, int coorY){
  linkList *pLink = createdLinkList();
  printf ("start head = %d \n", pLink->head);
  int i;
  
  for (i = 1; i<11; i++){
    addList((listElement *)(createEnemy(image, width, height, i*(coorX+width+3), coorY)), pLink); 
    draw(image, width, height, i*(coorX+width+3), coorY);
  }

  return pLink;
}