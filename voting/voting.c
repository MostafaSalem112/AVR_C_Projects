#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "voting.h"

candidate *head=NULL;
candidate *tail=NULL;

void CreateCandidatesList(u8 candidates[][20],u32 NumOfCandidates){
	u32 j=0;
	for(u32 i=0;i<NumOfCandidates;i++){
		candidate *new_candidate=(candidate *)malloc(sizeof(candidate));
		if(i==0){
			head=new_candidate;
			tail=new_candidate;
		}
		else{
			tail->next=new_candidate;
			tail=new_candidate;
		}
		//new_candidate->name=candidates[i];
		while(candidates[i][j]!='\0'){
			new_candidate->name[j]=candidates[i][j];
			j++;
		}
		new_candidate->name[j]=candidates[i][j];
		j=0;
		new_candidate->votes=0;
		new_candidate->next=NULL;
	}
}

void voting(u32 CandidateNum,u32 NumOfCandidates){
	if(CandidateNum>NumOfCandidates){
		(tail->votes)++;
	}
	else{
		candidate *current=head;
		for(u32 i=1;i<CandidateNum;i++){
			current=current->next;
		}
		(current->votes)++;
	}
}

void DisplayCandidates(){
	candidate *current=head;
	while(current!=NULL){
		printf("%s - ",current->name);
		printf("%d\n",current->votes);
		current=current->next;
	}
}

void ShowWinner(){
	u32 max=0;
	u8 f=0;
	candidate *winner=NULL;
	candidate *current=head;
	while(current->next != NULL){
		if(current->votes>max){
			winner=current;
			max=current->votes;
		}
		else if(current->votes==max){
			winner=NULL;
		}
		current=current->next;
	}
	if(winner==NULL){
		printf("\nthere is no winner yet...\n\n");
	}
	else{
		printf("\nthe winner is %s with %d votes\n\n",winner->name,winner->votes);
	}
}

