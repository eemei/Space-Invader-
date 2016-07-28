#include "linkList.h"

linkList *createdLinkList(){
  linkList *plinkList = malloc(sizeof(linkList));
  plinkList->head = NULL;
  plinkList->tail = NULL;
  plinkList->length = 0;
  return plinkList;
}

listElement *createdlistElement(int coordinateX, int coordinateY){
  listElement *plistElement = malloc(sizeof(listElement));
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
      link->head->coorX = link->head->next->coorX;
      link->head->coorY = link->head->next->coorY;
      link->head->indexNum = link->head->next->indexNum;
      link->head->next = link->head->next->next;
      firstElement = NULL;
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
    while(tempNode != element) {
      tempNode = tempNode->next;
    }   
    
    if(link->head->next == NULL) {
      printf("\n Given node is not present in Linked List");
      return;
    }
    
    tempNode->coorX = tempNode->next->coorX;
    tempNode->coorY = tempNode->next->coorY;
    tempNode->indexNum = tempNode->next->indexNum;
    tempNode = tempNode->next;
    
    element = NULL;
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
    
    link->tail->coorX = tempNode->coorX;
    link->tail->coorY = tempNode->coorY;
    link->tail->indexNum = tempNode->indexNum;
    
    lastElement = NULL;
  }
}

