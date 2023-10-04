#include<stdio.h>

void main(){
	int num1=5,num2=7;
	
	num1 = num1++ + num1;
	num2 = num2-- + num2;
	
	printf("num1 = num1++ + num1 = %d\n",num1);
	printf("num2 = num2-- + num2 = %d\n",num2);
}