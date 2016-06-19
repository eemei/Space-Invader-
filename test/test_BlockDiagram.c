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

/* void testing(void){
  int i, j, a, b ,c ,d;
  char *ptr;
  char space[10][10];
  char example[][5] = {{"-----"},
                       {"|[+]|"},
                       {"-----"}};
                       
  ptr = (char *)example;
  
  for (a=0; a<10; a++){
    for (b=0; b<10; b++){
      space[a][b] = 0x2e;
      printf("%c", space[a][b]);
    }
    printf("\n");
  }
  
  for (i=0; i<3; i++){
    for (j=0; j<1; j++){ //
      space[i][j+9] = *(ptr++); //
      printf("%c", space[i][j+9]); //
    }
      ptr = ptr + 4; // 
    printf("\n");
  }
  
  for (c=0; c<10; c++){
    for (d=0; d<10; d++){
      printf("%c", space[c][d]);
    }
    printf("\n");
  }
} */




