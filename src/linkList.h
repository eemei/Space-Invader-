#ifndef linkList_H
#define linkList_H
#include <stdio.h>
#include <malloc.h>

typedef struct listElement listElement;
  struct listElement{
  int coorX;
  int coorY;
  char *image;
  int height;
  int width;
  listElement *next;
};

typedef struct linkList linkList;
struct linkList {
  listElement *head;
  listElement *tail;
};

linkList *createdLinkList();
listElement *createdlistElement(int coordinateX, int coordinateY);
void addList(listElement *newElement, linkList *newlinkElement);
// void deleteList(listElement *element, linkList *link, int x, int y);
#endif // linkList_H
