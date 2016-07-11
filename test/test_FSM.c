#include <stdlib.h>
#include <stdio.h>
#include "unity.h"
#include "FSM.h"
#include "mock_Action.h"

void setUp(void){}

void tearDown(void){}

void test_ship_initialized_coordination_return_X_twenty_four_and_Y_forty_seven(void){
  movementShip *pThis = initiateMovementState();
  
  pThis->state = START;
  movementShipFSM(pThis);
  
  TEST_ASSERT_EQUAL(24, pThis->coordinateX);
  TEST_ASSERT_EQUAL(47, pThis->coordinateY);
  TEST_ASSERT_EQUAL(RELEASE, pThis->state);
}

void test_keyboard_no_press_should_return_the_direction_zero(void){
  movementShip *pThis = initiateMovementState();
  
  pThis->state = RELEASE;
  pThis->keyboard->buttonState = BUTTONNOHIT;
  getKbPressed_ExpectAndReturn(pThis->kbPressed, BUTTON_RELEASED);
  movementShipFSM(pThis);
  
  TEST_ASSERT_EQUAL(BUTTON_RELEASED, pThis->keyboard->direction);
  TEST_ASSERT_EQUAL(BUTTONHIT, pThis->keyboard->buttonState);
  TEST_ASSERT_EQUAL(RELEASE, pThis->state);
}

void test_keyboard_press_left_should_return_the_direction_seventy_five(void){
  movementShip *pThis = initiateMovementState();
  
  pThis->state = RELEASE;
  pThis->keyboard->buttonState = BUTTONHIT;
  getKbPressed_ExpectAndReturn(pThis->kbPressed, BUTTON_PRESSED);
  movementShipFSM(pThis);
  
  TEST_ASSERT_EQUAL(KEY_LEFT, pThis->keyboard->direction);
  TEST_ASSERT_EQUAL(BUTTONHIT, pThis->keyboard->buttonState);
  TEST_ASSERT_EQUAL(PRESSED, pThis->state);
}

void test_keyboard_press_right_should_return_the_direction_seventy_seven(void){
  movementShip *pThis = initiateMovementState();
  
  pThis->state = RELEASE;
  pThis->keyboard->buttonState = BUTTONHIT;
  getKbPressed_ExpectAndReturn(pThis->kbPressed, BUTTON_PRESSED);
  movementShipFSM(pThis);
  
  TEST_ASSERT_EQUAL(KEY_RIGHT, pThis->keyboard->direction);
  TEST_ASSERT_EQUAL(BUTTONHIT, pThis->keyboard->buttonState);
  TEST_ASSERT_EQUAL(PRESSED, pThis->state);
}

void test_keyboard_press_left_should_return_the_coordinateX_twenty_three(void){
  movementShip *pThis = initiateMovementState();
  
  pThis->coordinateX = 24;
  pThis->coordinateY = 47;
  pThis->state = PRESSED;
  pThis->keyboard->buttonState = BUTTONHIT;
  getKbCodeLeft_ExpectAndReturn(pThis->keyboard->direction, KEY_LEFT);
  movementShipFSM(pThis);
  
  TEST_ASSERT_EQUAL(23, pThis->coordinateX);
  TEST_ASSERT_EQUAL(47, pThis->coordinateY);
  TEST_ASSERT_EQUAL(RELEASE, pThis->state);
}

void test_keyboard_press_right_should_return_the_coordinateX_twenty_five(void){
  movementShip *pThis = initiateMovementState();
  
  pThis->coordinateX = 24;
  pThis->coordinateY = 47;
  pThis->state = PRESSED;
  pThis->keyboard->buttonState = BUTTONHIT;
  getKbCodeLeft_ExpectAndReturn(pThis->keyboard->direction, KEY_RIGHT);
  getKbCodeRight_ExpectAndReturn(pThis->keyboard->direction, KEY_RIGHT);
  movementShipFSM(pThis);
  
  TEST_ASSERT_EQUAL(25, pThis->coordinateX);
  TEST_ASSERT_EQUAL(47, pThis->coordinateY);
  TEST_ASSERT_EQUAL(RELEASE, pThis->state);
}

 
 