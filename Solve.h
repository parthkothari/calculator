#ifndef _SOLVE_H_
#define _SOLVE_H_

#include "Stack.h"
#include "Expr_Command_Factory.h"
#include "Stack_Expr_Command_Factory.h"
#include "Do_Eval.h"
#include "Expr_Command.h"
#include <string>
#include <iostream>


/*-----------------------------------------------------------------------
//	Takes user input and calls the do_eval method
/------------------------------------------------------------------------*/

bool solve(std::string & user_input);


#endif //!_SOLVE_H