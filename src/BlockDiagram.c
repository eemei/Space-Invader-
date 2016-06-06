#include <stdlib.h>
#include <stdio.h>
#include "BlockDiagram.h"

const char alien1[][11] = { {"    ++    "},
                            {"   ++++   "},
                            {"  ++++++  "},
                            {" ++++++++ "},
                            {"+++@++@+++"},
                            {"++++++++++"},
                            {"   +  +   "},
                            {"  +    +  "},
                            {"   +  +   "}};

const char alien2[][12] = {{"  +     +  "},
                           {"+  +   +  +"},
                           {"+ +++++++ +"},
                           {"+++@+++@+++"},
                           {" +++++++++ "},
                           {"  +     +  "},
                           {"+         +"}};

const char alien3[][13] = {{"  ++++++++  "},
                           {"++++++++++++"},
                           {"++@@++++@@++"},
                           {"++++++++++++"},
                           {"    +  +    "},
                           {"   + ++ +   "},
                           {"  +      +  "}};

const char alien4[][12] = {{"  +     +  "},
                           {"   +   +   "},
                           {"  +++++++  "},
                           {" ++@+++@++ "},
                           {"+++++++++++"},
                           {"+ +++++++ +"},
                           {"+ +     + +"},
                           {"   ++ ++   "}};
                           
const char planet[][17] = {{"   ++++++++++   "},
                           {"  ++++++++++++  "},
                           {" ++ ++ ++ ++ ++ "},
                           {"++++++++++++++++"},
                           {"  +++  ++  +++  "},
                           {"   +        +   "}};     

const char ship[][12] = {{"     +     "},
                         {"    +++    "},
                         {" +++++++++ "},                     
                         {"+++++++++++"}};
                         
const char shelter[][21] = {{"  +++++++++++++++++  "},
                            {" +++++++++++++++++++ "},
                            {"+++++++++++++++++++++"},
                            {"++++++         ++++++"},                            
                            {"+++++           +++++"},
                            {"+++++           +++++"}};
                            
void displayAlien1(){
  int i, j;

  for(i=0; i<9; i++){ 
    for(j=0; j<10; j++){
      printf("%c", alien1[i][j]);
    }
    printf("\n");
  }
}

void displayAlien2(){
  int i, j;

  for(i=0; i<7; i++){
    for(j=0; j<12; j++){
      printf("%c", alien2[i][j]);
    }
    printf("\n");
  }
}

void displayAlien3(){
  int i, j;

  for(i=0; i<7; i++){
    for(j=0; j<12; j++){
      printf("%c", alien3[i][j]);
    }
    printf("\n");
  }
}

void displayAlien4(){
  int i, j;

  for(i=0; i<8; i++){
    for(j=0; j<12; j++){
      printf("%c", alien4[i][j]);
    }
    printf("\n");
  }
}

void displayPlanet(){
  int i, j;

  for(i=0; i<6; i++){
    for(j=0; j<17; j++){
      printf("%c", planet[i][j]);
    }
    printf("\n");
  }
}

void displayShip(){
  int i, j;

  for(i=0; i<4; i++){
    for(j=0; j<12; j++){
      printf("%c", ship[i][j]);
    }
    printf("\n");
  }
}

void displayShelter(){
  int i, j;

  for(i=0; i<6; i++){
    for(j=0; j<21; j++){
      printf("%c", shelter[i][j]);
    }
    printf("\n");
  }
}