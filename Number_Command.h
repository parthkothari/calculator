#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

/*-----------------------------------------------------------------------
//	Command class for Numerical tokens.
/------------------------------------------------------------------------*/

#include "Expr_Command.h"
#include <sstream>

class Number_Command : public Expr_Command
{
public:
	
	// Constructor.
	Number_Command(int num);

	// Execute.
	virtual bool execute(Stack<int> & stack);
	
	// Evaluate.
	virtual int evaluate(int n);

	// Get Type.
	std::string get_type(void);

	// Virtual Destructor for correct polymorphic behavior.
	virtual ~Number_Command();

private:
	int n_;
};

#endif //!_NUMBER_COMMAND_H_