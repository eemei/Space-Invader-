#include "unity.h"
#include "linkList.h"

void setUp(void){}

void tearDown(void){}

void test_created_link_list(void){
  linkList *pThis = createdLinkList();
  
  TEST_ASSERT_EQUAL(NULL, pThis->tail);
  TEST_ASSERT_EQUAL(NULL, pThis->head);
}

void test_add_a_new_element(void){
  listElement *pElement;
  linkList *pLink;
  
  pLink = createdLinkList();
  pElement = createdElement();
  addList(pElement, pLink);
   
  TEST_ASSERT_EQUAL(pElement, pLink->tail);
  TEST_ASSERT_EQUAL(pElement, pLink->head);
  TEST_ASSERT_EQUAL(1, pElement->indexNum);
  TEST_ASSERT_EQUAL(NULL, pElement->next);
}

void test_created_list_element(void){

  listElement *pThis;
  pThis = createdElement();
  
  TEST_ASSERT_EQUAL(0, pThis->indexNum);
  TEST_ASSERT_EQUAL(NULL, pThis->next);
}

void test_add_three_elements(void){
  listElement *pElement1, *pElement2, *pElement3;
  linkList *pLink;
  
  pLink = createdLinkList();
  pElement1 = createdElement();
  addList(pElement1, pLink);
  pElement2 = createdElement();
  addList(pElement2, pLink);
  pElement3 = createdElement();
  addList(pElement3, pLink);

  TEST_ASSERT_EQUAL(pElement1, pLink->head);
  TEST_ASSERT_EQUAL(pElement2, pLink->head->next);
  TEST_ASSERT_EQUAL(pElement3, pLink->tail);
  TEST_ASSERT_EQUAL(1, pElement1->indexNum);
  TEST_ASSERT_EQUAL(2, pElement2->indexNum);
  TEST_ASSERT_EQUAL(3, pElement3->indexNum);
  TEST_ASSERT_EQUAL(NULL, pElement3->next);
}

void test_delete_first_node_from_a_link_list(void){
  listElement *pElement1, *pElement2, *pElement3;
  linkList *pLink;

  pLink = createdLinkList();
  pElement1 = createdElement();
  addList(pElement1, pLink);
  pElement2 = createdElement();
  addList(pElement2, pLink);
  pElement3 = createdElement();
  addList(pElement3, pLink);
  
  deleteFirstNode(pElement1, pLink);
  
  TEST_ASSERT_EQUAL(pElement2, pLink->head);
  TEST_ASSERT_EQUAL(pElement3, pLink->tail);
  TEST_ASSERT_EQUAL(3, pLink->length);
  TEST_ASSERT_EQUAL(2, pLink->head->indexNum);
  TEST_ASSERT_EQUAL(3, pLink->tail->indexNum);
}

void test_delete_third_node_from_a_link_list_of_five_nodes(void){
  listElement *pElement1, *pElement2, *pElement3, *pElement4, *pElement5;
  linkList *pLink;
  

  pLink = createdLinkList();
  pElement1 = createdElement();
  addList(pElement1, pLink);
  pElement2 = createdElement();
  addList(pElement2, pLink);
  pElement3 = createdElement();
  addList(pElement3, pLink);
  pElement4 = createdElement();
  addList(pElement4, pLink);
  pElement5 = createdElement();
  addList(pElement5, pLink);
  
  printf("node 1 :  %d, %p\n", pLink->head->indexNum, pElement1);
  printf("node 2 :  %d, %p\n",  pLink->head->next->indexNum, pElement2);
  printf("node 3 :  %d, %p\n", pLink->head->next->next->indexNum, pElement3);
  printf("node 4 :  %d, %p\n", pLink->head->next->next->next->indexNum,  pElement4);
  printf("node 5 :  %d, %p\n\n", pLink->tail->indexNum,  pElement5);
  
  deleteOneNode(pElement3, pLink);
  
  printf("node 1 :  %d, %p\n", pLink->head->indexNum, pElement1);
  printf("node 2 :  %d, %p\n",  pLink->head->next->indexNum, pElement2);
  printf("node 3 :  %d, %p\n", pLink->head->next->next->indexNum, pElement3);
  printf("node 4 :  %d, %p\n", pLink->head->next->next->next->indexNum,  pElement4);
  printf("node 5 :  %d, %p\n\n", pLink->tail->indexNum,  pElement5);
  
  TEST_ASSERT_EQUAL(5, pLink->length);
 
  TEST_ASSERT_EQUAL(pElement1, pLink->head);
  TEST_ASSERT_EQUAL(pElement2, pLink->head->next);
  TEST_ASSERT_EQUAL(pElement4, pLink->head->next->next);
  TEST_ASSERT_EQUAL(pElement5, pLink->tail);
  TEST_ASSERT_EQUAL(1, pLink->head->indexNum);
  TEST_ASSERT_EQUAL(2, pLink->head->next->indexNum);
  TEST_ASSERT_EQUAL(4, pLink->head->next->next->indexNum);
  TEST_ASSERT_EQUAL(5, pLink->tail->indexNum);
}

void test_delete_last_node_from_a_link_list_of_four_nodes(void){
  listElement *pElement1, *pElement2, *pElement3, *pElement4, *pElement5;
  linkList *pLink;
  

  pLink = createdLinkList();
  pElement1 = createdElement();
  addList(pElement1, pLink);
  pElement2 = createdElement();
  addList(pElement2, pLink);
  pElement3 = createdElement();
  addList(pElement3, pLink);
  pElement4 = createdElement();
  addList(pElement4, pLink);
  
  printf("node 1 :  %d, %p\n", pLink->head->indexNum, pElement1);
  printf("node 2 :  %d, %p\n",  pLink->head->next->indexNum, pElement2);
  printf("node 3 :  %d, %p\n", pLink->head->next->next->indexNum, pElement3);
  printf("node 4 :  %d, %p\n", pLink->head->next->next->next->indexNum,  pElement4);
  
  deleteLastNode(pElement4, pLink);
  
  printf("node 1 :  %d, %p\n", pLink->head->indexNum, pElement1);
  printf("node 2 :  %d, %p\n",  pLink->head->next->indexNum, pElement2);
  printf("node 3 :  %d, %p\n", pLink->head->next->next->indexNum, pElement3);

  
  TEST_ASSERT_EQUAL(4, pLink->length);
  TEST_ASSERT_EQUAL(1, pLink->head->indexNum);
  TEST_ASSERT_EQUAL(2, pLink->head->next->indexNum);
  TEST_ASSERT_EQUAL(3, pLink->tail->indexNum);
}

