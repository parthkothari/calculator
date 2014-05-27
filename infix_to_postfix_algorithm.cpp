#include "infix_to_postfix_algorithm.h"
#include <iostream>
#include <string>

bool check_precedence(Expr_Command * lhs, Expr_Command * rhs);
int get_priority(Expr_Command * cmd);

//
// do_convert
//

bool do_convert (Expr_Command * cmd,
				Stack<Expr_Command*> & cmd_stack,
				Stack<char> & para_stack,
				Array<Expr_Command*> & postfix,
				int & postfix_ptr) {
	
	// Store command type in a string to avoid repeated function calls.
	std::string cmd_type_= cmd->get_type();

	// If cmd is a number or operand.
	bool has_only_digits = (cmd_type_.find_first_not_of("-0123456789") == std::string::npos);
	if (has_only_digits && cmd_type_ != "-")
	{
		postfix.set(postfix_ptr,cmd);
		++postfix_ptr;
	}
	// If cmd is an operator.
	else 
	{
		// Check for paranthesis.
		// This is never going to happen because create para open command is commented
		
		
			if (cmd_stack.size() == 0)
			{
				cmd_stack.push(cmd);
				para_stack.push('*');	// Make para_stack and cmd_stack consistent.
			}
			else
			{
				// if top of the stack is '(' push cmd directly as '(' lowest priority in stack.
				if (para_stack.top() == '(')
					{
						cmd_stack.push(cmd);
						para_stack.push('*');
						return true;
					}
			
				// If cmd has higher priority than current stack top.
				bool cmd_higherthan_topstack = check_precedence(cmd, cmd_stack.top());
				if (cmd_higherthan_topstack || para_stack.top() == '(')	
				{
					cmd_stack.push(cmd);
					para_stack.push('*');
				}
				// If cmd has lower priority than current stack top.
				else 
				{
					
					do // Pop operator stack into postfix until stacktop has a priority lower than cmd.
					{
						postfix.set(postfix_ptr, cmd_stack.top());
						++postfix_ptr;
						cmd_stack.pop();
						para_stack.pop();
					}
					while((cmd_stack.size()!=0) && !(check_precedence(cmd, cmd_stack.top())) && para_stack.top() != '(');
					
					cmd_stack.push(cmd);	// Stack contains an operator with lower priority, push cmd onto stack.
					para_stack.push('*');
				}
			}
	}
	
	return true;
	
}


// Definition of priority function
// returns true if lhs has strictly greater priority than rhs
// smaller number denotes higher priority
bool check_precedence (Expr_Command * lhs, Expr_Command * rhs)
{
	int lhs_priority=get_priority(lhs);
	int rhs_priority=get_priority(rhs);

	if (lhs_priority >= 0 && rhs_priority >=0)
	{
		return (!(lhs_priority < rhs_priority)) ? false : true;
	}

	return false;
}

int get_priority (Expr_Command * cmd)
{
	std::string command_type_ = cmd->get_type();
	if (command_type_ == "+")
	{
		return 2;
	}
	else if (command_type_ == "-")
	{
		return 2;
	}
	else if (command_type_ == "*")
	{
		return 1;
	}
	else if (command_type_ == "/")
	{
		return 1;
	}
	else if (command_type_ == "%")
	{
		return 1;
	}
	
	else 
	{
		return -1;
	}
}
