#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "LinkedList.h"

Node *Head=NULL;
Node *Tail=NULL;

static Node *LKL_CreatNode(u32 Data){
	Node *Ptr=(Node *)malloc(sizeof(Node));
	Ptr->Data=Data;
	return Ptr;
}

void LKL_InsertAtLast(u32 Data){
	Node *Ptr=LKL_CreatNode(Data);
	if(Head==NULL){
		Head=Ptr;
	}
	else{
		Tail->Next=Ptr;
	}
	Ptr->Next=NULL;
	Tail=Ptr;
}

void LKL_InsertAtFirst(u32 Data){
	Node *Ptr=LKL_CreatNode(Data);
	if(Head==NULL){
		Head=Ptr;
		Tail=Ptr;
	}
	else{
		Ptr->Next=Head;
		Head=Ptr;
	}	
}

void LKL_InsertAtIndex(u32 Data,u32 index){
	Node *Ptr=LKL_CreatNode(Data);
	if(Head==NULL){
		Head=Ptr;
		Tail=Ptr;
	}
	else{
		Node *prev=Head;
		Node *Current=prev->Next;
		u32 i;
		if(index==0){
			Ptr->Next=Head;
			Head=Ptr;
		}
		else{
			Node *Ptr=LKL_CreatNode(Data);
			for(i=0;i<index-1;i++){
				if(Current!=NULL){
					prev=prev->Next;
					Current=Current->Next;
				}
				else{
					break;
				}
			}
			if(i==index-1){
				Ptr->Next=Current;
				prev->Next=Ptr;
				if(Current==NULL){
					Tail=Ptr;
				}
			}
			else{
				printf("this index is not valid...\n");
			}
		}
	}
}

void LKL_DisplayList(){
	Node *Current=Head;
	u32 i=0;
	if(Current==NULL){
		printf("your list is empty\n");
	}
	else{
		while(Current!=NULL){
			printf("data in index %d: %d\n",i,Current->Data);
			Current=Current->Next;
			i++;
		}
	}
}

u32 LKL_Find(u32 Data){
	Node *Current=Head;
	u32 index=-1,i=0;
	if(Current==NULL){
		printf("your list is empty\n");
	}
	else{
		while(Current!=NULL){
			if(Current->Data==Data){
				index=i;
				break;
			}
			i++;
			Current=Current->Next;
		}
	}
	return index;
}

void LKL_Delete(u32 Data){
	Node *prev=Head;
	Node *Current=prev->Next;
	Node *toDelete;
	if(prev==NULL){
		printf("your list is empty\n");
	}
	else if(prev->Data==Data){
		toDelete=Head;
		Head=Current;
	}
	else{
		while(Current!=NULL){
			if(Current->Data==Data){
				toDelete=Current;
				prev->Next=Current->Next;
				if(Current->Next==NULL){
					Tail=prev;
				}
				break;
			}
			prev=prev->Next;
			Current=Current->Next;
		}
	}
	free(toDelete);
}

void LKL_Sort(){
	Node *Current=Head;
	Node *prev;
	Node *Current_2;
	u32 temp;
	u8 flag;
	
	if(Current==NULL){
		printf("your list is empty\n");
	}
	else{
		while(Current!=NULL){
			prev=Head;
			Current_2=prev->Next;
			flag=0;
			while(Current_2!=NULL){
				if(prev->Data>Current_2->Data){
					temp=prev->Data;
					prev->Data=Current_2->Data;
					Current_2->Data=temp;
					flag=1;
				}
				prev=prev->Next;
				Current_2=Current_2->Next;
			}
			if(!flag){
				break;
			}
			Current=Current->Next;
		}
	}
}