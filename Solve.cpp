#include "Solve.h"

//
// solve
//
bool solve (std::string & user_input)
{
	std::string infix = user_input;
	Stack_Expr_Command_Factory factory;
	Array<Expr_Command*> postfix;
	bool eval_success=false;


	if (user_input == "QUIT")
		{
			return false;	
		}
		else
		{
			if (user_input != "")
			{
				try
				{
					do_eval(infix, factory, postfix);
				}
				catch (std::exception &e)
				{

					std::cout << e.what() << std::endl;
				}
			}
		}
	return true;
}