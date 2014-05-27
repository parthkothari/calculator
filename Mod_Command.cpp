#include "Mod_Command.h"

//
//	Evaluate - Mod_Command
//
int Mod_Command::evaluate (int n1, int n2)
{
	return n2%n1;
}

//
//	Get Type - Mod_Command
//
std::string Mod_Command::get_type (void)
{
	return "%";
}

//
//	Destructor - Mod_Command
//
Mod_Command::~Mod_Command(){}

//
//	Constrcutor - Mod_Command
//
Mod_Command::Mod_Command(){}