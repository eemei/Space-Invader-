#include <stdlib.h>
#include <stdio.h>
#include "unity.h"
#include "BlockDiagram.h"

void setUp(void){}

void tearDown(void){}

/**To display out all the icon has been created:
*   Alien1, 2, 3, 4
*   Planet
*   Shelter
*/

// void test_module_generator_needs_to_be_implemented(void)
// {
	// displayAlien1();
  // displayAlien2();
  // displayAlien3();
  // displayAlien4();
  // displayPlanet();
  // displayShip();
  // displayShelter();
// }

void test_bufferFiller_with_symbol_plus_into_buffer(void){
  bufferFiller(10, 10, 0x2b);
}

void test_bufferFiller_with_symbol_asterisk_into_buffer(void){
  bufferFiller(10, 10, 0x2a);
}

void test_jumper_return_two_given_buffer_size_ten_coordinate_eight_and_width_four(void){
  char bufferTest[10][10];
  int returnJump1;
  returnJump1 = jumper(10, 8, 4);
  TEST_ASSERT_EQUAL(2, returnJump1);
}

void test_jumper_return_zero_given_buffer_size_ten_coordinate_four_and_width_four(void){
  char bufferTest[10][10];
  int returnJump2;
  returnJump2 = jumper(10, 4, 4);
  TEST_ASSERT_EQUAL(0, returnJump2);
}

void test_image_with_coordinate_inside_the_range(void){
	char shelter[][5] = {{"-----"},
                       {"|[+]|"},
                       {"-----"}};

	bufferFiller(50, 50, 0x2e);
  
  draw((char *)shelter, 5, 3, 5, 6);
  transferImageToConsole();
}

void test_image_with_coordinate_at_the_edge_and_show_half_of_the_image(void){
	char ship[][5] = {{"-----"},
                    {"|[+]|"},
                    {"-----"}};

	draw((char *)ship, 5, 3, 48, 6);
  transferImageToConsole();
}




