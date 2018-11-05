#include "vector_imp.h"
struct Int_Vector
{
    int *data;
    size_t capacity;
    size_t total;
};

static size_t nextPow(size_t x)
{
	int num = 1;
	while (num < x)
		num *= 2;
	return num;
}

Int_Vector *vectorGenerate(size_t capty)//Ctor
{
	capty = nextPow(capty);
		
	Int_Vector *v = malloc(sizeof(Int_Vector));
	if (v != NULL) 
	{
	   v->data = malloc(capty * sizeof(int));
	   if (v->data == NULL)
	   {
	   		free(v);
			return NULL;
	   } 

	   v->capacity = capty;
	   v->total = 0;
	}
	else
	{
		return NULL;
	}
	return v;
}

void vectorDestroy(Int_Vector **v)//Dtor
{
	if (*v != NULL || v != NULL)
	{
		free((*v)->data);
        	free(*v);
        	*v = NULL;
	}
}

static ErrorCode vectorResize(Int_Vector *v)
{
	v->data = realloc(v->data,sizeof(int) * v->capacity * 2);
		if(v->data == NULL)
			return E_ALLOCATION_ERROR;
	v->capacity *= 2;
	return E_OK;
}

ErrorCode vectorPush(Int_Vector *v, size_t value)
{
	if (v == NULL)
		return E_NULL_PTR;
	
	if (v->total == v->capacity)
	{
		ErrorCode err = vectorResize(v);
		if (err != E_OK)
			return err;			
	}
	v->data[v->total++] = value;
	return E_OK;
}

ErrorCode vectorInsert(Int_Vector *v, int value, size_t index)
{
	if (v == NULL)
		return E_NULL_PTR;
		
	if (index > v->total)
		return E_BAD_INDEX;
	
	if (index ==  v->total)
		return vectorPush(v , value);
		
	if (v->total == v->capacity)
	{
		ErrorCode err = vectorResize(v);
		if (err != E_OK)
			return err;			
	}
	
	//moveElementForward();TODO
	for (int i = v->capacity; i < index; --i)
		v->data[i] = v->data[i-1];
		
	v->data[index] = value;
	v->total += 1;
	return E_OK;
}

ErrorCode vectorPop(Int_Vector *v, int* item)
{	
	if (v == NULL || item == NULL)
		return E_NULL_PTR;
	
	if (v->total == 0)
		return E_UNDERFLOW;
			
	*item = v->data[--v->total];
	return E_OK;
}

ErrorCode vectorRemove(Int_Vector *v, size_t index, int* item)
{	
	int i;
	if (v == NULL || item == NULL)
		return E_NULL_PTR;
		
	if (index >= v->total)
		return E_BAD_INDEX;
		
	*item =  v->data[index];
	v->total--;
				
	for(i = index; i < v->capacity; ++i)
		v->data[i] = v->data[i+1];
	return E_OK;
}

ErrorCode vectorGetElement(Int_Vector *v, size_t index, int* item)
{	
	if (v == NULL || item == NULL)
		return E_NULL_PTR;
		
	if (index >= v->total)
		return E_BAD_INDEX;	
			
	*item = v->data[index];
	return E_OK;
}

ErrorCode vectorSetElement(Int_Vector *v,int value, size_t index)
{			
	if (v == NULL)
		return E_NULL_PTR;
		
	if (index >= v->total)
		return E_BAD_INDEX;	
			
	v->data[index] = value;
	return E_OK;
}

size_t vectorGetSize(Int_Vector *v)
{			
	return (v == NULL) ? 0 : v->total;
}

size_t vectorGetCapacity(Int_Vector *v)
{			
	return (v == NULL) ? 0 : v->capacity;
}

size_t vectorCount(Int_Vector *v, int value)
{	
	size_t i;
	size_t counter = 0;
	if (v == NULL)
		return 0;		
	for(i = 0; i < v->capacity; ++i)
	{
		if(v->data[i] == value)
			++counter;
	}
	return counter;
}

void vectorPrint(Int_Vector *v)
{	
	int i;
	printf("the vector:");
	for(int i = 0; i < v->capacity; i++)
		printf("%d\n",v->data[i]);
}
