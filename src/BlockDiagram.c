#include <stdlib.h>
#include <stdio.h>
#include "BlockDiagram.h"

char buffer[50][50];

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

/**
 *
 *        --------------------    __
 *        |                  |     |
 *        |                  |     |
 *        |                  |     |
 *        |                  |     |
 *        |                  |     |
 *        |                  |     |- Y / length
 *        |                  |     |
 *        |                  |     |
 *        |                  |     |
 *        |                  |     |
 *        |                  |     |
 *        |                  |    __
 *        --------------------
 *        |__________________|
 *                 |
 *              X / width 
 *
 **/
void draw(char *image, int width, int length, int coorX, int coorY) {
  int i, j, a, b, jumpNumX, jumpNumY, tempX, tempY;

  jumpNumX = jumper(50, coorX, width);
  // printf("jumping number X = %d\n", jumpNumX);

  if ((width+coorX)>50){
    width = 50 - coorX;
    // printf("new width = %d\n", width);
  }
  else {
    width = width;
    // printf("original width = %d\n", width);
  }
  
  for (i = 0; i < length; i++){
    for (j = 0; j < width; j++){
      buffer[coorY+i][coorX+j] = *(image++); 
      // printf("%c", buffer[coorY+i][coorX+j]);
    }
    image = image + jumpNumX;
    printf("\n");
  }
  printf("\n");
}

void transferImageToConsole(){
  int a, b;
  
  for (a=0; a<50; a++){
    for (b=0; b<50; b++){
      printf("%c", buffer[a][b]);
    }
    printf("\n");
  }
}

void maskOutImage(int coorX, int coorY, int width, int height){
    int a = 0, b = 0;
    char symbol = 32;
    
  for (a=coorY; a<(coorY+height); a++){
    for (b=coorX; b<(coorX+width); b++){
      buffer[a][b] = symbol;
      // printf("%c", buffer[a][b]);
    }
    printf("\n");
  }
} 