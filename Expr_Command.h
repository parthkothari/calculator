#ifndef _EXPR_COMMAND_H_ 
#define _EXPR_COMMAND_H_ 

#include "Stack.h"

// Parth, you need to thoroughly document your class
// definitions as I have done with the previous assignments.

// Parth, your class needs a virtual destructor since you
// it has at least one virtual method. Otherwise, you will
// not have proper cleanup of the class hierarchy in certain
// cases.
// 
// Dr. Hill, I have corrected the mistake by adding a virtual 
// destructor and hence, implementing the polymorphic behavior
// needed to call all the destructors required.

class Expr_Command
{
public:
	
	virtual bool execute (Stack<int> & stack) = 0;
	virtual std::string get_type(void)=0;
	
	// Virtual Destructor for correct polymorphic behavior.
	virtual ~Expr_Command(){};
};




#endif //!_EXPR_COMMAND_H_ 