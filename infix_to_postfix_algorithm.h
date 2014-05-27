#ifndef _INFIX_TO_POSTFIX_ALGORITHM_H_
#define _INFIX_TO_POSTFIX_ALGORITHM_H_

/*-----------------------------------------------------------------------
//	Takes command object and puts it in operator stack or postfix string
/------------------------------------------------------------------------*/

#include "Expr_Command.h"
#include "Stack.h"
#include "Array.h"


bool do_convert (Expr_Command * cmd,
				Stack<Expr_Command*> & cmd_stack,
				Stack<char> & para_stack,
				Array<Expr_Command*> & postfix,
				int & postfix_ptr);


#endif //!_INFIX_TO_POSTFIX_ALGORITHM_H_