#include "Evaluate_PostFix.h"
#include <iostream>


//
// evaluate_postfix
//

bool evaluate_postfix (Array<Expr_Command*> & postfix, int & postfixptr, int & result)
{
	Iterator<Expr_Command*> iter(postfix, postfixptr);
	Stack<int> stack;

	try{
	for (; !iter.is_done() ; iter.advance())
	{
		(*iter)->execute(stack);
	}
	} catch (std::exception &e)
		{
			{
				// Cleanup - empty the postfix expression and free memory.
				// If iteration failed, clean up before exiting the control.

				Iterator<Expr_Command*> cleaner (postfix, postfixptr);
				for (; !cleaner.is_done() ; cleaner.advance())
				{
					delete *cleaner;
				}
			}
			throw;
			return false;
		}

	// If evaluation is successful, the stack top contains the result.
	// Evaluation is complete. Stack should have only one element. If 
	// there are more elements in the stack, the postfix string is 
	// not correct, and therefore, the input string must be invalid.
	if (stack.size() == 1)
	{
	result = stack.top();
	return true;
	}
	else
	{
		// Clean up here before throwing an exception.
		Iterator<Expr_Command*> cleaner (postfix, postfixptr);
		for (; !cleaner.is_done() ; cleaner.advance())
		{
			delete *cleaner;
		}

		throw std::invalid_argument("INPUT ERROR, TRY AGAIN");
		return false;
	}

}
