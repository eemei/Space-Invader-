#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "unity.h"
#include "FSM.h"
#include "mock_Action.h"
#include "FSM_t.h"

void setUp(void)
{
}

void tearDown(void)
{
}

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
  
  pThis->moveShipState = RELEASE;
  pThis->keyboard->buttonState = BUTTONNOHIT;
  getKbPressed_ExpectAndReturn(pThis->kbPressed, BUTTON_RELEASED);
  movementShipFSM(pThis);
  
  TEST_ASSERT_EQUAL(BUTTON_RELEASED, pThis->keyboard->escCode);
  TEST_ASSERT_EQUAL(BUTTONHIT, pThis->keyboard->buttonState);
  TEST_ASSERT_EQUAL(RELEASE, pThis->moveShipState);
}

void test_keyboard_press_left_should_return_the_direction_seventy_five(void){
  movementShip *pThis = initiateMovementState();
  
  pThis->moveShipState = RELEASE;
  pThis->keyboard->buttonState = BUTTONHIT;
  getKbPressed_ExpectAndReturn(pThis->kbPressed, BUTTON_PRESSED);
  movementShipFSM(pThis);
  
  TEST_ASSERT_EQUAL(KEY_LEFT, pThis->keyboard->escCode);
  TEST_ASSERT_EQUAL(BUTTONHIT, pThis->keyboard->buttonState);
  TEST_ASSERT_EQUAL(PRESSED, pThis->moveShipState);
}

void test_keyboard_press_right_should_return_the_direction_seventy_seven(void){
  movementShip *pThis = initiateMovementState();
  
  pThis->moveShipState = RELEASE;
  pThis->keyboard->buttonState = BUTTONHIT;
  getKbPressed_ExpectAndReturn(pThis->kbPressed, BUTTON_PRESSED);
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

void test_keyboard_press_left_should_return_the_coordinateX_twenty_three(void){
  movementShip *pThis = initiateMovementState();
  
  pThis->ship->coordinateX = 24;
  pThis->ship->coordinateY = 47;
  pThis->moveShipState = PRESSED;
  pThis->keyboard->buttonState = BUTTONHIT;
  getKbCodeLeft_ExpectAndReturn(pThis->keyboard->escCode, KEY_LEFT);
  movementShipFSM(pThis);
  
  TEST_ASSERT_EQUAL(23, pThis->ship->coordinateX);
  TEST_ASSERT_EQUAL(47, pThis->ship->coordinateY);
  TEST_ASSERT_EQUAL(RELEASE, pThis->moveShipState);
}

void test_keyboard_press_right_should_return_the_coordinateX_twenty_five(void){
  movementShip *pThis = initiateMovementState();
  
  pThis->ship->coordinateX = 24;
  pThis->ship->coordinateY = 47;
  pThis->moveShipState = PRESSED;
  pThis->keyboard->buttonState = BUTTONHIT;
  getKbCodeLeft_ExpectAndReturn(pThis->keyboard->escCode, KEY_RIGHT);
  getKbCodeRight_ExpectAndReturn(pThis->keyboard->escCode, KEY_RIGHT);
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
  
  pThis->moveAmmoState = RELEASEBULLET;
  pThis->keyboard->buttonState = BUTTONNOHIT;
  getKbPressed_ExpectAndReturn(pThis->kbPressed, BUTTON_RELEASED);
  movementAmmoFSM(pThis);
  
  TEST_ASSERT_EQUAL(BUTTON_RELEASED, pThis->keyboard->escCode);
  TEST_ASSERT_EQUAL(BUTTONHIT, pThis->keyboard->buttonState);
  TEST_ASSERT_EQUAL(RELEASEBULLET, pThis->moveAmmoState);
}

void test_keyboard_press_space_should_return_the_direction_thirty_two(void){
  movementShip *pThis = initiateMovementState();
  
  pThis->moveAmmoState = RELEASEBULLET;
  pThis->keyboard->buttonState = BUTTONHIT;
  getKbPressed_ExpectAndReturn(pThis->kbPressed, BUTTON_PRESSED);
  movementAmmoFSM(pThis);

  TEST_ASSERT_EQUAL(KEY_SPACEBAR, pThis->keyboard->escCode);
  TEST_ASSERT_EQUAL(BUTTONHIT, pThis->keyboard->buttonState);
  TEST_ASSERT_EQUAL(PRESSEDBULLET, pThis->moveAmmoState);
}

// void test_move_bullet_one_step_with_mock_the_time(void){
  // char bullet[] = {"|"};
  
  // movementShip *pThis = initiateMovementState();
  // pThis->bullet->image->picture = (char *)bullet;
  // pThis->bullet->image->height = 1;
  // pThis->bullet->image->width = 1;
  // pThis->bullet->coorX = 25;
  // pThis->bullet->coorY = 46;
  // pThis->bullet->recordedTime = 0;
  // pThis->bullet->timeInterval = 250;
  // pThis->moveAmmoState = MOVEBULLETONESTEP; 
  
  // getTIME_ExpectAndReturn(250);
  // getTIME_ExpectAndReturn(100);
  
  // movementAmmoFSM(pThis);
  
  // TEST_ASSERT_EQUAL(pThis->moveAmmoState, MOVEBULLETONESTEP);
  // TEST_ASSERT_EQUAL(45, pThis->bullet->coorY); 
  // TEST_ASSERT_EQUAL(25, pThis->bullet->coorX); 
//}

  
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

void test_get_current_time(void){

  uint32_t start, end;
  char get_char[256];
  uint32_t diffms;

  start = getSystemTime();
  gets (get_char);                  /* act as a interrupt to proceed next station*/
  end = getSystemTime();
  diffms = end - start;
  printf ("diffms = %i\n ", diffms);
}

void test_get_system_time_together_with_FSM_without_mock(void){
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