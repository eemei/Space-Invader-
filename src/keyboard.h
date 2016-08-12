#ifndef keyboard_H
#define keyboard_H

#ifndef TEST
  #include <stdio.h>
  #define _kbhit kbhit
  #define _getch getch
#else
  int _kbhit(void); 
  int _getch(void); 
#endif

#endif // keyboard_H
