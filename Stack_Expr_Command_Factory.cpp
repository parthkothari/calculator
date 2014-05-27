#include "Stack_Expr_Command_Factory.h"
//
// Default Constructor.
//
Stack_Expr_Command_Factory::Stack_Expr_Command_Factory(){}

//
// Destructor.
//
Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory(){}

//
// Number Command
//
Number_Command * Stack_Expr_Command_Factory::create_number_command (int num)
{
	return (new Number_Command(num));
}
	
//
// Add Command
//
Add_Command * Stack_Expr_Command_Factory::create_add_command()
{
	return (new Add_Command);
}
	
//
// Subtract Command
//
Subtract_Command * Stack_Expr_Command_Factory::create_subtract_command()
{
	return (new Subtract_Command);
}
	
//
// Divide Command
//
Divide_Command * Stack_Expr_Command_Factory::create_divide_command()
{
	return (new Divide_Command);
}
	
//
// Multiply Command
//
Multiply_Command * Stack_Expr_Command_Factory::create_multiply_command()
{
	return (new Multiply_Command);
}
	
//
// Mod Command
//
Mod_Command * Stack_Expr_Command_Factory::create_mod_command()
{
	return (new Mod_Command);
}
	
