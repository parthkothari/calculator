#include "Binary_Op_Command.h"

//
//	Execute - Binary_Op_Command
//
bool Binary_Op_Command::execute(Stack<int> &stack)
{
	int n1, n2;
	
	// Check for invalid expressions
	// If expression is invalid, the stack will not contain 
	// two opearands for a binary operator. (unless it is a - e.g. -(-2))
	try{
		n1 = stack.top();
		stack.pop();
		n2 = stack.top();
		stack.pop();
		stack.push (this->evaluate(n1, n2));
		return true;
	}
	catch (...)
	{
		throw std::invalid_argument ("INPUT ERROR, TRY AGAIN");	
		return false;
	}
}

//
//	Evaluate - Binary_Op_Command
//
int Binary_Op_Command::evaluate(int n1, int n2)
{
	return 0;
}

//
//	Destructor - Binary_Op_Command
//
Binary_Op_Command::~Binary_Op_Command()
{}

//
//	Constrcutor - Binary_Op_Command
//
Binary_Op_Command::Binary_Op_Command()
{}