#include "solve.hpp"

int solve(Party *party){

	// TODO

	// Auxiliary codes (can be deleted)
	bool AknowB, BknowA;
	int i, j;
	for(i=0, j=1; j<party->getN(); j++){
		AknowB = party->askAToKnowB(i, j);
		if(AknowB)	i=j;
	}
	int winner = i;
	
	AknowB = true;
	for(int i=0; i<winner; i++){
		AknowB = party->askAToKnowB(i, winner);
		if(!AknowB)	return -1;
	}

	return winner;
}

