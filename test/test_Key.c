#include "unity.h"
#include "Key.h"
#include "BlockDiagram.h"

void setUp(void){}

void tearDown(void){}

void test_EscKey_return_27_when_esc_key_is_pressed(void){
	int esc;
  esc = escKey();
  TEST_ASSERT_EQUAL(27, esc);
} 

void test_fireBullet_return_1_when_spacebar_is_pressed(void){
  int returnFire;
  returnFire = fireBullet();
  TEST_ASSERT_EQUAL(32, returnFire);
  TEST_IGNORE_MESSAGE("FIRE!");
} 

/*void test_press_arrow_key_to_move_ship_left(void){
  
  //continuPress();

 int moveLeft;
 moveLeft = moveShipLeftRight();

 TEST_ASSERT_EQUAL(75, moveLeft);
  }
*/
void test_press_arrow_key_to_move_ship_right(void){

  int moveRight;
  moveRight = moveShipLeftRight();

  TEST_ASSERT_EQUAL(6, moveRight);
 // TEST_ASSERT_EQUAL(7, moveRight);
  }

 void test_gotoXY_function_at_the_range_when_x_equal_negative_value(void){
  int coordinateX = -5;
  int coordinateY = 9;
  
  gotoXY(coordinateX, coordinateY);
  TEST_ASSERT_EQUAL (0, gotoXY(coordinateX, coordinateY));
}

void test_gotoXY_function_at_the_range_when_x_more_than_50_value(void){
  int coordinateX = 55;
  int coordinateY = 40;
  
  gotoXY(coordinateX, coordinateY);
  TEST_ASSERT_EQUAL (47, gotoXY(coordinateX, coordinateY));
} 