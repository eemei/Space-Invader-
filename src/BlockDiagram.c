#include <stdlib.h>
#include <stdio.h>
#include "BlockDiagram.h"
#include <windows.h>

// Global buffer acts as a virtual console.
char buffer[BUFFERROW][BUFFERCOL];

// Filled buffer with blank space.
// To clean the buffer.
// Otherwise, buffer is filled with junk and will affect the result.
void bufferFiller(int row, int col, char symbol){
  int a, b;
  
  for (a=0; a<row; a++){
    for (b=0; b<col; b++){
      buffer[a][b] = symbol;
    }
  }
}

/* 
 *  @brief To jump the pointer cursor.
 *
 *  @aug   coor = coorX or coorY;
 *         range = width or length;
 *
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
 *        |    yeah          |     |
 *        |                ye|     |
 *        |                  |     |
 *        |yeah              |     |
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
 *
 *  @brief This function is to draw the images into buffer.
 *         (Assume "yeah" in above Figure as images drawn into the buffer.)
 *
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

/*
 *  @brief This function is to transfer the images
 *         inside the buffer into real console by 
 *         printing on it.
 *
 */
void transferImageToConsole(){
  int a, b, area;
  
  for (a=0; a<BUFFERROW; a++){
    for (b=0; b<BUFFERCOL; b++){
      printf("%c", buffer[a][b]);
    }
  }
}

/*
 *  @brief This function is to blank out the unwanted image.
 *
 */
void maskOutImage(int coorX, int coorY, int width, int height){
    int a = 0, b = 0;
    char symbol = 32;
    
  for (a=coorY; a<(coorY+height); a++){
    for (b=coorX; b<(coorX+width); b++){
      buffer[a][b] = symbol;
    }
  }
} 

/*
 *  @brief This function is to originate the cursor
 *         from the end point to (0,0) of the buffer. 
 *         The cursor will be hidden as well from the console
 *         as to make the console clean and nice to be seen.
 *
 *  @PS    This function can only be tested in bash/console.
 */
void cursorGotoXY(int x, int y){

  COORD coord;
  CONSOLE_CURSOR_INFO ConCurInf;
  
  coord.X = x;
  coord.Y = y;

  ConCurInf.dwSize = 10;
  ConCurInf.bVisible = FALSE;
 
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConCurInf);
}
