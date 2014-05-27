#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

/*-----------------------------------------------------------------------
//	Command class for Multiplication operation
/------------------------------------------------------------------------*/

#include "Binary_Op_Command.h"
class Multiply_Command : public Binary_Op_Command
{
public:

	// Default Constructor.
	Multiply_Command();

	// Evaluate.
	virtual int evaluate(int n1, int n2);
	
	// Get Type.
	virtual std::string get_type(void);
	
	// Virtual Destructor for correct polymorphic behavior.
	virtual ~Multiply_Command();

};


#endif //!_MULTIPLY_COMMAND_H_