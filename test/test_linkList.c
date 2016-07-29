#include "unity.h"
#include "linkList.h"

void setUp(void){}

void tearDown(void){}

void test_created_link_list(void){
  linkList *pThis = createdLinkList();
  
  TEST_ASSERT_EQUAL(NULL, pThis->tail);
  TEST_ASSERT_EQUAL(NULL, pThis->head);
}

void test_created_list_element(void){
  char alien1[][3] = {{" ^ "},
                      {" @ "},
                      {"* *"}};
  int width = 3, height = 3;
  int x = 20, y = 39;
  listElement *pThis;
  pThis = createdlistElement((char *)alien1, width, height, x, y);
  
  TEST_ASSERT_EQUAL_PTR(alien1, pThis->diagram);  
  TEST_ASSERT_EQUAL(3, pThis->width);
  TEST_ASSERT_EQUAL(3, pThis->height);
  TEST_ASSERT_EQUAL(20, pThis->coorX);
  TEST_ASSERT_EQUAL(39, pThis->coorY);
  TEST_ASSERT_EQUAL(0, pThis->indexNum);
  TEST_ASSERT_EQUAL(NULL, pThis->next);
}

void test_add_a_new_element(void){
  listElement *pElement;
  linkList *pLink;
  
  char alien1[][3] = {{" ^ "},
                      {" @ "},
                      {"* *"}};
  int width = 3, height = 3;
  int x = 24, y = 31;
  
  pLink = createdLinkList();
  pElement = createdlistElement((char *)alien1, width, height, x, y);
  addList(pElement, pLink);
  
  TEST_ASSERT_EQUAL_PTR(alien1, pLink->head->diagram);
  TEST_ASSERT_EQUAL_PTR(3, pLink->head->width);
  TEST_ASSERT_EQUAL_PTR(3, pLink->head->height);
  TEST_ASSERT_EQUAL_PTR(24, pLink->head->coorX);
  TEST_ASSERT_EQUAL_PTR(31, pLink->head->coorY);
  TEST_ASSERT_EQUAL(pElement, pLink->tail);
  TEST_ASSERT_EQUAL(pElement, pLink->head);
  TEST_ASSERT_EQUAL(1, pElement->indexNum);
  TEST_ASSERT_EQUAL(NULL, pElement->next);
}

void test_add_three_elements(void){
  listElement *pElement1, *pElement2, *pElement3;
  linkList *pLink;
  
  char alien1[][3] = {{" ^ "},
                      {" @ "},
                      {"* *"}};
  char alien2[][4] =  {{" ^^ "},
                       {" @@ "},
                       {"*  *"}};
  char alien3[][6] = {{" ^^^ "},
                      {" @@@ "},
                      {"* * *"}};
  int width1 = 3, height1 = 3;
  int width2 = 4, height2 = 3;
  int width3 = 5, height3 = 3;
  int x1 = 12, y1 = 15;
  int x2 = 34, y2 = 51;
  int x3 = 22, y3 = 41;
  
  pLink = createdLinkList();
  pElement1 = createdlistElement((char *)alien1, width1, height1, x1, y1);
  addList(pElement1, pLink);
  pElement2 = createdlistElement((char *)alien2, width2, height2, x2, y2);
  addList(pElement2, pLink);
  pElement3 = createdlistElement((char *)alien3, width3, height3, x3, y3);
  addList(pElement3, pLink);

  TEST_ASSERT_EQUAL(pElement1, pLink->head);
  TEST_ASSERT_EQUAL(pElement2, pLink->head->next);
  TEST_ASSERT_EQUAL(pElement3, pLink->tail);
  TEST_ASSERT_EQUAL_PTR(alien1, pLink->head->diagram);
  TEST_ASSERT_EQUAL_PTR(alien2, pLink->head->next->diagram);
  TEST_ASSERT_EQUAL_PTR(alien3, pLink->tail->diagram);
  TEST_ASSERT_EQUAL(width1, pLink->head->width);
  TEST_ASSERT_EQUAL(width2, pLink->head->next->width);
  TEST_ASSERT_EQUAL(width3, pLink->tail->width);
  TEST_ASSERT_EQUAL(height1, pLink->head->height);
  TEST_ASSERT_EQUAL(height2, pLink->head->next->height);
  TEST_ASSERT_EQUAL(height3, pLink->tail->height);
  TEST_ASSERT_EQUAL(x1, pLink->head->coorX);
  TEST_ASSERT_EQUAL(x2, pLink->head->next->coorX);
  TEST_ASSERT_EQUAL(x3, pLink->tail->coorX);
  TEST_ASSERT_EQUAL(y1, pLink->head->coorY);
  TEST_ASSERT_EQUAL(y2, pLink->head->next->coorY);
  TEST_ASSERT_EQUAL(y3, pLink->tail->coorY);
  TEST_ASSERT_EQUAL(1, pElement1->indexNum);
  TEST_ASSERT_EQUAL(2, pElement2->indexNum);
  TEST_ASSERT_EQUAL(3, pElement3->indexNum);
  TEST_ASSERT_EQUAL(NULL, pElement3->next);
}

void test_delete_first_node_from_a_link_list(void){
  listElement *pElement1, *pElement2, *pElement3;
  linkList *pLink;
  
  char alien1[][3] = {{" ^ "},
                      {" @ "},
                      {"* *"}};
  pLink = createdLinkList();
  pElement1 = createdlistElement((char *)alien1, 3, 3, 12, 15);
  addList(pElement1, pLink);
  pElement2 = createdlistElement((char *)alien1, 3, 3, 22, 25);
  addList(pElement2, pLink);
  pElement3 = createdlistElement((char *)alien1, 3, 3, 31, 36);
  addList(pElement3, pLink);
  
  deleteFirstNode(pElement1, pLink);
  
  TEST_ASSERT_EQUAL_PTR(alien1, pLink->head->diagram);
  TEST_ASSERT_EQUAL_PTR(alien1, pLink->tail->diagram);
  TEST_ASSERT_EQUAL(pElement2, pLink->head);
  TEST_ASSERT_EQUAL(pElement3, pLink->tail);
  TEST_ASSERT_EQUAL(3, pLink->length);
  TEST_ASSERT_EQUAL(3, pLink->head->width);
  TEST_ASSERT_EQUAL(3, pLink->tail->width);
  TEST_ASSERT_EQUAL(3, pLink->head->height);
  TEST_ASSERT_EQUAL(3, pLink->tail->height);
  TEST_ASSERT_EQUAL(22, pLink->head->coorX);
  TEST_ASSERT_EQUAL(25, pLink->head->coorY);
  TEST_ASSERT_EQUAL(31, pLink->tail->coorX);
  TEST_ASSERT_EQUAL(36, pLink->tail->coorY);
  TEST_ASSERT_EQUAL(2, pLink->head->indexNum);
  TEST_ASSERT_EQUAL(3, pLink->tail->indexNum);
}

void test_delete_third_node_from_a_link_list_of_five_nodes(void){
  listElement *pElement1, *pElement2, *pElement3, *pElement4, *pElement5;
  linkList *pLink;
  
  char alien1[][3] = {{" ^ "},
                      {" @ "},
                      {"* *"}};
  pLink = createdLinkList();
  pElement1 = createdlistElement((char *)alien1, 3, 3, 4, 1);
  addList(pElement1, pLink);
  pElement2 = createdlistElement((char *)alien1, 3, 3, 8, 9);
  addList(pElement2, pLink);
  pElement3 = createdlistElement((char *)alien1, 3, 3, 13, 15);
  addList(pElement3, pLink);
  pElement4 = createdlistElement((char *)alien1, 3, 3, 22, 28);
  addList(pElement4, pLink);
  pElement5 = createdlistElement((char *)alien1, 3, 3, 35, 32);
  addList(pElement5, pLink);
  
  printf("node 1 : %d, %d, %p\n", pLink->head->coorX, pLink->head->coorY, pElement1);
  printf("node 2 : %d, %d, %p\n", pLink->head->next->coorX, pLink->head->next->coorY, pElement2);
  printf("node 3 : %d, %d, %p\n", pLink->head->next->next->coorX, pLink->head->next->next->coorY, pElement3);
  printf("node 4 : %d, %d, %p\n", pLink->head->next->next->next->coorX, pLink->head->next->next->next->coorY, pElement4);
  printf("node 5 : %d, %d, %p\n\n", pLink->tail->coorX, pLink->tail->coorY, pElement5);
  
  deleteOneNode(pElement3, pLink);
  
  printf("node 1 : %d, %d, %p\n", pLink->head->coorX, pLink->head->coorY, pElement1);
  printf("node 2 : %d, %d, %p\n", pLink->head->next->coorX, pLink->head->next->coorY, pElement2);
  printf("node 4 : %d, %d, %p\n", pLink->head->next->next->coorX, pLink->head->next->next->coorY, pLink->head->next->next);
  printf("node 5 : %d, %d, %p\n", pLink->tail->coorX, pLink->tail->coorY, pLink->tail);
  
  TEST_ASSERT_EQUAL(5, pLink->length);
  TEST_ASSERT_EQUAL_PTR(alien1, pLink->head->diagram);
  TEST_ASSERT_EQUAL_PTR(alien1, pLink->head->next->diagram);
  TEST_ASSERT_EQUAL_PTR(alien1, pLink->head->next->next->diagram);
  TEST_ASSERT_EQUAL_PTR(alien1, pLink->tail->diagram);
  TEST_ASSERT_EQUAL(pElement1, pLink->head);
  TEST_ASSERT_EQUAL(pElement2, pLink->head->next);
  TEST_ASSERT_EQUAL(pElement4, pLink->head->next->next);
  TEST_ASSERT_EQUAL(pElement5, pLink->tail);
  TEST_ASSERT_EQUAL(3, pLink->head->width);
  TEST_ASSERT_EQUAL(3, pLink->head->next->width);
  TEST_ASSERT_EQUAL(3, pLink->head->next->next->width);
  TEST_ASSERT_EQUAL(3, pLink->tail->width);
  TEST_ASSERT_EQUAL(3, pLink->head->height);
  TEST_ASSERT_EQUAL(3, pLink->head->next->height);
  TEST_ASSERT_EQUAL(3, pLink->head->next->next->height);
  TEST_ASSERT_EQUAL(3, pLink->tail->height);
  TEST_ASSERT_EQUAL(4, pLink->head->coorX);
  TEST_ASSERT_EQUAL(1, pLink->head->coorY);
  TEST_ASSERT_EQUAL(8, pLink->head->next->coorX);
  TEST_ASSERT_EQUAL(9, pLink->head->next->coorY);
  TEST_ASSERT_EQUAL(22, pLink->head->next->next->coorX);
  TEST_ASSERT_EQUAL(28, pLink->head->next->next->coorY);
  TEST_ASSERT_EQUAL(35, pLink->tail->coorX);
  TEST_ASSERT_EQUAL(32, pLink->tail->coorY);
  TEST_ASSERT_EQUAL(1, pLink->head->indexNum);
  TEST_ASSERT_EQUAL(2, pLink->head->next->indexNum);
  TEST_ASSERT_EQUAL(4, pLink->head->next->next->indexNum);
  TEST_ASSERT_EQUAL(5, pLink->tail->indexNum);
}

void test_delete_last_node_from_a_link_list_of_four_nodes(void){
  listElement *pElement1, *pElement2, *pElement3, *pElement4, *pElement5;
  linkList *pLink;
  
  char alien1[][3] = {{" ^ "},
                      {" @ "},
                      {"* *"}};
  pLink = createdLinkList();
  pElement1 = createdlistElement((char *)alien1, 3, 3, 1, 2);
  addList(pElement1, pLink);
  pElement2 = createdlistElement((char *)alien1, 3, 3, 11, 22);
  addList(pElement2, pLink);
  pElement3 = createdlistElement((char *)alien1, 3, 3, 33, 44);
  addList(pElement3, pLink);
  pElement4 = createdlistElement((char *)alien1, 3, 3, 55, 66);
  addList(pElement4, pLink);
  
  printf("\nnode 1 : %d, %d, %p\n", pLink->head->coorX, pLink->head->coorY, pElement1);
  printf("node 2 : %d, %d, %p\n", pLink->head->next->coorX, pLink->head->next->coorY, pElement2);
  printf("node 3 : %d, %d, %p\n", pLink->head->next->next->coorX, pLink->head->next->next->coorY, pElement3);
  printf("node 4 : %d, %d, %p\n", pLink->tail->coorX, pLink->tail->coorY, pElement4);
  
  deleteLastNode(pElement4, pLink);
  
  printf("\nnode 1 : %d, %d, %p\n", pLink->head->coorX, pLink->head->coorY, pElement1);
  printf("node 2 : %d, %d, %p\n", pLink->head->next->coorX, pLink->head->next->coorY, pElement2);
  printf("node 3 : %d, %d, %p\n", pLink->tail->coorX, pLink->tail->coorY, pLink->tail);
  
  TEST_ASSERT_EQUAL(4, pLink->length);
  TEST_ASSERT_EQUAL_PTR(alien1, pLink->head->diagram);
  TEST_ASSERT_EQUAL_PTR(alien1, pLink->head->next->diagram);
  TEST_ASSERT_EQUAL_PTR(alien1, pLink->tail->diagram);
  TEST_ASSERT_EQUAL(3, pLink->head->width);
  TEST_ASSERT_EQUAL(3, pLink->head->next->width);
  TEST_ASSERT_EQUAL(3, pLink->tail->width);
  TEST_ASSERT_EQUAL(3, pLink->head->height);
  TEST_ASSERT_EQUAL(3, pLink->head->next->height);
  TEST_ASSERT_EQUAL(3, pLink->tail->height);
  TEST_ASSERT_EQUAL(1, pLink->head->coorX);
  TEST_ASSERT_EQUAL(2, pLink->head->coorY);
  TEST_ASSERT_EQUAL(11, pLink->head->next->coorX);
  TEST_ASSERT_EQUAL(22, pLink->head->next->coorY);
  TEST_ASSERT_EQUAL(33, pLink->tail->coorX);
  TEST_ASSERT_EQUAL(44, pLink->tail->coorY);
  TEST_ASSERT_EQUAL(1, pLink->head->indexNum);
  TEST_ASSERT_EQUAL(2, pLink->head->next->indexNum);
  TEST_ASSERT_EQUAL(3, pLink->tail->indexNum);
}




