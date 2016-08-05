#include <stdlib.h>
#include <stdio.h>
#include "linkList.h"

linkList *createdLinkList(){
  linkList *plinkList = malloc(sizeof(linkList));
  plinkList->head = NULL;
  plinkList->tail = NULL;
  plinkList->length = 0;
  return plinkList;
}

listElement *createdlistElement(char *image, int width, int height, int coordinateX, int coordinateY){
  listElement *plistElement = malloc(sizeof(listElement));
  plistElement->diagram = image;
  plistElement->width = width;
  plistElement->height = height;
  plistElement->coorX = coordinateX;
  plistElement->coorY = coordinateY;
  plistElement->indexNum = 0;
  plistElement->next = NULL;
  return plistElement;
}

void addList(listElement *newElement, linkList *newlinkElement){
  
  if (newElement == NULL){
    printf("error\n");
    return;
  }
  
  if (newlinkElement->head == NULL && newlinkElement->tail == NULL){
    newlinkElement->head = newElement;
    newlinkElement->tail = newElement;
  }
  else{
    newlinkElement->tail->next = newElement;
    newlinkElement->tail = newElement;
  }
  (newlinkElement->length)++;
  newElement->indexNum = newlinkElement->length;
}

void deleteFirstNode(listElement *firstElement, linkList *link){
  if (link->head == NULL && link->tail == NULL){
    firstElement = NULL;
    printf("No node needs to be freed");
  }
  else {
    if (link->head->next == NULL){
      link->head = NULL;
      link->tail = NULL;
    }
    else{
      link->head->diagram = link->head->next->diagram;
      link->head->width = link->head->next->width;
      link->head->height = link->head->next->height;
      link->head->coorX = link->head->next->coorX;
      link->head->coorY = link->head->next->coorY;
      link->head->indexNum = link->head->next->indexNum;
      link->head = link->head->next;

      free(firstElement);
    }
  }
}

void deleteOneNode(listElement *element, linkList *link){
  listElement *tempNode;
  tempNode = link->head;
  
  if (link->head == NULL && link->tail == NULL){
    element = NULL;
    printf("No node needs to be freed");
  }
  else{
    while(tempNode->next != element) {
      tempNode = tempNode->next;
    }   
    
    if(tempNode->next == NULL) {
      printf("\n Given node is not present in the Linked List");
      return;
    }
    
    tempNode->next->diagram = tempNode->next->next->diagram;
    tempNode->next->width = tempNode->next->next->width;
    tempNode->next->height = tempNode->next->next->height;
    tempNode->next->coorX = tempNode->next->next->coorX;
    tempNode->next->coorY = tempNode->next->next->coorY;
    tempNode->next->indexNum = tempNode->next->next->indexNum;
    tempNode->next = tempNode->next->next;
    
    free(element);
  }
}

void deleteLastNode(listElement *lastElement, linkList *link){
  listElement *tempNode;
  tempNode = link->head;
  
  if (link->head == NULL && link->tail == NULL){
    lastElement = NULL;
    printf("\nNo node needs to be freed\n");
  }
  else{
    while(tempNode->next != lastElement) {
      tempNode = tempNode->next;
    }
    
    if(link->head->next == NULL) {
      printf("\n Given node is not present in Linked List\n");
      return;
    }
    
    link->tail->diagram = tempNode->diagram;
    link->tail->width = tempNode->width;
    link->tail->height = tempNode->height;
    link->tail->coorX = tempNode->coorX;
    link->tail->coorY = tempNode->coorY;
    link->tail->indexNum = tempNode->indexNum;
    link->tail = tempNode;
    
    free(lastElement);
  }
}

