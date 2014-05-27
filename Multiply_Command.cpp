#include "Multiply_Command.h"

//
//	Evaluate - Multiply_Command
//
int Multiply_Command::evaluate (int n1, int n2)
{
	return n1*n2;
}

//
//	Get Type - Multiply_Command
//
std::string Multiply_Command::get_type (void)
{
	return "*";
}

//
//	Destructor - Multiply_Command
//
Multiply_Command::~Multiply_Command(){}

//
//	Constructor - Multiply_Command
//
Multiply_Command::Multiply_Command(){}