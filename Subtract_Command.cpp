#include "Subtract_Command.h"

//
//	Execute - Subtract_Command
//
bool Subtract_Command::execute(Stack<int> &stack)
{
	int n1, n2;
	if (stack.size() > 0)
	{
		n1 = stack.top();
		stack.pop();
		if (stack.size() > 0)
		{
			n2 = stack.top();
			stack.pop();
		}
		else
		{
			n2 = 0;
		}
		stack.push (this->evaluate(n1, n2));
		return true;
	}
	else
	{
		throw std::invalid_argument ("INPUT ERROR, TRY AGAIN");	
		return false;
	}
}

//
//	Evaluate - Subtract_Command
//
int Subtract_Command::evaluate (int n1, int n2)
{
	return n2-n1;
}

//
//	Get Type - Subtract_Command
//
std::string Subtract_Command::get_type(void)
{
	return "-";
}

//
//	Destructor - Subtract_Command
//
Subtract_Command::~Subtract_Command(){}

//
//	Constructor - Subtract_Command
//
Subtract_Command::Subtract_Command(){}