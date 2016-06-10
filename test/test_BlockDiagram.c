#include "unity.h"
#include "BlockDiagram.h"

void setUp(void){}

void tearDown(void){}

void test_module_generator_needs_to_be_implemented(void)
{
	displayAlien1();
  displayAlien2();
  displayAlien3();
  displayAlien4();
  displayPlanet();
  displayShip();
  displayShelter();
}

/*  http://www.asciitable.com/
  ASCII table
*/
void test_illuAlien1_has_equal_symbol_with_respective_position(void){
  char illuAlien1[][8] = {{"   ^   "},
                          {"   @   "},
                          {"  * *  "}};
                      
  TEST_ASSERT_EQUAL(94, illuAlien1[0][3]);
  TEST_ASSERT_EQUAL(64, illuAlien1[1][3]);
  TEST_ASSERT_EQUAL(42, illuAlien1[2][2]);
  TEST_ASSERT_EQUAL(32, illuAlien1[2][3]);
  TEST_ASSERT_EQUAL(42, illuAlien1[2][4]);
  // printf("diagram = %c", illuAlien1[1][3]);
}

void test_illuAlien2_has_equal_symbol_with_respective_position(void){
  char illuAlien2[][9] =  {{"   ^^   "},
                           {"   @@   "},
                           {"  *  *  "}};
                           
  TEST_ASSERT_EQUAL(94, illuAlien2[0][3]);
  TEST_ASSERT_EQUAL(94, illuAlien2[0][4]);
  TEST_ASSERT_EQUAL(64, illuAlien2[1][3]);
  TEST_ASSERT_EQUAL(64, illuAlien2[1][4]);
  TEST_ASSERT_EQUAL(42, illuAlien2[2][2]);
  TEST_ASSERT_EQUAL(32, illuAlien2[2][3]);
  TEST_ASSERT_EQUAL(32, illuAlien2[2][4]);
  TEST_ASSERT_EQUAL(42, illuAlien2[2][5]);
}

void test_illuPlanet_has_equal_symbol_with_respective_position(void){
  char illuPlanet[][9] = {{"   --   "},
                          {"  ====  "},
                          {"   --   "}};  
                           
  TEST_ASSERT_EQUAL(45, illuPlanet[0][3]);
  TEST_ASSERT_EQUAL(45, illuPlanet[0][4]);
  TEST_ASSERT_EQUAL(61, illuPlanet[1][2]);
  TEST_ASSERT_EQUAL(61, illuPlanet[1][3]);
  TEST_ASSERT_EQUAL(61, illuPlanet[1][4]);
  TEST_ASSERT_EQUAL(45, illuPlanet[2][3]);
  TEST_ASSERT_EQUAL(45, illuPlanet[2][4]);
}

void test_illuShip_has_equal_symbol_with_respective_position(void){
  char illuShip[][10] = {{"    |    "},
                         {"   [+]   "}};
                           
  TEST_ASSERT_EQUAL(124, illuShip[0][4]);
  TEST_ASSERT_EQUAL(91, illuShip[1][3]);
  TEST_ASSERT_EQUAL(43, illuShip[1][4]);
  TEST_ASSERT_EQUAL(93, illuShip[1][5]);
  TEST_ASSERT_EQUAL(32, illuShip[1][6]);
}

void test_illuShelter_has_equal_symbol_with_respective_position(void){
 const char illuShelter[][11] = {{"   -----   "},
                                 {"   |[+]|   "},
                                 {"   -----   "}};
                            
  TEST_ASSERT_EQUAL(32,illuShelter[0][2]);
  TEST_ASSERT_EQUAL(45,illuShelter[0][3]);
  TEST_ASSERT_EQUAL(45,illuShelter[0][4]);
  TEST_ASSERT_EQUAL(45,illuShelter[0][5]);
  TEST_ASSERT_EQUAL(45,illuShelter[0][6]);
  TEST_ASSERT_EQUAL(45,illuShelter[0][7]);
  TEST_ASSERT_EQUAL(32,illuShelter[0][8]);
  TEST_ASSERT_EQUAL(124,illuShelter[1][3]);
  TEST_ASSERT_EQUAL(91,illuShelter[1][4]);
  TEST_ASSERT_EQUAL(43,illuShelter[1][5]);
  TEST_ASSERT_EQUAL(93,illuShelter[1][6]);
  TEST_ASSERT_EQUAL(124,illuShelter[1][7]);
  TEST_ASSERT_EQUAL(45,illuShelter[2][3]);
  TEST_ASSERT_EQUAL(45,illuShelter[2][4]);
  TEST_ASSERT_EQUAL(45,illuShelter[2][5]);
  TEST_ASSERT_EQUAL(45,illuShelter[2][6]);
  TEST_ASSERT_EQUAL(45,illuShelter[2][7]);  
}

