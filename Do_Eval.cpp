

#include "Do_Eval.h"
#include <cstdlib>	// For atoi.


void printarray(Array<Expr_Command*> & postfix, int postfix_ptr);
// Function to print the stack for debug purposes
void printstack(Stack<Expr_Command*> & temp);
void printps(Stack<char> & temp);

//
// do_eval
//
bool do_eval (	const std::string & infix, 
				Expr_Command_Factory & factory, 
				Array<Expr_Command*> & postfix){ 

	// Set insertion point in postfix string at 0 for new user input.
	postfix.resize(0);
	int postfix_ptr = 0;	

	// Trim the whitespaces at the end of the input string.
	std::string str(infix);
	str.erase(str.find_last_not_of(' ')+1);   


	// If postfix array is uninitialized, initialize with max possible length.
	if (postfix.size() < str.length())	
	{									
		 postfix.resize(str.length());
	}

	std::istringstream input(str); // Create an input stream parser. 
	std::string token; // Current token in string/stream.
	Expr_Command * cmd = 0; // Create a command object. 
	Stack <Expr_Command *> cmd_stack; // Create a stack to hold command objects.
	Stack <char> para_stack;	// Create a stack to keep track of Paranthesis position and type.

	while (!input.eof ()) 
	{ 
		input >> token;

		bool has_only_digits = (token.find_first_not_of("-0123456789") == std::string::npos);

		if (has_only_digits && token != "-") 
		{
			cmd = factory.create_number_command(atoi(token.c_str())); 	
		}
		else if (token == "+") 
		{
			cmd = factory.create_add_command (); 
		}
		else if (token == "-") 
		{
			cmd = factory.create_subtract_command (); 
		}
		else if (token == "/") 
		{
			cmd = factory.create_divide_command (); 
		} 
		else if (token == "*") 
		{
			cmd = factory.create_multiply_command (); 
		} 
		else if (token == "%") 
		{
			cmd = factory.create_mod_command (); 
		} 
		else if (token == "(") 
		{
			para_stack.push('(');
			continue;
		} 
		else if (token == ")") 
		{
			// pop and add to postfix string until a '(' is found.
			try
			{	// If there is an extra ) that doesnt match.
				while (para_stack.top() != '(')
				{
					postfix.set(postfix_ptr,cmd_stack.top());
					++postfix_ptr;
					cmd_stack.pop();
					para_stack.pop();
				}
				// Pop the parameter stack to maintain consistency with opeator stack.
				if (para_stack.top() == '(') {para_stack.pop();}
				continue;
			}catch(...)
			{
				// Cleanup - Emptying the Postfix Array.
				Iterator<Expr_Command*> cleaner (postfix, postfix_ptr);
				for (; !cleaner.is_done() ; cleaner.advance())
				{
					delete *cleaner;
					--postfix_ptr;
				}

				// Clean up - Emptying the stack.
				Expr_Command * cleaner_;
				while (cmd_stack.size() != 0)
				{
					cleaner_ = cmd_stack.top();
					delete cleaner_;
					cmd_stack.pop();
				}
				throw std::invalid_argument("INPUT ERROR, TRY AGAIN");
			}
							
		}
		// For all cases when parsed token is not a valid input
		// return false, halt operation.
		else 
		{
			// Cleanup - Emptying the Postfix Array.
			Iterator<Expr_Command*> cleaner (postfix, postfix_ptr);
			for (; !cleaner.is_done() ; cleaner.advance())
			{
				delete *cleaner;
				--postfix_ptr;
			}

			// Clean up - Emptying the stack.
			Expr_Command * cleaner_;
			while (cmd_stack.size() != 0)
			{
				cleaner_ = cmd_stack.top();
				delete cleaner_;
				cmd_stack.pop();
			}

			throw std::invalid_argument("INPUT ERROR, TRY AGAIN");
			//std::cout << "INVALID INPUT, TRY AGAIN." << std::endl;
			return false;
		}

		// This is where the cmd will be added to output string accordingly.
		do_convert (cmd, cmd_stack, para_stack, postfix, postfix_ptr);
	 }


	// At this point, all the tokens in the input string have been parsed.
	// Stack might contain remaining operators that need further computation.
	// Append all remaining operators in stack to postfix string.
	while (cmd_stack.size() != 0)
	{
		postfix.set(postfix_ptr, cmd_stack.top());
		++postfix_ptr;
		cmd_stack.pop();
	}

	//// Print Postfix string for debug purposes.
	/*std::cout << "FINAL ";
	printarray(postfix, postfix_ptr);*/

	int result=0;

	// Check if postfix string can be evaluated without any problems.
	try{
		if (evaluate_postfix(postfix, postfix_ptr, result))
		{
			std::cout << "Result : " << result << std::endl;
		}
		else
		{
			std::cout << "Oops! This was not expected. (Evaluation Failed)" << std::endl;
		}
	} catch (std::exception &e)
	{
	throw;
	}


	// Cleanup the command pointers.
	// Freeing up the memory - Everything that has been created is in the postfix string.
	// Iterate over it and free each instance.

	Iterator<Expr_Command*> iter_(postfix, postfix_ptr);
	while (!iter_.is_done())
	{
		if (0 != *iter_)
		{
			delete *iter_;
		} 
	iter_.advance();
	}
	return true;
};


