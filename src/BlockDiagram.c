#include <stdlib.h>
#include <stdio.h>
#include "BlockDiagram.h"

char buffer[50][50];
// char buffer1[1][1];

const char alien1[][3] = {{" ^ "},
                          {" @ "},
                          {"* *"}};

const char alien2[][4] =  {{" ^^ "},
                           {" @@ "},
                           {"*  *"}};

const char alien3[][6] = {{" ^^^ "},
                          {" @@@ "},
                          {"* * *"}};

const char alien4[][5] = {{" |*| "},
                          {" @@@ "},
                          {"*   *"}};
                           
const char planet[][4] = {{" -- "},
                          {"===="},
                          {" -- "}};     

const char ship[][3] = {{" | "},
                        {"[+]"}};
                         
const char shelter[][5] = {{"-----"},
                           {"|[+]|"},
                           {"-----"}};


                            
/* 
  {{" ^ "},
   {" @ "},
   {"* *"}};
 */
char displayAlien1(){
  int i, j;

  for(i=0; i<3; i++){ 
    for(j=0; j<3; j++){
      printf("%c", alien1[i][j]);
    }
    printf("\n");
  }
  
  return alien1[i][j];
}

/* 
  {{" ^^ "},
   {" @@ "},
   {"*  *"}};
 */
void displayAlien2(){
  int i, j;

  for(i=0; i<3; i++){
    for(j=0; j<4; j++){
      printf("%c", alien2[i][j]);
    }
    printf("\n");
  }
}

/* 
  {{" ^^^ "},
   {" @@@ "},
   {"* * *"}};
 */
void displayAlien3(){
  int i, j;

  for(i=0; i<3; i++){
    for(j=0; j<6; j++){
      printf("%c", alien3[i][j]);
    }
    printf("\n");
  }
}

/* 
  {{" |*| "},
   {" @@@ "},
   {"*   *"}};
 */
void displayAlien4(){
  int i, j;

  for(i=0; i<3; i++){
    for(j=0; j<5; j++){
      printf("%c", alien4[i][j]);
    }
    printf("\n");
  }
}

/* 
  {{" -- "},
   {"===="},
   {" -- "}}; 
 */
void displayPlanet(){
  int i, j;

  for(i=0; i<3; i++){
    for(j=0; j<4; j++){
      printf("%c", planet[i][j]);
    }
    printf("\n");
  }
}

/* 
  {{" | "},
   {"[+]"}};
 */
void displayShip(){
  int i, j;

  for(i=0; i<2; i++){
    for(j=0; j<3; j++){
      printf("%c", ship[i][j]);
    }
    printf("\n");
  }
}

/* 
  {{"-----"},
   {"|[+]|"},
   {"-----"}};
 */
void displayShelter(){
  int i, j;

  for(i=0; i<3; i++){
    for(j=0; j<5; j++){
      printf("%c", shelter[i][j]);
    }
    printf("\n");
  }
}

/* void transferImageToConsole (){
  displayAlien1 ();
  displayAlien2 ();                               
  displayAlien3 ();
  displayAlien4 ();
  displayPlanet ();
  displayShelter ();
  displayShip ();
};  */

void bufferFiller(int row, int col, char symbol){
  int a, b;
  
  for (a=0; a<row; a++){
    for (b=0; b<col; b++){
      buffer[a][b] = symbol;
      printf("%c", buffer[a][b]);
    }
    printf("\n");
  }
  
}

void draw (char *image, int width, int length, int coorX, int coorY) {
// void draw (char *image, int width, int length) {
  int i, j, a, b, displayIconX, displayIconY, totalX, totalY, widthPrime, lengthPrime;
  
  bufferFiller(50, 50, 0x2b);
  
  totalX = coorX + width;
  totalY = coorY + length;
  
  if ((totalX > 50)){
    widthPrime = totalX - 50;
    displayIconX = width - widthPrime;
    lengthPrime = totalY - 50;
    displayIconY = length - lengthPrime;
    for (i = 0; i< displayIconX; i++){
      for (j = 0; j< displayIconY; j++){
        buffer[coorY+j][coorX+j] = *(image++);
        printf("%c", buffer[coorY+i][coorX+j]);
      }
      printf("\n");
    }
  }
  else{
    for (i = 0; i < length; i++){
      for (j = 0; j < width; j++){
        buffer[coorY+i][coorX+j] = *(image++); 
        printf("%c", buffer[coorY+i][coorX+j]);
      }
      printf("\n");
    }
  }
  
  for (a=0; a<50; a++){
    for (b=0; b<50; b++){
      printf("%c", buffer[a][b]);
    }
    printf("\n");
  }
  
  printf("\n\n");
}

