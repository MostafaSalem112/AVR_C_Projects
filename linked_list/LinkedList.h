#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"

//======variables===========
typedef struct Node Node;
struct Node{
	u32 Data;
	Node *Next;
};

//=========functions=========
static Node *LKL_CreatNode(u32 Data);
void LKL_InsertAtLast(u32 Data);
void LKL_InsertAtFirst(u32 Data);
void LKL_InsertAtIndex(u32 Data,u32 inex);
void LKL_DisplayList();
u32 LKL_Find(u32 Data);
void LKL_Delete(u32 Data);
void LKL_Sort();