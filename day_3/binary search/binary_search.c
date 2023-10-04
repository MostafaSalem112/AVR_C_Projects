#include<stdio.h>

void main(){
	int arr[10];
	int temp,flag,item;
	int start=0,end=9,mid;
	
	for(int i=0;i<10;i++){
		printf("enter element number %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("enter the element to be searched: ");
	scanf("%d",&item);
	
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
	
	printf("sorted array is:\n");
	for(int i=0;i<10;i++){
		printf("%d\n",arr[i]);
	}
	flag=0;
	while(start<=end){
		mid=(start+end)/2;
		if(arr[mid]==item){
			printf("the element is found in index %d",mid);
			flag=1;
			break;
		}
		else if(arr[mid]>item){
			end=mid-1;
		}
		else{
			start=mid+1;
		}
	}
	if(!flag){
		printf("the element is not found");
	}
}