#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct {
    size_t capacity;
    int *data;
    int total;
} int_vector;

int_vector *vectorGenerate(size_t capty)//Ctor
{
	int n;
	if(capty % 2 == 0)
		n = 2;
	else
		n = 1;
		
	int_vector *v = malloc(sizeof(int_vector));
	if(v) 
	{
	   v->data = malloc(n * capty * sizeof(int));
	   v->capacity = capty;
	   v->total = 0;
	}
	else
	{
		return NULL;
	}
	return v;
}

void vectorDestroy(int_vector *v)//Dtor
{
	if(v)
	{
		free(v->data);
        	free(v);
	}
}

void vectorPush(int_vector *v, int value)//not complit!!
{
	if(v->total > v->capacity)
	{
		v->data = realloc(v->data,sizeof(int) * v->capacity * 2);
	}
	v->data[v->total] = value;
	v->total = v->total + 1;
	
}
void vectorInsert(int_vector *v, int value, int index)
{
	if(v->total > v->capacity)
		v->data = realloc(v->data,sizeof(int) * v->capacity * 2);
		
	for(int i = index; i < v->capacity; ++i)
		v->data[i + 1] = v->data[i];
		
	v->data[index] = value;
	v->total = v->total + 1;
}
int vectorPop(int_vector *v)
{		
	int last = v->data[v->total];
	v->data[v->total] = 0;
	v->total--;
	return last;
}

void vectorRemove(int_vector *v, int value, int index)
{			
	for(int i = index; i > 0; --i)
		v->data[i] = v->data[i-1];
	v->total--;
}

int vectorGetElement(int_vector *v, int index)
{			
	return v->data[index];
}

void vectorSetElement(int_vector *v,int value, int index)//??
{			
	v->data[index] = value;
}

int vectorGetSize(int_vector *v)
{			
	return v->total;
}

int vectorGetCapacity(int_vector *v)
{			
	return v->capacity;
}

int vectorCount(int_vector *v)//??
{	
	int counter = 0;		
	for(int i = 0; i < v->capacity; i++)
	{
		counter++;
	}
	return counter;
}

void vectorPrint(int_vector *v)
{	
	for(int i = 0; i < v->capacity; i++)
		printf("%d\n",v->data[i]);
}

int main(void)
{
	printf("**** START-MAIN!!! ****\n");
	int_vector *v = vectorGenerate(10);
	vectorPush(v, 7);
	vectorPush(v, 4);
	vectorPush(v, 2);
	vectorPush(v, 9);
	vectorPush(v, 0);
	vectorInsert(v, 9, 6);
	vectorInsert(v, 5, 3);
	vectorRemove(v, 4, 7);
	printf("BEFOR PRINT\n");
	vectorPrint(v);
	printf("vectorGetElement: in position 3 --> %d\n",vectorGetElement(v , 3));
	printf("vectorGetCapacity: --->> %d\n",vectorGetCapacity(v));
	printf("vectorGetSize: --->> %d\n",vectorGetSize(v));
	printf("**** END-OF-MAIN!!! ****\n");
     return 0;
}
