#ifndef linkList_H
#define linkList_H
#include <stdio.h>
#include <malloc.h>

typedef struct listElement listElement;
struct listElement{
  char *diagram;
  int width;
  int height;
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
listElement *createdlistElement(char *image, int width, int height, int coordinateX, int coordinateY);
void addList(listElement *newElement, linkList *newlinkElement);
void deleteFirstNode(listElement *firstElement, linkList *link);
void deleteOneNode(listElement *element, linkList *link);
void deleteLastNode(listElement *lastElement, linkList *link);

#endif // linkList_H
