#ifndef _MOD_COMMAND_H_
#define _MOD_COMMAND_H_

/*-----------------------------------------------------------------------
//	Command class for Modulo operation
/------------------------------------------------------------------------*/

#include "Binary_Op_Command.h"

class Mod_Command : public Binary_Op_Command
{
public:

	// Default Constructor.
	Mod_Command();

	// Evaluate.
	virtual int evaluate(int n1, int n2);
	
	// Get Type.
	virtual std::string get_type(void);

	// Virtual Destructor.
	virtual ~Mod_Command();
};

#endif //!_MOD_COMMAND_H_