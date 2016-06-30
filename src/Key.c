#include <stdlib.h>
#include <stdio.h>
#include "Key.h"

int escKey(){
  int ch;
  while ((ch = getch()) != 27){
    printf("%d", ch);
    if (ch == 0 || ch == 224)
      printf (", %d,", getch()); 
    printf("\n");
  }
  printf("ESC %d\n", ch);
  
  return ch;
}

int fireBullet(){
  int fire, kbPressed;
  
  while ((kbPressed = kbhit()) != 1);
  printf("%d\n", kbPressed);
  if (kbPressed){
    fire = getch();
    printf("%d\n", fire);
  } 
  
  if (fire == FIRE){
    printf("Fire!\n");
    return 1;
  }
  else{
    printf("Not pressed!\n");
    return 0;
  }
}

