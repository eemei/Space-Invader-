#ifndef keyboard_H
#define keyboard_H

/*
 *  @brief This is to mock the function kbhit and getch
 *         for test and use the real functions in .exe.
 *
 */
#ifndef TEST
  #include <stdio.h>
  #define _kbhit kbhit
  #define _getch getch
#else
  int _kbhit(void); 
  int _getch(void); 
#endif

#endif // keyboard_H
