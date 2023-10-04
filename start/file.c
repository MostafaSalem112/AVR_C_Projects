#include<stdio.h>
#include"file_2.h"

void main(){
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int sum=0;
	
	add(arr,&sum,10);
	
	printf("%d",sum);
}