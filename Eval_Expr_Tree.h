//Eval_Expr_Tree.h

#ifndef _EVAL_EXPR_TREE_H_
#define _EVAL_EXPR_TREE_H_

#include "Expr_Node_Visitor.h"
#include "Stack.h"
#include <iostream>

class Eval_Expr_Tree: public Expr_Node_Visitor{
	public:
		Eval_Expr_Tree (void);
		virtual ~Eval_Expr_Tree(void);
		//methods for visiting concrete nodes
		virtual void Visit_Number_Node (const Num_Expr_Node & node);
		virtual void Visit_Unary_Node (const Unary_Expr_Node & node);
		virtual void Visit_Add_Node (const Add_Expr_Node & node);
		virtual void Visit_Subtract_Node (const Subtract_Expr_Node & node);
		virtual void Visit_Multiply_Node (const Multiply_Expr_Node & node);
		virtual void Visit_Divide_Node (const Divide_Expr_Node & node);
		virtual void Visit_Modulus_Node (const Modulus_Expr_Node & node);
		int result(void) const;
		bool result_valid(void);
	private:
		Stack <int> visitorTree_;
		bool valid;
};

#endif
