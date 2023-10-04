#include<stdio.h>

void main(){
	int arr[10];
	int temp,flag;
	
	for(int i=0;i<10;i++){
		printf("enter element number %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	
	for(int i=0;i<10;i++){
		flag=0;
		for(int j=0;j<9-i;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=1;
			}
		}
		if(!flag){
			break;
		}
	}
	
	for(int i=0;i<10;i++){
		printf("%d\n",arr[i]);
	}
}