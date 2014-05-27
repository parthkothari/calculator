#ifndef _BINARY_OP_COMMAND_H_
#define _BINARY_OP_COMMAND_H_

/*-----------------------------------------------------------------------
//	Base Command class for all Binary operations.
/------------------------------------------------------------------------*/

#include "Expr_Command.h"


class Binary_Op_Command : public Expr_Command
{
public:

	// Default Constructor.
	Binary_Op_Command();

	// Execute.
	virtual bool execute(Stack<int> & stack);
	
	// Evaluate.
	virtual int evaluate(int n1, int n2) = 0;

	// Virtual Destructor for proper polymorphic destruction.
	virtual ~Binary_Op_Command();
};

#endif //!_BINARY_OP_COMMAND_H_