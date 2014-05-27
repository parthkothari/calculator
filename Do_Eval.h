#ifndef _DO_EVAL_H_
#define	_DO_EVAL_H_

#include <string>
#include <iostream>
#include <sstream>
#include "Expr_Command_Factory.h"
#include "Expr_Command.h"
#include "infix_to_postfix_algorithm.h"
#include "Evaluate_PostFix.h"
#include "Iterator.h"

/*-----------------------------------------------------------------------
//	Calls the do_eval method with user input, factory and postfix string
/------------------------------------------------------------------------*/

bool do_eval (	const std::string & infix,
				Expr_Command_Factory & factory, 
				Array <Expr_Command*> & postfix);

#endif //!_DO_EVAL_H_