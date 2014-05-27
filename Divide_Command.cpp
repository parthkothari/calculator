#include "Divide_Command.h"

//
//	Evaluate  - Divide_Command
//
int Divide_Command::evaluate (int n1, int n2)
{
	if ( n1 != 0 )
	{
	return n2/n1;
	}
	else 
	{
		throw std::invalid_argument("MATH ERROR: DIVISION BY ZERO");
	}
}

//
//	Get_type - Divide_Command
//
std::string Divide_Command::get_type (void)
{
	return "/";
}

//
//	Destructor - Divide_Command
//
Divide_Command::~Divide_Command()
{}

//
//	Constructor - Divide_Command
//
Divide_Command::Divide_Command()
{}