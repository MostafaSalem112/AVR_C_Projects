#include<stdio.h>
void main(){
	int num1,num2;
	
	printf("enter number 1: ");
	scanf("%d",&num1);
	printf("enter number 2: ");
	scanf("%d",&num2);
	
	printf("num1 + num2 = %d\n",num1+num2);
	printf("num1 - num2 = %d\n",num1-num2);
	printf("num1 * num2 = %d\n",num1*num2);
	printf("num1 / num2 = %d\n",num1/num2);
	printf("num1 mod num2 = %d\n",num1%num2);
	printf("num1 & num2 = %d\n",num1&num2);
	printf("num1 | num2 = %d\n",num1|num2);
	printf("num1 ^ num2 = %d\n",num1^num2);
	printf("num1 && num2 = %d\n",num1&&num2);
	printf("num1 || num2 = %d\n",num1||num2);
	
}