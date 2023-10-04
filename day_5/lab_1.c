#include <stdio.h>
#include "STD_TYPES.h"

void main(){
	u8 x=5,y=6;
	u8 *const ptr1=&x;
	u8 **ptr2=&ptr1;
	
	printf("%p\n",ptr1);
	printf("%p\n",*ptr2);
	
	//ptr1=&y; // case 1 ==>  error
	
	*ptr2=&y;  // case 2
	
	printf("%p\n",ptr1);
}