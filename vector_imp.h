#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    size_t capacity;
    int *data;
    int total;
} int_vector;
int_vector *vectorGenerate(size_t capty);
void vectorDestroy(int_vector *v);
void vectorPush(int_vector *v, int value);
void vectorInsert(int_vector *v, int value, int index);
int vectorPop(int_vector *v);
void vectorRemove(int_vector *v, int value, int index);
int vectorGetElement(int_vector *v, int index);
void vectorSetElement(int_vector *v,int value, int index);
int vectorGetSize(int_vector *v);
int vectorGetCapacity(int_vector *v);
int vectorCount(int_vector *v);
void vectorPrint(int_vector *v);
