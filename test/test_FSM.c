#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "unity.h"
#include "FSM.h"
#include "BlockDiagram.h"

void setUp(void){}

void tearDown(void){}

void test_ship_initialized_coordination_return_X_twenty_four_and_Y_forty_seven(void){
  movementShip *pThis = initiateMovementState();
  
  pThis->moveShipState = START;
  movementShipFSM(pThis);
  
  TEST_ASSERT_EQUAL(24, pThis->ship->coordinateX);
  TEST_ASSERT_EQUAL(47, pThis->ship->coordinateY);
  TEST_ASSERT_EQUAL(RELEASE, pThis->moveShipState);
}

void test_keyboard_no_press_should_return_the_direction_zero(void){
  movementShip *pThis = initiateMovementState();
  int keyHit;
  
  pThis->moveShipState = RELEASE;
  while((keyHit = getKbPressed()) != 0); 
  pThis->keyboard->buttonState = BUTTONNOHIT;
  movementShipFSM(pThis);
  
  TEST_ASSERT_EQUAL(BUTTON_RELEASED, pThis->keyboard->escCode);
  TEST_ASSERT_EQUAL(BUTTONHIT, pThis->keyboard->buttonState);
  TEST_ASSERT_EQUAL(RELEASE, pThis->moveShipState);
}

void test_keyboard_press_left_should_return_the_direction_seventy_five(void){
  movementShip *pThis = initiateMovementState();
  int keyHit;
  pThis->moveShipState = RELEASE;
  while((keyHit = getKbPressed()) != 1); 
  pThis->keyboard->buttonState = BUTTONHIT;
  movementShipFSM(pThis);
  
  TEST_ASSERT_EQUAL(KEY_LEFT, pThis->keyboard->escCode);
  TEST_ASSERT_EQUAL(BUTTONHIT, pThis->keyboard->buttonState);
  TEST_ASSERT_EQUAL(PRESSED, pThis->moveShipState);
}

void test_keyboard_press_right_should_return_the_direction_seventy_seven(void){
  movementShip *pThis = initiateMovementState();
  int keyHit;
  
  pThis->moveShipState = RELEASE;
  pThis->keyboard->buttonState = BUTTONHIT;
  while((keyHit = getKbPressed()) != 1); 
  movementShipFSM(pThis);
  
  TEST_ASSERT_EQUAL(KEY_RIGHT, pThis->keyboard->escCode);
  TEST_ASSERT_EQUAL(BUTTONHIT, pThis->keyboard->buttonState);
  TEST_ASSERT_EQUAL(PRESSED, pThis->moveShipState);
}

void test_move_with_delta_x_positive_five_and_delta_y_negative_ten(void){
  movementShip *pThis = initiateMovementState();
  char spaceShip[][3] = {{" T "},
                         {"[+]"}};

  pThis->ship->image->picture = (char *)spaceShip;
  pThis->ship->image->height = 2;
  pThis->ship->image->width = 3;
  pThis->ship->coordinateX = 24;
  pThis->ship->coordinateY = 48;
  relativeMoveImage(pThis->ship, 0, 0);
  transferImageToConsole();
  relativeMoveImage(pThis->ship, 5, -10);
  transferImageToConsole();
  
  TEST_ASSERT_EQUAL(29, pThis->ship->coordinateX);
  TEST_ASSERT_EQUAL(38, pThis->ship->coordinateY);
}

void test_getKbCode_should_return_seventy_five_given_escCode_seventy_five(void){
  movementShip *thisCode = initiateMovementState();
  int code;
  
  thisCode->keyboard->escCode = 75;
  code = getKbCode(thisCode);
  TEST_ASSERT_EQUAL(75, code);
}

void test_keyboard_pressed_left_should_return_the_coordinateX_twenty_three(void){
  movementShip *pThis = initiateMovementState();
  
  pThis->ship->coordinateX = 24;
  pThis->ship->coordinateY = 47;
  pThis->keyboard->escCode = KEY_LEFT;
  pThis->moveShipState = PRESSED;
  movementShipFSM(pThis);
  
  TEST_ASSERT_EQUAL(23, pThis->ship->coordinateX);
  TEST_ASSERT_EQUAL(47, pThis->ship->coordinateY);
  TEST_ASSERT_EQUAL(RELEASE, pThis->moveShipState);
}

void test_keyboard_pressed_right_should_return_the_coordinateX_twenty_five(void){
  movementShip *pThis = initiateMovementState();
  
  pThis->ship->coordinateX = 24;
  pThis->ship->coordinateY = 47;
  pThis->keyboard->escCode = KEY_RIGHT;
  pThis->moveShipState = PRESSED;
  movementShipFSM(pThis);
  
  TEST_ASSERT_EQUAL(25, pThis->ship->coordinateX);
  TEST_ASSERT_EQUAL(47, pThis->ship->coordinateY);
  TEST_ASSERT_EQUAL(RELEASE, pThis->moveShipState);
}

void test_ammo_initialized_coordination_return_X_twenty_four_and_Y_forty_seven(void){
  movementShip *pThis = initiateMovementState();
  pThis->ship->coordinateX = 24;
  pThis->ship->coordinateY = 47;
  pThis->moveAmmoState = STARTBULLET;
  movementAmmoFSM(pThis);
  
  TEST_ASSERT_EQUAL(24, pThis->bullet->coorX);
  TEST_ASSERT_EQUAL(47, pThis->bullet->coorY);
  TEST_ASSERT_EQUAL(RELEASEBULLET, pThis->moveAmmoState);
}

void test_keyboard_no_press_should_return_the_direction_zero_in_ammo_state(void){
  movementShip *pThis = initiateMovementState();
  int keyHit;
  
  pThis->moveAmmoState = RELEASEBULLET;
  while((keyHit = getKbPressed()) != 0); 
  pThis->keyboard->buttonState = BUTTONNOHIT;
  movementAmmoFSM(pThis);
  
  TEST_ASSERT_EQUAL(BUTTON_RELEASED, pThis->keyboard->escCode);
  TEST_ASSERT_EQUAL(BUTTONHIT, pThis->keyboard->buttonState);
  TEST_ASSERT_EQUAL(RELEASEBULLET, pThis->moveAmmoState);
}

void test_keyboard_press_space_should_return_the_direction_thirty_two(void){
  movementShip *pThis = initiateMovementState();
  
  pThis->moveAmmoState = RELEASEBULLET;
  while((getKbPressed()) != 1);
  pThis->keyboard->buttonState = BUTTONHIT;
  movementAmmoFSM(pThis);

  TEST_ASSERT_EQUAL(KEY_SPACEBAR, pThis->keyboard->escCode);
  TEST_ASSERT_EQUAL(BUTTONHIT, pThis->keyboard->buttonState);
  TEST_ASSERT_EQUAL(PRESSEDBULLET, pThis->moveAmmoState);
}
  
void test_move_bullet_with_delta_x_zero_and_delta_y_negative_one(void){
  char bullet[] = {"|"};
  
  movementShip *pThis = initiateMovementState();
  pThis->bullet->image->picture = (char *)bullet;
  pThis->bullet->image->height = 1;
  pThis->bullet->image->width = 1;
  pThis->bullet->coorX = 25;
  pThis->bullet->coorY = 46;

  relativeMoveBullet(pThis->bullet, 0, -1);
  transferImageToConsole();

  TEST_ASSERT_EQUAL(25, pThis->bullet->coorX);
  TEST_ASSERT_EQUAL(45, pThis->bullet->coorY);
}

void test_get_system_time_together_with_FSM(void){
  movementShip *pThis = initiateMovementState();
  
  pThis->bullet->coorX = 25;
  pThis->bullet->coorY = 46;
  pThis->bullet->recordedTime = 0;
  pThis->bullet->timeInterval = 250;
  pThis->moveAmmoState = MOVEBULLETONESTEP; 
  movementAmmoFSM(pThis);
  
  TEST_ASSERT_EQUAL(pThis->moveAmmoState, MOVEBULLETONESTEP);
  TEST_ASSERT_EQUAL(45, pThis->bullet->coorY); 
  TEST_ASSERT_EQUAL(25, pThis->bullet->coorX); 
}

void test_alien_move_right_return_coorX_plus_one(void){
  char alien1[][3] = {{" ^ "},
                      {" @ "},
                      {"* *"}};
  movementShip *pEnemy = initiateMovementState();
  
  pEnemy->ship->image->picture = (char *)alien1;
  pEnemy->ship->image->width = 3;
  pEnemy->ship->image->height = 3;
  pEnemy->ship->coordinateX = 0;
  pEnemy->ship->coordinateY = 40;
  pEnemy->moveAlienState = MOVERIGHT;
  alienFSM(pEnemy);
  transferImageToConsole(); 
  
  TEST_ASSERT_EQUAL_PTR(alien1, pEnemy->ship->image->picture);
  TEST_ASSERT_EQUAL(3, pEnemy->ship->image->width);
  TEST_ASSERT_EQUAL(3, pEnemy->ship->image->height);
  TEST_ASSERT_EQUAL(1, pEnemy->ship->coordinateX);
  TEST_ASSERT_EQUAL(40, pEnemy->ship->coordinateY);
  TEST_ASSERT_EQUAL(MOVERIGHT, pEnemy->moveAlienState);
}

void test_alien_move_down_return_coorX_same_and_coorY_plus_one(void){
  char alien1[][3] = {{" ^ "},
                      {" @ "},
                      {"^ ^"}};
  movementShip *pEnemy = initiateMovementState();
  
  pEnemy->ship->image->picture = (char *)alien1;
  pEnemy->ship->image->width = 3;
  pEnemy->ship->image->height = 3;
  pEnemy->ship->coordinateX = 4;
  pEnemy->ship->coordinateY = 40;
  pEnemy->moveAlienState = MOVEDOWN;
  alienFSM(pEnemy);
  transferImageToConsole(); 
  
  TEST_ASSERT_EQUAL_PTR(alien1, pEnemy->ship->image->picture);
  TEST_ASSERT_EQUAL(3, pEnemy->ship->image->width);
  TEST_ASSERT_EQUAL(3, pEnemy->ship->image->height);
  TEST_ASSERT_EQUAL(4, pEnemy->ship->coordinateX);
  TEST_ASSERT_EQUAL(41, pEnemy->ship->coordinateY);
  TEST_ASSERT_EQUAL(MOVERIGHT, pEnemy->moveAlienState);
}

void test_alien_move_left_return_coorX_minus_one(void){
  char alien1[][3] = {{" ^ "},
                      {" @ "},
                      {"+ +"}};
  movementShip *pEnemy = initiateMovementState();
  
  pEnemy->ship->image->picture = (char *)alien1;
  pEnemy->ship->image->width = 3;
  pEnemy->ship->image->height = 3;
  pEnemy->ship->coordinateX = 8;
  pEnemy->ship->coordinateY = 42;
  pEnemy->moveAlienState = MOVELEFT;
  alienFSM(pEnemy);
  transferImageToConsole(); 
  
  TEST_ASSERT_EQUAL_PTR(alien1, pEnemy->ship->image->picture);
  TEST_ASSERT_EQUAL(3, pEnemy->ship->image->width);
  TEST_ASSERT_EQUAL(3, pEnemy->ship->image->height);
  TEST_ASSERT_EQUAL(7, pEnemy->ship->coordinateX);
  TEST_ASSERT_EQUAL(42, pEnemy->ship->coordinateY);
  TEST_ASSERT_EQUAL(MOVELEFT, pEnemy->moveAlienState);
}


 void test_exploreSequenceFSM(void){
  movementShip *pThis = initiateMovementState();
  listElement *element = NULL;
  pThis->explodeState = INITIALIZE; 
  explodeSequenceFSM(pThis, element);

  TEST_ASSERT_EQUAL(EXPLODE1, pThis->explodeState);
  TEST_ASSERT_EQUAL(0, explodeSequenceFSM(pThis, element));
 }

/* void test_explore_in_stage_one(void){
  char explosion1[][4] = {{" {} "},
                          {"{  }"}}; 
                          
  movementShip *pThis = initiateMovementState();
  listElement *element = createdlistElement((char *)explosion1, 4, 2, 37, 20);
  
  pThis->image->picture = (char *)explosion1;
  pThis->image->width = 4;
  pThis->image->height = 2;
  // element->coorX = 37;
  // element->coorY = 20;
  pThis->explodeState = EXPLODE1; 
  explodeSequenceFSM(pThis, element);  

  TEST_ASSERT_EQUAL(pThis->explodeState, EXPLODE2);
  TEST_ASSERT_EQUAL(0, explodeSequenceFSM(pThis, element));  
} */

  // char explode2[][5] = {{" ( ) "},
                        // {"(   )"}}; 
                        
  // char explode3[][6] = {{" <  > "},
                        // {"<    >"}};