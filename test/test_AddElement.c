#include "unity.h"
#include "AddElement.h"
#include "linkList.h"
#include <malloc.h>
#include "BlockDiagram.h"

void setUp(void){}

void tearDown(void){}

void test_createEnemy_Element(void){
  char alien1[][3] = {{" ^ "},
                      {" @ "},
                      {"* *"}};
  int width = 3, height = 3;
  int x = 20, y = 39;
  
  enemyElement *pThis;
  pThis = createEnemy((char *)alien1, 3, 3, 20, 39);
  TEST_ASSERT_EQUAL_PTR(alien1, pThis->diagram);  
  TEST_ASSERT_EQUAL(3, pThis->width);
  TEST_ASSERT_EQUAL(3, pThis->height);
  TEST_ASSERT_EQUAL(20, pThis->coorX);
  TEST_ASSERT_EQUAL(39, pThis->coorY);
  TEST_ASSERT_EQUAL(0, pThis->indexNum);
  TEST_ASSERT_EQUAL(NULL, pThis->next);
  }
  
void test_add_list_enemy(void){
  enemyElement *pThis, *pThisSecond;
  linkList *pLink;
  char alien1[][3] = {{" ^ "},
                      {" @ "},
                      {"* *"}};
                        
  pLink = createdLinkList();
  pThis = createEnemy((char *)alien1, 3, 3, 16, 12);
  addList((listElement *)pThis, pLink); 
  pThisSecond = createEnemy((char *)alien1, 5, 4, 2, 42);
  addList((listElement *)pThisSecond, pLink); 
  enemyElement* pEnemy = (enemyElement*)pLink->head; 

  TEST_ASSERT_EQUAL(pThisSecond, pLink->tail);
  TEST_ASSERT_EQUAL(pThis, pLink->head);
  TEST_ASSERT_EQUAL(1, (listElement *)pThis->indexNum);
  TEST_ASSERT_EQUAL(2, (listElement *)pThisSecond->indexNum);
  TEST_ASSERT_EQUAL_PTR(alien1,pEnemy->diagram);
  TEST_ASSERT_EQUAL(3, pEnemy->width);
  TEST_ASSERT_EQUAL(3, pEnemy->height);
  TEST_ASSERT_EQUAL(16, pEnemy->coorX);
  TEST_ASSERT_EQUAL(12, pEnemy->coorY);
  TEST_ASSERT_EQUAL(5, pEnemy->next->width);
  TEST_ASSERT_EQUAL(4, pEnemy->next->height);
  TEST_ASSERT_EQUAL(42, pEnemy->next->coorY);
  TEST_ASSERT_EQUAL(2, pEnemy->next->coorX);
  TEST_ASSERT_EQUAL(pThisSecond, (listElement *)pThis->next);
  TEST_ASSERT_EQUAL(NULL, (listElement *)pThisSecond->next);
}


void test_add_two_enemy_element(void){
enemyElement *pThis, *pThisSecond;
  linkList *pLink;
  char alien1[][3] = {{" ^ "},
                      {" @ "},
                      {"* *"}};
  int i;
  int width = 3, height = 3;
  int x = 3, y = 9;  
  pLink = createdLinkList();

  for(i = 1; i<3; i++){
   addList((listElement *)(createEnemy((char *)alien1, width, height, i*(x+width), y)), pLink); 
  }
  enemyElement* pEnemy = (enemyElement*)pLink->head; 

 
  TEST_ASSERT_EQUAL(1,  pEnemy->indexNum);
  TEST_ASSERT_EQUAL(2,  pEnemy->next->indexNum);
  TEST_ASSERT_EQUAL_PTR(alien1,pEnemy->diagram);
  TEST_ASSERT_EQUAL(3, pEnemy->width);
  TEST_ASSERT_EQUAL(3, pEnemy->height);
  TEST_ASSERT_EQUAL(6, pEnemy->coorX);
  TEST_ASSERT_EQUAL(9, pEnemy->coorY);
  TEST_ASSERT_EQUAL(3, pEnemy->next->width);
  TEST_ASSERT_EQUAL(3, pEnemy->next->height);
  TEST_ASSERT_EQUAL(9, pEnemy->next->coorY);
  TEST_ASSERT_EQUAL(12, pEnemy->next->coorX);
  TEST_ASSERT_EQUAL(NULL, pEnemy->next->next);
}

void test_createEnemy_ElementList_fuction(void){
  linkList *pLinkEnemy;

  char alien1[][3] = {{" ^ "},
                      {" @ "},
                      {"* *"}};
                      
  int width = 3, height = 3;
  int x = -2, y = 16; 
  pLinkEnemy = createEnemyList((char *)alien1, width, height, x, y);  
  transferImageToConsole();
  enemyElement *pElementEnemy = (enemyElement*)pLinkEnemy->head; 

  TEST_ASSERT_EQUAL(pElementEnemy,  pLinkEnemy->head);
  TEST_ASSERT_EQUAL(1, pElementEnemy->indexNum);
  TEST_ASSERT_EQUAL_PTR(alien1,pElementEnemy->diagram);
  TEST_ASSERT_EQUAL_PTR(alien1,pElementEnemy->next->next->next->next->next->next->next->next->next->diagram);
  TEST_ASSERT_EQUAL(2, pElementEnemy->next->indexNum);
  TEST_ASSERT_EQUAL(10, pElementEnemy->next->next->next->next->next->next->next->next->next->indexNum);
  TEST_ASSERT_EQUAL(3, pElementEnemy->next->next->next->next->next->next->next->next->next->width);
  TEST_ASSERT_EQUAL(3, pElementEnemy->width);
  TEST_ASSERT_EQUAL(3, pElementEnemy->height);
  TEST_ASSERT_EQUAL(4, pElementEnemy->coorX);
  TEST_ASSERT_EQUAL(16, pElementEnemy->coorY);  
  TEST_ASSERT_EQUAL(8, pElementEnemy->next->coorX);
  TEST_ASSERT_EQUAL(16, pElementEnemy->next->coorY);
  TEST_ASSERT_EQUAL(40, pElementEnemy->next->next->next->next->next->next->next->next->next->coorX);
}



