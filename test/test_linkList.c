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
  int x = 20;
  int y = 39;
  listElement *pThis;
  pThis = createdlistElement(x, y);
  
  TEST_ASSERT_EQUAL(20, pThis->coorX);
  TEST_ASSERT_EQUAL(39, pThis->coorY);
  TEST_ASSERT_EQUAL(0, pThis->indexNum);
  TEST_ASSERT_EQUAL(NULL, pThis->next);
}

void test_add_a_new_element(void){
  listElement *pElement;
  linkList *pLink;
  int x = 24, y = 31;
  
  pLink = createdLinkList();
  pElement = createdlistElement(x, y);
  addList(pElement, pLink);
  
  TEST_ASSERT_EQUAL(pElement, pLink->tail);
  TEST_ASSERT_EQUAL(pElement, pLink->head);
  TEST_ASSERT_EQUAL(1, pElement->indexNum);
  TEST_ASSERT_EQUAL(NULL, pElement->next);
}

void test_add_two_new_element(void){
  listElement *pElement1, *pElement2, *pElement3;
  linkList *pLink;
  int x1 = 12, y1 = 15;
  int x2 = 34, y2 = 51;
  int x3 = 22, y3 = 41;
  
  pLink = createdLinkList();
  pElement1 = createdlistElement(x1, y1);
  addList(pElement1, pLink);
  pElement2 = createdlistElement(x2, y2);
  addList(pElement2, pLink);
  pElement3 = createdlistElement(x3, y3);
  addList(pElement3, pLink);
  
  TEST_ASSERT_EQUAL(pElement1, pLink->head);
  TEST_ASSERT_EQUAL(pElement2, pLink->head->next);
  TEST_ASSERT_EQUAL(pElement3, pLink->tail);
  TEST_ASSERT_EQUAL(1, pElement1->indexNum);
  TEST_ASSERT_EQUAL(2, pElement2->indexNum);
  TEST_ASSERT_EQUAL(3, pElement3->indexNum);
  TEST_ASSERT_EQUAL(NULL, pElement3->next);
}

void test_LinkedList_given_an_array_6_7_8_9_should_return_head_as_6_and_tail_as_9(){
  linkList *pLL = createdLinkList();
  int i;
  int num[] = {6, 7, 8, 9};
  
  for (i=0; i<4; i++){
    addList(createdlistElement(num[i], (num[i]-1)), pLL);
  }
  
  TEST_ASSERT_EQUAL(6, pLL->head->coorX);
  TEST_ASSERT_EQUAL(5, pLL->head->coorY);
  TEST_ASSERT_EQUAL(7, pLL->head->next->coorX);
  TEST_ASSERT_EQUAL(6, pLL->head->next->coorY);
  TEST_ASSERT_EQUAL(8, pLL->head->next->next->coorX);
  TEST_ASSERT_EQUAL(7, pLL->head->next->next->coorY);
  TEST_ASSERT_EQUAL(9, pLL->tail->coorX);
  TEST_ASSERT_EQUAL(8, pLL->tail->coorY);
  TEST_ASSERT_NULL (pLL->tail->next);
}

void test_delete_first_node_from_a_link_list(void){
  listElement *pElement1, *pElement2, *pElement3;
  linkList *pLink;
  
  pLink = createdLinkList();
  pElement1 = createdlistElement(12, 15);
  addList(pElement1, pLink);
  pElement2 = createdlistElement(22, 25);
  addList(pElement2, pLink);
  pElement3 = createdlistElement(31, 36);
  addList(pElement3, pLink);
  
  deleteFirstNode(pElement1, pLink);
  
  TEST_ASSERT_EQUAL(3, pLink->length);
  TEST_ASSERT_EQUAL(22, pLink->head->coorX);
  TEST_ASSERT_EQUAL(25, pLink->head->coorY);
  TEST_ASSERT_EQUAL(31, pLink->head->next->coorX);
  TEST_ASSERT_EQUAL(36, pLink->head->next->coorY);
  TEST_ASSERT_EQUAL(2, pLink->head->indexNum);
  TEST_ASSERT_EQUAL(3, pLink->head->next->indexNum);
}

void test_delete_third_node_from_a_link_list_of_five_nodes(void){
  listElement *pElement1, *pElement2, *pElement3, *pElement4, *pElement5;
  linkList *pLink;
  
  pLink = createdLinkList();
  pElement1 = createdlistElement(4, 1);
  addList(pElement1, pLink);
  pElement2 = createdlistElement(8, 9);
  addList(pElement2, pLink);
  pElement3 = createdlistElement(13, 15);
  addList(pElement3, pLink);
  pElement4 = createdlistElement(22, 28);
  addList(pElement4, pLink);
  pElement5 = createdlistElement(35, 32);
  addList(pElement5, pLink);
  
  printf("node 1 : %d, %d\n", pLink->head->coorX, pLink->head->coorY);
  printf("node 2 : %d, %d\n", pLink->head->next->coorX, pLink->head->next->coorY);
  printf("node 3 : %d, %d\n", pLink->head->next->next->coorX, pLink->head->next->next->coorY);
  printf("node 4 : %d, %d\n", pLink->head->next->next->next->coorX, pLink->head->next->next->next->coorY);
  printf("node 5 : %d, %d\n\n", pLink->tail->coorX, pLink->tail->coorY);
  
  deleteOneNode(pElement3, pLink);
  
  printf("node 1 : %d, %d\n", pLink->head->coorX, pLink->head->coorY);
  printf("node 2 : %d, %d\n", pLink->head->next->coorX, pLink->head->next->coorY);
  printf("node 3 : %d, %d\n", pLink->head->next->next->coorX, pLink->head->next->next->coorY);
  printf("node 4 : %d, %d\n", pLink->tail->coorX, pLink->tail->coorY);
  
  TEST_ASSERT_EQUAL(5, pLink->length);
  TEST_ASSERT_EQUAL(4, pLink->head->coorX);
  TEST_ASSERT_EQUAL(1, pLink->head->coorY);
  TEST_ASSERT_EQUAL(8, pLink->head->next->coorX);
  TEST_ASSERT_EQUAL(9, pLink->head->next->coorY);
  TEST_ASSERT_EQUAL(22, pLink->head->next->next->coorX);
  TEST_ASSERT_EQUAL(28, pLink->head->next->next->coorY);
}

void test_delete_last_node_from_a_link_list_of_four_nodes(void){
  listElement *pElement1, *pElement2, *pElement3, *pElement4, *pElement5;
  linkList *pLink;
  
  pLink = createdLinkList();
  pElement1 = createdlistElement(1, 2);
  addList(pElement1, pLink);
  pElement2 = createdlistElement(11, 22);
  addList(pElement2, pLink);
  pElement3 = createdlistElement(33, 44);
  addList(pElement3, pLink);
  pElement4 = createdlistElement(55, 66);
  addList(pElement4, pLink);
  
  printf("\nnode 1 : %d, %d\n", pLink->head->coorX, pLink->head->coorY);
  printf("node 2 : %d, %d\n", pLink->head->next->coorX, pLink->head->next->coorY);
  printf("node 3 : %d, %d\n", pLink->head->next->next->coorX, pLink->head->next->next->coorY);
  printf("node 4 : %d, %d\n", pLink->tail->coorX, pLink->tail->coorY);
  
  deleteLastNode(pElement4, pLink);
  
  printf("node 1 : %d, %d\n", pLink->head->coorX, pLink->head->coorY);
  printf("node 2 : %d, %d\n", pLink->head->next->coorX, pLink->head->next->coorY);
  printf("node 3 : %d, %d\n", pLink->tail->coorX, pLink->tail->coorY);
  
  TEST_ASSERT_EQUAL(4, pLink->length);
  TEST_ASSERT_EQUAL(1, pLink->head->coorX);
  TEST_ASSERT_EQUAL(2, pLink->head->coorY);
  TEST_ASSERT_EQUAL(11, pLink->head->next->coorX);
  TEST_ASSERT_EQUAL(22, pLink->head->next->coorY);
  TEST_ASSERT_EQUAL(33, pLink->tail->coorX);
  TEST_ASSERT_EQUAL(44, pLink->tail->coorY);
}




