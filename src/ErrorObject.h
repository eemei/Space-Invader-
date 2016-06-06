#ifndef ErrorObject_H
#define ErrorObject_H

typedef enum{
  ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING,  //
  ERR_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT_1             //
}ErrorCode;

typedef struct{
  char *errorMsg;
  ErrorCode errorCode;
}ErrorObject;

void throwErrorObject (char *message,ErrorCode errCode);
void freeError(ErrorObject *errObj);
#endif // ErrorObject_H
