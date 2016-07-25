#include "linkList.h"

linkList *createdLinkList(){
  linkList *plinkList = malloc(sizeof(linkList));
  plinkList->head = NULL;
  plinkList->tail = NULL;
  
  return plinkList;
}

listElement *createdlistElement(int coordinateX, int coordinateY){
  listElement *plistElement = malloc(sizeof(listElement));
  plistElement->coorX = coordinateX;
  plistElement->coorY = coordinateY;
  plistElement->next = NULL;
  
  return plistElement;
}

void addList(listElement *newElement, linkList *newlinkElement){
  
  if (newElement == NULL){
    printf("error\n");
    return;
  }
  
  if (newlinkElement->tail == NULL && newlinkElement->head == NULL){
    newlinkElement->head = newElement;
    newlinkElement->tail = newElement;
    newElement->next = NULL;
    printf ("x = %d, y =%d\n", newElement->coorX, newElement->coorY);
  }
  
  else{
    newlinkElement->tail = newElement;
    printf ("x = %d, y =%d\n", newElement->coorX, newElement->coorY);
    newlinkElement->tail = newElement;
  }
}

