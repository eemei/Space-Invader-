#include <stdlib.h>
#include <stdio.h>
#include "unity.h"
#include "FSM.h"
#include "BlockDiagram.h"
#include "mock_Action.h"

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

// void test_time_interval_for_move_one_step_ammo(void){
  // movementShip *pThis = initiateMovementState();
  // int i = getTIME ();
  
 // // TEST_ASSERT_EQUAL_(0,i);
// }

void test_ammo_initialized_coordination_return_X_twenty_four_and_Y_forty_seven(void){
  movementShip *pThis = initiateMovementState();
  pThis->ship->coordinateX = 24;
  pThis->ship->coordinateY = 47;
  pThis->moveAmmoState = STARTBullet;
  movementAmmoFSM(pThis);
  
  TEST_ASSERT_EQUAL(24, pThis->bullet->coorX);
  TEST_ASSERT_EQUAL(47, pThis->bullet->coorY);
  TEST_ASSERT_EQUAL(RELEASEBullet, pThis->moveAmmoState);
}

void test_keyboard_no_press_should_return_the_direction_zero_in_ammo_state(void){
  movementShip *pThis = initiateMovementState();
  
  pThis->moveAmmoState = RELEASEBullet;
  pThis->keyboard->buttonState = BUTTONNOHIT;
  getKbPressed_ExpectAndReturn(pThis->kbPressed, BUTTON_RELEASED);
  movementAmmoFSM(pThis);
  
  TEST_ASSERT_EQUAL(BUTTON_RELEASED, pThis->keyboard->escCode);
  TEST_ASSERT_EQUAL(BUTTONHIT, pThis->keyboard->buttonState);
  TEST_ASSERT_EQUAL(RELEASEBullet, pThis->moveAmmoState);
}

void test_keyboard_press_space_should_return_the_direction_thirty_two(void){
  movementShip *pThis = initiateMovementState();
  
  pThis->moveAmmoState = RELEASEBullet;
  pThis->keyboard->buttonState = BUTTONHIT;
  getKbPressed_ExpectAndReturn(pThis->kbPressed, BUTTON_PRESSED);
  movementAmmoFSM(pThis);

  TEST_ASSERT_EQUAL(KEY_SPACE, pThis->keyboard->escCode);
  TEST_ASSERT_EQUAL(BUTTONHIT, pThis->keyboard->buttonState);
  TEST_ASSERT_EQUAL(PRESSEDBullet, pThis->moveAmmoState);
}

void test_move_bullet_one_step(void){
  movementShip *pThis = initiateMovementState();
  pThis->moveAmmoState = MOVEBULLETONESTEP; 
  movementAmmoFSM(pThis);
  
  //getTIME_ExpectAndReturn(0.25);
 // pThis->bullet->recordedTime = 0.00;
  
  //TEST_ASSERT_EQUAL( pThis->moveAmmoState,MOVEBULLETONESTEP);
}
