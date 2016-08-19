#include <stdlib.h>
#include <stdio.h>
#include "linkList.h"

/*
 *  @brief This function is to initialize 
 *         the structure of linkList.
 *
 *  @return *plinkList
 */
linkList *createdLinkList(){
  linkList *plinkList = malloc(sizeof(linkList));
  plinkList->head = NULL;
  plinkList->tail = NULL;
  plinkList->length = 0;
  return plinkList;
}

/*
 *  @brief This function is to initialize 
 *         the structure of listElement.
 *
 *  @return *thisElement
 */
listElement *createdElement(){
  listElement *thisElement = malloc(sizeof(listElement));
  thisElement->indexNum = 0;
  thisElement->next = NULL;
  return thisElement;
}

/*
 *  @brief This function is to link the linklist and listElement
 *         and form a list whenever a new element added to the list.
 *
 */
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

/*
 *  @brief This function is to delete the first 
 *         node of the linked list and free it.
 */
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
      link->head->indexNum = link->head->next->indexNum;
      link->head = link->head->next;

      free(firstElement);
    }
  }
}

/*
 *  @brief This function is to delete a node 
 *         of the linked list and free it.
 *
 *  @except first and last node
 */
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
    
    tempNode->next = tempNode->next->next;
    
    free(element);
  }
}

/*
 *  @brief This function is to delete the last 
 *         node of the linked list and free it.
 */
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
    

    link->tail->indexNum = tempNode->indexNum;
    link->tail = tempNode;
    
    free(lastElement);
  }
}


