#include<stdio.h>

void main(){
	int arr[10];
	int item,flag=0;

	for(int i=0;i<10;i++){
		printf("enter element number %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("enter the element to be searched: ");
	scanf("%d",&item);

	for(int i=0;i<10;i++){
		if(arr[i]==item){
			printf("the element is found in index %d",i);
			flag=1;
			break;
		}
	}
	if(!flag){
		printf("the element is not found");
	}
}