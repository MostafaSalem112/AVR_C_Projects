#include <stdio.h>
#include "STD_TYPES.h"

//=================case_1===========================
/*
typedef struct employee{
	u16 id;
	u32 salary;
	u16 bonus;
	u32 deduction;
} emp;
*/

//=================case_2===========================
/*
typedef struct employee{
	u16 id;
	u16 bonus;
	u32 salary;
	u32 deduction;
} emp;
*/

//=================case_3===========================
#pragma pack(1)
typedef struct employee{
	u16 id;
	u32 salary;
	u16 bonus;
	u32 deduction;
} emp;


void main(){
	emp mostafa;
	printf("%d",sizeof(mostafa));
}