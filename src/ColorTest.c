#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "ColorTest.h"

HANDLE hStdout;

int bucky()
{
  HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
  WORD wOldColorAttrs;
  CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

  /*
  * First save the current color information
  */
  GetConsoleScreenBufferInfo(h, &csbiInfo);
  wOldColorAttrs = csbiInfo.wAttributes;

  /*
  * Set the new color information
  */
  SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

  printf ( "This is a test\n" );

  /*
  * Restore the original colors
  */
  SetConsoleTextAttribute ( h, wOldColorAttrs);
  // ----------------------------------------------------------------------
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED);
	printf("This is red.\n");
	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE);
	printf("This is blue.\n");
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN);
	printf("This is green.\n");
  // ----------------------------------------------------------------------
  int count;
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  for (count=0; count<10; count++){
    SetConsoleTextAttribute(hConsole, count);
    printf ("This color combination has the number of %i\n",count);
  }

  SetConsoleTextAttribute(hConsole, 7);
  return 0;
}


int colorTextANSI(){

  printf(ANSI_COLOR_RED     "This text is RED!"     ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_GREEN   "This text is GREEN!"   ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_YELLOW  "This text is YELLOW!"  ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_BLUE    "This text is BLUE!"    ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_MAGENTA "This text is MAGENTA!" ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_CYAN    "This text is CYAN!"    ANSI_COLOR_RESET "\n");

  return 0;
}
