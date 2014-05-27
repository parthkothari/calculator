#include "Add_Command.h"

//
//	Evaluate - Add Command
//
int Add_Command::evaluate (int n1, int n2)
{
	return n1+n2;
}

//
//	Get Type - Add Command
//
std::string Add_Command::get_type(void)
{
	return "+";
}

//
//	Constructor - Add Command
//
Add_Command::Add_Command()
{}

//
//	Destructor - Add Command
//
Add_Command::~Add_Command()
{}

