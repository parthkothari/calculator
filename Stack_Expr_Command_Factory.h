#ifndef _STACK_EXPR_COMMAND_FACTORY_H_ 
#define _STACK_EXPR_COMMAND_FACTORY_H_


/*-----------------------------------------------------------------------
//	Expression Command Factory - Creates relevant expression command 
//	instance as requested.
/------------------------------------------------------------------------*/

#include "Expr_Command_Factory.h"


class Stack_Expr_Command_Factory : public Expr_Command_Factory
{
public:

	// Default Constructor.
	Stack_Expr_Command_Factory(); 

	// virtual destructor for correct destructor call in polymorphic behaviour.
	virtual ~Stack_Expr_Command_Factory(void);

	// Number Command.
	virtual Number_Command * create_number_command (int num);
	
	// Add Command.
	virtual Add_Command * create_add_command();
	
	// Subtract Command.
	virtual Subtract_Command * create_subtract_command();
	
	// Divide Command.
	virtual Divide_Command * create_divide_command();
	
	// Multiply Command.
	virtual Multiply_Command * create_multiply_command();
	
	// Mod Command.
	virtual Mod_Command * create_mod_command();
	
};

#endif //!_STACK_EXPR_COMMAND_FACTORY_H_