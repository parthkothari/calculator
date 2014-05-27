#ifndef _EXPR_COMMAND_FACTORY_H_
#define _EXPR_COMMAND_FACTORY_H_

#include "Number_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Mod_Command.h"


// Parth, you need to thoroughly document your class
// definitions as I have done with the previous assignments.

class Expr_Command_Factory{
public:
	// Default Constrctor.
	Expr_Command_Factory();

	// Virtual destructor for correct destructor call in polymorphic behavior.
	virtual ~Expr_Command_Factory();

	// Number Command.
	virtual Number_Command * create_number_command (int num)=0;
	
	// Add Command.
	virtual Add_Command * create_add_command(void)=0;
	
	// Subtract Command.
	virtual Subtract_Command * create_subtract_command()=0;
	
	// Divide Command.
	virtual Divide_Command * create_divide_command()=0;
	
	// Multiply Command.
	virtual Multiply_Command * create_multiply_command()=0;
	
	// Mod Command.
	virtual Mod_Command * create_mod_command()=0;
	

private:
	// Do not allow client to call these functions.
	Expr_Command_Factory (const Expr_Command_Factory &);
	const Expr_Command_Factory & operator = (const Expr_Command_Factory &);
};




#endif //!_EXPR_COMMAND_FACTORY_H_