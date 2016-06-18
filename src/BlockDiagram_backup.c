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

/*
  coor = coorX or coorY;
  range = width or length;
*/
int jumper(int bufferRange, int coor, int range){
  int jump, newRange;
  if ((range + coor) > bufferRange){
    newRange = bufferRange - coor;
    jump = range - newRange;    
  }
  else
    jump = 0;
  return jump;
}

void draw (char *image, int width, int length, int coorX, int coorY) {
  int i, j, a, b, jumpNumX, jumpNumY, tempX, tempY;

  jumpNumX = jumper(50, coorX, width);
  jumpNumY = jumper(50, coorY, length);
  printf("jumping number X = %d\n", jumpNumX);
  printf("jumping number Y = %d\n", jumpNumY);
  
/*   if ((length+coorY)>50){
    length = 50 - coorY;
    printf("y=%d\n", length);
  }
  else {
    length = length;
    printf("yQ=%d\n", length);
  }
   if ((width+coorX)>50){
    width = 50 - coorX;
    printf("x=%d\n", width);
  }
  else {
    width = width;
    printf("Qx=%d\n", width);
  } */
  
  
  for (i = 0; i < length; i++){
    for (j = 0; j < width; j++){
      tempX = coorX + j;
      tempY = coorY + i;
      if ((tempX<50) || (tempY<50)){
      // if (tempX<50){
        buffer[coorY+i][coorX+j] = *(image++); 
      }
      else{
        image = image + jumpNumX;
        buffer[coorY+i][coorX+j] = *image;
      }
      printf("%c", buffer[coorY+i][coorX+j]);
    }
    printf("\n");
  }
  
  for (a=0; a<50; a++){
    for (b=0; b<50; b++){
      printf("%c", buffer[a][b]);
    }
    printf("\n");
  }
  
  printf("\n\n");
}

