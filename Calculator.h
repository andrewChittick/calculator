//Calculator.h

#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <string>
#include <sstream>
#include "Expr_Node.h"
#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Multiply_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Modulus_Expr_Node.h"
#include "Num_Expr_Node.h"
#include "Expr_Builder.h"
#include "Expr_Tree_Builder.h"
#include "Stack.h"
#include "Queue.h"



class Calculator{
	public:
		Calculator(void);
		bool evaluate (const std::string & infix);
		Expr_Node * get_expression (void);
		int get_answer(void);
		bool parse_expr (const std::string & infix);
		bool infix2postfix (const std::string & infix);
		bool isOperator (const std::string & token);
		bool isNumber (const std::string & token);
		int getPrec (const std::string & token);
	private:
		Expr_Tree_Builder builder_;
		Queue <std::string> postfix_;
};

#endif
