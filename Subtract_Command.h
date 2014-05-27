#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

/*-----------------------------------------------------------------------
//	Command class for Subtraction operation
/------------------------------------------------------------------------*/

#include "Expr_Command.h"

/*
Subtract is usually a binary operator but sometime it functions as a unary 
operator e.g. - ( -5 ). Hence, Subtract_Command derives directly from Expr_Command
and not Binary_op_Command.
*/
class Subtract_Command : public Expr_Command
{
public:

	// Default Constructor.
	Subtract_Command();

	// Execute.
	virtual bool execute(Stack<int> & stack);
	
	// Evaluate.
	virtual int evaluate(int n1, int n2);

	// Get type.
	virtual std::string get_type(void);

	// Virtual Destructor for correct polymorphic behavior.
	virtual ~Subtract_Command();
};






#endif //!_SUBTRACT_COMMAND_H_