#include <stdio.h>

void get_size(char *str,int *size){
	while(str[*size]!='\0'){
		(*size)++;
	}
}

void main(){
	char str[50];
	int size=0;

	printf("enter a string: ");
	scanf("%s",str);

	get_size(str,&size);

	printf("size of string: %d",size);
}
