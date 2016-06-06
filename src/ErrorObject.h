#ifndef ErrorObject_H
#define ErrorObject_H

typedef enum{
  ERR_ICON_NO_MATCH,
  ERR_POSITION_NO_MATCH,
  ERR_ICON_NO_FULLY_DISPLAY          
}ErrorCode;

typedef struct{
  char *errorMsg;
  ErrorCode errorCode;
}ErrorObject;

void throwErrorObject (char *message,ErrorCode errCode);
void freeError(ErrorObject *errObj);
#endif // ErrorObject_H
