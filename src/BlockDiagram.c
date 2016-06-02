#include <stdlib.h>
#include <stdio.h>
#include "BlockDiagram.h"

const char alien1[][8] = {{"   ^   "},
                          {"   @   "},
                          {"  * *  "}};

const char alien2[][9] =  {{"   ^^   "},
                           {"   @@   "},
                           {"  *  *  "}};

const char alien3[][10] = {{"   ^^^   "},
                           {"   @@@   "},
                           {"  * * *  "}};

const char alien4[][10] = {{"   |*|   "},
                           {"   @@@   "},
                           {"  *   *  "}};
                           
const char planet[][9] = {{"   --   "},
                          {"  ====  "},
                          {"   --   "}};     

const char ship[][10] = {{"    |    "},
                         {"   [+]   "}};
                         
const char shelter[][11] = {{"   -----   "},
                            {"   |[+]|   "},
                            {"   -----   "}};
                            
void displayAlien1(){
  int i, j;

  for(i=0; i<3; i++){ 
    for(j=0; j<7; j++){
      printf("%c", alien1[i][j]);
    }
    printf("\n");
  }
}

void displayAlien2(){
  int i, j;

  for(i=0; i<3; i++){
    for(j=0; j<8; j++){
      printf("%c", alien2[i][j]);
    }
    printf("\n");
  }
}

void displayAlien3(){
  int i, j;

  for(i=0; i<3; i++){
    for(j=0; j<9; j++){
      printf("%c", alien3[i][j]);
    }
    printf("\n");
  }
}

void displayAlien4(){
  int i, j;

  for(i=0; i<3; i++){
    for(j=0; j<9; j++){
      printf("%c", alien4[i][j]);
    }
    printf("\n");
  }
}

void displayPlanet(){
  int i, j;

  for(i=0; i<3; i++){
    for(j=0; j<8; j++){
      printf("%c", planet[i][j]);
    }
    printf("\n");
  }
}

void displayShip(){
  int i, j;

  for(i=0; i<2; i++){
    for(j=0; j<9; j++){
      printf("%c", ship[i][j]);
    }
    printf("\n");
  }
}

void displayShelter(){
  int i, j;

  for(i=0; i<3; i++){
    for(j=0; j<10; j++){
      printf("%c", shelter[i][j]);
    }
    printf("\n");
  }
}


