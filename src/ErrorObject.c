#include "ErrorObject.h"
#include "CExceptionConfig.h"
#include <malloc.h>

void throwErrorObject (char *message, ErrorCode errCode){
  ErrorObject *errorObj = malloc(sizeof(ErrorObject));

  errorObj->errorMsg = message;
  errorObj->errorCode = errCode;
  Throw(errorObj);
}

void freeError(ErrorObject *errObj){
  free(errObj);
}
