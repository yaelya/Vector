#include "vector_imp.h"
#define CHECK_FUNC(func) if (func != E_OK) printf("ERROR IN LINE: %d\n",__LINE__);
int main(void)
{
	int* item;
	printf("**** START-MAIN!!! ****\n");
	Int_Vector *v = vectorGenerate(4);
	CHECK_FUNC(vectorPush(v, 7));
	CHECK_FUNC(vectorPush(v, 4));
	CHECK_FUNC(vectorPush(v, 2));
	CHECK_FUNC(vectorPush(v, 9));
	CHECK_FUNC(vectorInsert(v, 9, 2));
	CHECK_FUNC(vectorInsert(v, 5, 3));
	CHECK_FUNC(vectorRemove(v, 4,item));
	printf("BEFOR PRINT\n");
	vectorPrint(v);
	printf("vectorGetElement: in position 3 --> %d\n",vectorGetElement(v , 3,item));
	printf("vectorGetCapacity: --->> %ld\n",vectorGetCapacity(v));
	printf("vectorGetSize: --->> %ld\n",vectorGetSize(v));
	printf("**** END-OF-MAIN!!! ****\n");
     return 0;
}
