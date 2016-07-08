#ifndef FSM_H
#define FSM_H

#define KEY_LEFT  75
#define KEY_UP    72
#define KEY_RIGHT 77
#define KEY_DOWN  80

typedef enum {
  START,
  RELEASE,
  PRESSED,
  ST0RE
}StateMachine;

typedef struct {
  int Left;
  int Right;
}Move;

typedef struct {
  StateMachine state;
  Move *whichDirection;
  int coordinateX;
  int coordinateY;
  int kbPressed;
}movementShipState;

#endif // FSM_H


