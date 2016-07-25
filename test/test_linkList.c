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
  TEST_ASSERT_EQUAL(NULL, pThis->next);
}

void test_add_new_element(void){
  listElement *pElement;
  linkList *pLink;
  int x = 24, y = 31;
  
  pLink = createdLinkList();
  pElement = createdlistElement(x, y);
  addList(pElement, pLink);
  
  TEST_ASSERT_EQUAL(pElement, pLink->tail);
  TEST_ASSERT_EQUAL(pElement, pLink->head);
  TEST_ASSERT_EQUAL(NULL, pElement->next);
}

void test_add_on_new_element(void){
  listElement *pElement1, *pElement2;
  linkList *pLink;
  int x1 = 12, y1 = 15;
  int x2 = 34, y2 = 51;
  
  pLink = createdLinkList();
  pElement1 = createdlistElement(x1, y1);
  addList(pElement1, pLink);
  pElement2 = createdlistElement(x2, y2);
  addList(pElement2, pLink);
  
  TEST_ASSERT_EQUAL(pElement2, pLink->tail);
  TEST_ASSERT_EQUAL(pElement1, pLink->head);
  TEST_ASSERT_EQUAL(NULL, pElement2->next);
}

// void test_delete_list(void){
  // listElement *pElement;
  // linkList *pLink;
  // int xSerach = 12, ySearch = 15;
  // int x = 12, y = 15;
  
  // pLink = createdLinkList();
  // pElement = createdlistElement(x, y);
  // addList(pElement, pLink);
  // // deleteList(pElement, pLink, xSerach, ySearch);
// }