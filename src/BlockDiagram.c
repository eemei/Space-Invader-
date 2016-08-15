#include <stdlib.h>
#include <stdio.h>
#include "BlockDiagram.h"
#include <time.h>

char buffer[BUFFERROW][BUFFERCOL];

void bufferFiller(int row, int col, char symbol){
  int a, b;
  
  for (a=0; a<row; a++){
    for (b=0; b<col; b++){
      buffer[a][b] = symbol;
      // printf("%c", buffer[a][b]);
    }
    // printf("\n");
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
  
  jumpNumX = jumper(BUFFERROW, coorX, width);

  if ((width+coorX)>BUFFERROW){
    width = BUFFERROW - coorX;
  }
  else {
    width = width;
  }
  
  for (i = 0; i < length; i++){
    for (j = 0; j < width; j++){
      if (*image == 32){
        image++;        
      }
      else{
        buffer[coorY+i][coorX+j] = *(image++);                 
      }
    }
    image = image + jumpNumX;
  }
}

void transferImageToConsole(){
  int a, b, area;
  
  for (a=0; a<BUFFERROW; a++){
    for (b=0; b<BUFFERCOL; b++){
      printf("%c", buffer[a][b]);
    }
  }
  
  area = BUFFERROW * BUFFERCOL;
  refresh(area);
}

void maskOutImage(int coorX, int coorY, int width, int height){
    int a = 0, b = 0;
    char symbol = 32;
    
  for (a=coorY; a<(coorY+height); a++){
    for (b=coorX; b<(coorX+width); b++){
      buffer[a][b] = symbol;
    }
  }
} 

void refresh(int num){
  int x;
  for (x=num; x>0; x--){
    printf("\b");
  }
}