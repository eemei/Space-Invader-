#include "BlockDiagram.h"
#include "unity.h"


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









void test_illuAlien1_has_equal_symbol_with_respective_position(void){

  char illuAlien1[][8] = {{"   ^   "},

                          {"   @   "},

                          {"  * *  "}};



  UnityAssertEqualNumber((_U_SINT)((94)), (_U_SINT)((illuAlien1[0][3])), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((64)), (_U_SINT)((illuAlien1[1][3])), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((42)), (_U_SINT)((illuAlien1[2][2])), (((void *)0)), (_U_UINT)29, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((illuAlien1[2][3])), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((42)), (_U_SINT)((illuAlien1[2][4])), (((void *)0)), (_U_UINT)31, UNITY_DISPLAY_STYLE_INT);



}



void test_illuAlien2_has_equal_symbol_with_respective_position(void){

  char illuAlien2[][9] = {{"   ^^   "},

                           {"   @@   "},

                           {"  *  *  "}};



  UnityAssertEqualNumber((_U_SINT)((94)), (_U_SINT)((illuAlien2[0][3])), (((void *)0)), (_U_UINT)40, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((94)), (_U_SINT)((illuAlien2[0][4])), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((64)), (_U_SINT)((illuAlien2[1][3])), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((64)), (_U_SINT)((illuAlien2[1][4])), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((42)), (_U_SINT)((illuAlien2[2][2])), (((void *)0)), (_U_UINT)44, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((illuAlien2[2][3])), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((illuAlien2[2][4])), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((42)), (_U_SINT)((illuAlien2[2][5])), (((void *)0)), (_U_UINT)47, UNITY_DISPLAY_STYLE_INT);

}



void test_illuPlanet_has_equal_symbol_with_respective_position(void){

  char illuPlanet[][9] = {{"   --   "},

                          {"  ====  "},

                          {"   --   "}};



  UnityAssertEqualNumber((_U_SINT)((45)), (_U_SINT)((illuPlanet[0][3])), (((void *)0)), (_U_UINT)55, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((45)), (_U_SINT)((illuPlanet[0][4])), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((61)), (_U_SINT)((illuPlanet[1][2])), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((61)), (_U_SINT)((illuPlanet[1][3])), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((61)), (_U_SINT)((illuPlanet[1][4])), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((45)), (_U_SINT)((illuPlanet[2][3])), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((45)), (_U_SINT)((illuPlanet[2][4])), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_INT);

}



void test_illuShip_has_equal_symbol_with_respective_position(void){

  char illuShip[][10] = {{"    |    "},

                         {"   [+]   "}};



  UnityAssertEqualNumber((_U_SINT)((124)), (_U_SINT)((illuShip[0][4])), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((91)), (_U_SINT)((illuShip[1][3])), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((43)), (_U_SINT)((illuShip[1][4])), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((93)), (_U_SINT)((illuShip[1][5])), (((void *)0)), (_U_UINT)71, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((illuShip[1][6])), (((void *)0)), (_U_UINT)72, UNITY_DISPLAY_STYLE_INT);

}



void test_illuShelter_has_equal_symbol_with_respective_position(void){

 const char illuShelter[][11] = {{"   -----   "},

                                 {"   |[+]|   "},

                                 {"   -----   "}};



  UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((illuShelter[0][2])), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((45)), (_U_SINT)((illuShelter[0][3])), (((void *)0)), (_U_UINT)81, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((45)), (_U_SINT)((illuShelter[0][4])), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((45)), (_U_SINT)((illuShelter[0][5])), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((45)), (_U_SINT)((illuShelter[0][6])), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((45)), (_U_SINT)((illuShelter[0][7])), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((illuShelter[0][8])), (((void *)0)), (_U_UINT)86, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((124)), (_U_SINT)((illuShelter[1][3])), (((void *)0)), (_U_UINT)87, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((91)), (_U_SINT)((illuShelter[1][4])), (((void *)0)), (_U_UINT)88, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((43)), (_U_SINT)((illuShelter[1][5])), (((void *)0)), (_U_UINT)89, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((93)), (_U_SINT)((illuShelter[1][6])), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((124)), (_U_SINT)((illuShelter[1][7])), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((45)), (_U_SINT)((illuShelter[2][3])), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((45)), (_U_SINT)((illuShelter[2][4])), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((45)), (_U_SINT)((illuShelter[2][5])), (((void *)0)), (_U_UINT)94, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((45)), (_U_SINT)((illuShelter[2][6])), (((void *)0)), (_U_UINT)95, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((45)), (_U_SINT)((illuShelter[2][7])), (((void *)0)), (_U_UINT)96, UNITY_DISPLAY_STYLE_INT);

}
