#include <stdlib.h>
#include <stdio.h>
#include "unity.h"
#include "BlockDiagram.h"

void setUp(void){}

void tearDown(void){}

void test_bufferFiller_with_symbol_plus_into_buffer(void){
  bufferFiller(10, 10, 0x2b);
  transferImageToConsole();
}

void test_bufferFiller_with_symbol_asterisk_into_buffer(void){
  bufferFiller(10, 10, 0x2a);
  transferImageToConsole();
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
	char ship[][3] = {{" T "},
                    {"[+]"}};

	bufferFiller(BUFFERROW, BUFFERCOL, 0x2e);
  
  draw((char *)ship, 3, 2, 5, 6);
  transferImageToConsole();
}

void test_image_with_coordinate_at_the_edge_and_show_half_of_the_image(void){
	char ship[][5] = {{"-----"},
                    {"|[+]|"},
                    {"-----"}};

	draw((char *)ship, 5, 3, 48, 6);
  transferImageToConsole();
}

void test_mask_out_image(void){
  maskOutImage(5, 6, 5, 3);
  transferImageToConsole();
}

void test_buffer_refresh_filled_with_symbol_underscore_with_initial_symbol_dot(void){
  int i, j;
  int a, b;
  char bufferTest[80][80];
  for (a=0; a<80; a++){
    for (b=0; b<80; b++){
      bufferTest[a][b] = 0x2e;
    }
  }
  
  refresh();
  
  for (a=0; a<80; a++){
    for (b=0; b<80; b++){
      bufferTest[a][b] = 95;
    }
  }
  
  for (i=0; i<80; i++){
    for (j=0; j<80; j++){
      TEST_ASSERT_EQUAL(95, bufferTest[i][j]);
    }
  }
}

