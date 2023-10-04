//implementation

#include<stdio.h>
#include"file_2.h"

void add(int *arr,int *sum,int size){
	for(int i=0;i<size;i++){
		*sum+=*(arr+i);
	}
}