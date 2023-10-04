#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"

//================variables==========================
typedef struct candidate candidate;
struct candidate{
	u8 name[20];
	u32 votes;
	candidate *next;
};

//===============functions===========================

void CreateCandidatesList(u8 candidates[][20],u32 NumOfCandidates);
void voting(u32 CandidateNum,u32 NumOfCandidates);
void DisplayCandidates();
void ShowWinner();