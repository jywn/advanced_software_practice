#include <cstdio>
#include "Party.hpp"
#include "Solve.hpp"

int main(){
	Party party(10);
	party.setRandomCase();
	party.start();
	int guess = solve(&party);
	//system("ls");
	return party.answer(guess);	
}
