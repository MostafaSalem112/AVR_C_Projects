#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "voting.h"

void main(){
	u32 NumOfCandidates=3;
	u8 candidates[][20]={"Ahmed","Mohamed","Mostafa","None of these"};

	u32 option,CandidateNum;
	
	CreateCandidatesList(candidates,NumOfCandidates+1);
	
	while(1){
		printf("=============== Welcome to voting 2022 ======================\n\n");
		printf("1. Cast the Vote\n");
		printf("2. Find Vote Count\n");
		printf("3. Find winner\n");
		printf("0. Exit\n");
		
		printf("Enter your choice: ");
		scanf("%d",&option);
		
		if(option==0){
			break;
		}
		else if(option==1){
			printf("============== Choose your Candidate=================\n\n");
			for(u32 i=0;i<NumOfCandidates;i++){
				printf("%d. %s\n",i+1,candidates[i]);
			}
			printf("Enter your choice: ");
			scanf("%d",&CandidateNum);
			voting(CandidateNum,NumOfCandidates);
		}
		else if(option==2){
			printf("=============== Voting statistics ===================\n\n");
			DisplayCandidates();
		}
		else if(option==3){
			ShowWinner();
		}
	}
}