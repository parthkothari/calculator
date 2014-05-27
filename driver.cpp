#include <iostream>
#include "Solve.h"

using std::cout;
using std::endl;


int main()
{
	std::string user_input;
	bool continue_iteration = true;

	// Command loop - will run until user types 'QUIT'.
	while(continue_iteration)
	{
		cout << endl << "Enter Expression >> " ;
		getline(std::cin, user_input, '\n');
		continue_iteration = solve(user_input);
	} // !Command Loop.

	return 0;
}