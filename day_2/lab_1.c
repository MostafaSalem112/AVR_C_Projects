#include<stdio.h>
void main(){
	int n,x=1;
	
	printf("enter a number: ");
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			printf("%d ",x);
			x++;
		}
		printf("\n");
	}
}