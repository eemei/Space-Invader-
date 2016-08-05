#include <stdlib.h>
#include <stdio.h>
#include "BlockDiagram.h"
#include <time.h>


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
      if (*image == 32){
        image++;        
      }
      else{
        buffer[coorY+i][coorX+j] = *(image++);                 
      }
      printf("%c", buffer[coorY+i][coorX+j]);
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

double waitStage(double sec){
  clock_t start,end;
  double execution;

  start=clock();
  clock_t wait = sec*CLOCKS_PER_SEC;
  
  while(clock () < wait){}

  end=clock();
  
  execution = (double)(end-start)/CLOCKS_PER_SEC;
  printf("the program take %lf second\n",execution);
  return execution;
}

/* has the same value every time you execute it, 
 - since the value of sec never changes. 
 - So in your second program, 
 - the loop will wait on the first iteration 
 - until one second past program start, 
 - and on the subsequent iterations will never wait again,
 - because more than one second will have passed 
 - since program start and clock() < wait will never again be true.
*/
void explodeSequence(char *image1, char *image2, char *image3, int width, int length, int coorX, int coorY){
  draw(image1, width, length, coorX, coorY);
  waitStage(0.15);
  draw(image2, width+1, length, coorX, coorY);
  waitStage(0.30);
  draw (image3, width+2, length, coorX, coorY);
  waitStage(0.45);
}

