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

void test_press_arrow_key_to_move_ship_left_or_right(void){
/*   int hit;
  hit = arrow();
  TEST_ASSERT_EQUAL (75,hit); */
// arrow();

  continuPress() ;
  }