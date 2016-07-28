#ifndef linkList_H
#define linkList_H
#include <stdio.h>
#include <malloc.h>

typedef struct listElement listElement;
struct listElement{
  int coorX;
  int coorY;
  int indexNum;
  listElement *next;
};

typedef struct linkList linkList;
struct linkList {
  listElement *head;
  listElement *tail;
  int length;
};

linkList *createdLinkList();
listElement *createdlistElement(int coordinateX, int coordinateY);
void addList(listElement *newElement, linkList *newlinkElement);
void deleteFirstNode(listElement *firstElement, linkList *link);
void deleteOneNode(listElement *element, linkList *link);
void deleteLastNode(listElement *lastElement, linkList *link);

#endif // linkList_H
