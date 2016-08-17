#ifndef linkList_H
#define linkList_H
#include <stdio.h>
#include <malloc.h>

typedef struct linkList linkList;
typedef struct listElement listElement;

struct listElement{
  int indexNum;
  listElement *next;
  void *data;
};

struct linkList{
  listElement *head;
  listElement *tail;
  int length;
};


linkList *createdLinkList();
listElement *createdElement();
void addList(listElement *newElement, linkList *newlinkElement);
void deleteFirstNode(listElement *firstElement, linkList *link);
void deleteOneNode(listElement *element, linkList *link);
void deleteLastNode(listElement *lastElement, linkList *link);

#endif // linkList_H
