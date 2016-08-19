#include <stdlib.h>
#include <stdio.h>
#include "AddElement.h"
#include "linkList.h"

/*
 *  @brief This function is to initialize 
 *         the structure of enemyElement.
 *
 *  @return *thisEnemy
 */
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

/*
 *  @brief This function is to create a list
 *         of enemies in linked list form.
 *
 *  @return *pLink - to indicate the type of linked list
 */
linkList *createEnemyList(char *image, int width, int height, int coorX, int coorY){
  linkList *pLink = createdLinkList();
  int i;
  
  for (i = 1; i<11; i++){
    addList((listElement *)(createEnemy(image, width, height, i*(coorX+width+3), coorY)), pLink); 
    draw(image, width, height, i*(coorX+width+3), coorY);
  }

  return pLink;
}


enemyElement *search(linkList *pLink, int coorX, int coorY){
  enemyElement* pEnemy = (enemyElement*)pLink->head; 
  while(pEnemy != NULL){
    if (pEnemy->coorX == coorX && pEnemy->coorY == coorY){
      printf("key found\n");
      return pEnemy;
    }
    pEnemy = pEnemy->next;
  }
   printf("Key not found\n");
   return 0;
}
