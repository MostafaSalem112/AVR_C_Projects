#include<stdio.h>

void main(){
	int num,count=0,flag,temp,arr[10];
	
	printf("enter a number: ");
	scanf("%d",&num);
	
	while(num>0){
		arr[count]=num%10;
		num/=10;
		count++;
	}
	
	printf("number of digits = %d\n",count);
	
	for(int i=0;i<count;i++){
		flag=0;
		for(int j=0;j<count-1-i;j++){
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
	
	printf("sorted number is: ");
	for(int i=0;i<count;i++){
		printf("%d",arr[i]);
	}
}