#include "Number_Command.h"

//
//	Constructor - Number_Command
//
Number_Command::Number_Command(int n):
n_(n){}


//
//	Execute - Number_Command
//
bool Number_Command::execute (Stack<int> &stack)
{
	stack.push(this->evaluate(n_));
	return true;
}

//
//	Evaluate - Number_Command
//
int Number_Command::evaluate (int n)
{
	return n;
}

//
//	Get Type - Number_Command
//
std::string Number_Command::get_type (void)
{
	std::string result;
	std::ostringstream convert;
	convert << n_;
	result = convert.str();	// return the number as a string 
	return result;
}

//
//	Destructor - Number_Command
//
Number_Command::~Number_Command(){}