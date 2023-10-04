#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "LinkedList.h"

int main(){
	u16 User_Option;
	u32 User_Data;
	u32 index;
	
	while(1){
		printf("Welcome every one:)\n");
		printf("to insert at last enter 1\n");
		printf("to insert at first enter 2\n");
		printf("to insert at any index enter 3\n");
		printf("to display your list enter 4\n");
		printf("to search in list enter 5\n");
		printf("to delete from list enter 6\n");
		printf("to sort your list enter 7\n");
		printf("to exit enter 8\n");
		scanf("%d",&User_Option);
		
		if(User_Option==1){
			printf("enter your data: ");
			scanf("%d",&User_Data);
			LKL_InsertAtLast(User_Data);
		}
		else if(User_Option==2){
			printf("enter your data: ");
			scanf("%d",&User_Data);
			LKL_InsertAtFirst(User_Data);			
		}
		else if(User_Option==3){
			printf("enter your data: ");
			scanf("%d",&User_Data);
			printf("enter the index(starting from 0): ");
			scanf("%d",&index);
			LKL_InsertAtIndex(User_Data,index);
		}
		else if(User_Option==4){
			LKL_DisplayList();
		}
		else if(User_Option==5){
			printf("Enter the data you want to search for: ");
			scanf("%d",&User_Data);
			index=LKL_Find(User_Data);
			if(index==-1){
				printf("your data is not found...\n");
			}
			else{
				printf("your data is in index %d\n",index);
			}
		}
		else if(User_Option==6){
			printf("enter the data to be deleted: ");
			scanf("%d",&User_Data);
			LKL_Delete(User_Data);
		}
		else if(User_Option==7){
			LKL_Sort();
		}
		else if(User_Option==8){
			break;
		}
	}
	return 0;
}
