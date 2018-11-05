#ifndef __VECTOR_IMP_H__
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Int_Vector Int_Vector;
typedef enum
{
	E_OK,//THAT WILL BE = 0 -->THE FIRST VALUE IN ENUM IS 0
	E_NULL_PTR,
	E_UNDERFLOW,
	E_ALLOCATION_ERROR,
	E_BAD_INDEX
}ErrorCode;

Int_Vector *vectorGenerate(size_t capty);
void vectorDestroy(Int_Vector **v);

ErrorCode vectorPush(Int_Vector *v, size_t value);
ErrorCode vectorInsert(Int_Vector *v, int value, size_t index);
ErrorCode vectorPop(Int_Vector *v, int* item);
ErrorCode vectorRemove(Int_Vector *v, size_t index, int* item);
ErrorCode vectorGetElement(Int_Vector *v, size_t index, int* item);
ErrorCode vectorSetElement(Int_Vector *v,int value, size_t index);
size_t vectorGetSize(Int_Vector *v);
size_t vectorGetCapacity(Int_Vector *v);
size_t vectorCount(Int_Vector *v, int value);
void vectorPrint(Int_Vector *v);
#endif
