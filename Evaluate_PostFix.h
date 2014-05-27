#ifndef _EVALUATE_POSTFIX_H_
#define _EVALUATE_POSTFIX_H_

#include "Array.h"
#include "Iterator.h"
#include "Expr_Command.h"

/*-----------------------------------------------------------------------
//	Takes postfix string and performs postfix evaluation
/------------------------------------------------------------------------*/
bool evaluate_postfix (Array<Expr_Command*> & postfix, int & postfixptr, int & result);

#endif //!_EVALUATE_POSTFIX_H_