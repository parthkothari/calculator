#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

/*-----------------------------------------------------------------------
//	Command class for Division operation
/------------------------------------------------------------------------*/

#include "Binary_Op_Command.h"
class Divide_Command : public Binary_Op_Command
{
public:

	// Default Constructor.
	Divide_Command();

	// Evaluate.
	virtual int evaluate(int n1, int n2);
	
	// Get Type.
	virtual std::string get_type(void);

	// Virtual Destructor for proper polymorphic behavior.
	virtual ~Divide_Command();
};

#endif //!_DIVIDE_COMMAND_H_