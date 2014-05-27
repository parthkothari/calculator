#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

/*-----------------------------------------------------------------------
//	Command class for Addition operation
/------------------------------------------------------------------------*/

#include "Binary_Op_Command.h"


class Add_Command : public Binary_Op_Command
{
public:
	virtual int evaluate(int n1, int n2);
	virtual std::string get_type(void);
	
	// Virtual Destructor for proper polymorphic destruction.
	virtual ~Add_Command();

	Add_Command();
};

#endif //!_ADD_COMMAND_H_